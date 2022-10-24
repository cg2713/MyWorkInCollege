# -*- coding: utf-8 -*-
"""
dsatur (degree of saturation) is a heuristic,
easy-to-follow algorithm for coloring simple graphs

greedy algorithms are inherently sequential
challenge: come up with a way to create concurrency in a nontrivial way

- break up the problem into p, not necessarily entirely independent,
  subproblems of almost equal sizes
- solve the p subproblems concurrently
- detect inconsistencies in the solutions concurrently
- resolve any inconsistencies locally

hints:
- use random number to break ties
- if first round send deg, r, first legal color else send sat, r, first legal color
- coloring is done by cores
"""

import matplotlib.pyplot as plt
import numpy as np

# MPI init


def read_clq(filename, encoding='utf-8', directed=True):
    """
    clq format is the edge representation of a graph, stating the number of nodes
    and edges in the header, and enumerating the edges as pair of nodes
    (see http://dimacs.rutgers.edu/Challenges)
    1. coments (optional)
        lines that start with a letter 'c' at the begining of the file. e.g.
        c A graph representing a Boolean circuit
    2. problem line of the form
        p edge N E
        where N is the number of vertices and E is the number of edges in the graph
        NOTE: vertices are numbered from 1 to N
    3. vertex colors
        n v c
        where v is the vertex number and c its color
        c should be a nonnegative integer and can be missing
        NOTE:  if the color of a vertex is defined more than once,
               the last definition applies
    4. edges
        e v1 v2
        where 1≤ v1, v2 ≤ N are the numbers of the vertices connected by the edge
        NOTE: multiple definitions of the same edge are ignored
              there is no distinction between undirected and directed graphs

    see https://cedric.cnam.fr/~porumbed/graphs/
    """

    # csection = True
    vertices = 0
    edges = 0
    assigned = np.zeros(1, dtype=type(1))
    X = np.zeros(1, dtype=type(1))
    with open(filename, mode='r', encoding=encoding) as f:
        for line in f:
            line = line.strip()
            # if csection and line.startswith('c'):
            #    continue
            if line and not line.startswith('c'):
                # csection = False
                tokens = line.split(' ')
                if tokens[0] == 'e' and len(tokens) == 3:
                    try:
                        v1 = int(tokens[1])
                        v2 = int(tokens[2])
                    except ValueError as err:
                        print(f'parsed error {line}')
                    else:
                        X[v1 - 1, v2 - 1] = 1
                        if not directed:
                            X[v2 - 1, v1 - 1] = 1
                elif tokens[0] == 'p' and len(tokens) == 4:
                    try:
                        vertices = int(tokens[2])
                        edges = int(tokens[3])
                    except ValueError as err:
                        print(f'parsed error {line}')
                    else:
                        X = np.zeros((vertices, vertices), dtype=type(1))
                        assigned = np.zeros(vertices, dtype=type(1))
                elif tokens[0] == 'n' and len(tokens) == 3:
                    try:
                        v = int(tokens[1])
                        c = int(tokens[2])
                    except ValueError as err:
                        print(f'parsed error {line}')
                    else:
                        if c > 0:
                            assigned[v - 1] = c
    return X, edges, assigned


def plot_pbm(X):
    """
    plot adjacency matrix (with nodes reordered by color classes) as an image
    boxes without 1s around the main diagonal mean independent sets as no edge
    will run inside that set count the boxes and check the number of colors
    the coloring used
    """

    plt.imshow(X, cmap='terrain', interpolation='nearest')
    plt.axis('off')
    plt.show()


def color_permutation(coloring, asize=1):
    """
    generate a permutation of vertices based on color classes
    (vertices are clustered by color)
    """

    perm = []
    freq = np.zeros(1)
    if isinstance(coloring, dict):
        arr = np.zeros(asize, dtype=type(1))
        for k, v in coloring.items():
            arr[k] = v
    else:
        arr = coloring
    freq = np.bincount(arr)
    while freq.max():
        for i in np.where(arr == freq.argmax())[0]:
            perm.append(i)
        freq[freq.argmax()] = 0
    return perm


def matrix_permutation(adj, perm):
    """
    permute adjacency matrix based on the color permutation
    """

    p = np.zeros(adj.shape, dtype=type(1))
    for i in range(adj.shape[0]):
        for j in range(adj.shape[1]):
            p[i, j] = adj[perm[i], perm[j]]
    return p


def neighbors_of_color(coloring, neighbors, colorid):
    """
    number of neighbors with the same color
    """

    counter = 0
    for i in neighbors:
        if ((isinstance(coloring, dict) and coloring.get(i)) or isinstance(
                coloring, np.ndarray)) and coloring[i] == colorid:
            counter += 1
    print(
        f'core [{rank}]: coloring [{coloring}] neighbors[{neighbors}] colorid[{colorid}] cnt[{counter}]\n'
    )
    return counter


def select_vertex(globalset, localset, collection, commxchange=True):
    """
    select next vertex to color
    """

    selected = None
    cmap = dict()
    print(f'core [{rank}]: dset [{globalset.difference(localset)}] \n')
    for i in globalset.difference(localset):
        if (isinstance(collection, dict) and collection.get(i)) or isinstance(
                collection, np.ndarray):
            cmap.update({i: collection[i]})
    print(f'core [{rank}]: sety [{cmap}] \n')
    if commxchange:
        # recv = 
        cmap.clear()
        for i in recv:
            cmap.update(i)
    print(f'core [{rank}]: cmap [{cmap}] \n')
    if cmap.values():
        maxval = max(cmap.values())
        selected = min([k for k, v in cmap.items() if v == maxval])
    return selected


def color_graph_mpi(X, startval, endval):
    """
    read graph and create adjacency matrix and obtain
    colored and vertex info
    """

    num_color = 1
    # nv = endval - startval
    sat = dict()
    finalcoloring = dict()
    coloring = dict()
    uncolored = set(range(startval, endval))
    degrees = X.sum(axis=1)
    cset = set()
    globalcset = set()
    # phase 1:
    # construct global conflict set by exchanging local conflict sets with degree information
    for i in range(startval, endval):
        cset.update([
            j for j in X[i].nonzero()[0] if (j < startval or j > (endval - 1))
        ])
    print(f'core [{rank}]: cset [{cset}] \n')
    # recv = 
    for i in recv:
        globalcset.update(i)
    print(f'core [{rank}]: gset [{globalcset}] \n')
    # select and color max degree vertex
    neighbors = np.zeros(0, dtype=type(1))
    selected = select_vertex(globalcset, cset, degrees)
    if selected in globalcset:
        globalcset.remove(selected)
    if selected in uncolored:
        neighbors = X[selected].nonzero()[0]
        coloring[selected] = num_color
        uncolored.remove(selected)
        print(
            f'core [{rank}]: selected [{selected}] colored [{coloring[selected]}]\n'
        )
    # recv = 

    print(f'core [{rank}]: recv_ [{recv}]\n')
    for i in recv:
        if i[0] > num_color:
            num_color = i[0]
        if len(i[1]):
            neighbors = np.unique(np.concatenate((neighbors, i[1]), axis=None))
        print(f'core [{rank}]: recv_NN [{neighbors}]\n')
        if i[2]:
            coloring[selected] = i[2]
    # update saturation
    for i in neighbors:
        if sat.get(i):
            sat[i] += 1
        else:
            sat[i] = 1
    print(
        f'core [{rank}]: gset [{globalcset}] nc[{}] nn[{num_color}] sat[{sat}]\n'
    )
    # wait until all task are done
    # select and color one vertex until global conflict set is empty
    while len(globalcset):
        neighbors = np.zeros(0, dtype=type(1))
        selected = select_vertex(globalcset, cset, degrees)
        if selected in globalcset:
            globalcset.remove(selected)
        if selected in uncolored:
            neighbors = X[selected].nonzero()[0]
            for i in range(1, num_color + 1):
                if not neighbors_of_color(coloring, neighbors, i):
                    coloring[selected] = i
                    break
            # if uncolored, color it (maybe with a new color)
            if (isinstance(coloring, dict)
                    and not coloring.get(selected)) or (isinstance(
                        coloring, np.ndarray) and not coloring[selected]):
                num_color += 1
                coloring[selected] = num_color
            uncolored.remove(selected)
            print(
                f'core [{rank}]: selected [{selected}] colored [{coloring[selected]}]\n'
            )
        # recv = 
        print(f'core [{rank}]: recv_ [{recv}]\n')
        for i in recv:
            if i[0] > num_color:
                num_color = i[0]
            if len(i[1]):
                neighbors = np.unique(
                    np.concatenate((neighbors, i[1]), axis=None))
            print(f'core [{rank}]: recv_NN [{neighbors}]\n')
            if i[2]:
                coloring[selected] = i[2]
        # update saturation
        for i in neighbors:
            subneighbors = X[i].nonzero()[0]
            print(f'core [{rank}]: [{i}] subnn_ [{subneighbors}]\n')
            if neighbors_of_color(coloring, subneighbors,
                                  coloring.get(selected)) == 1:
                if sat.get(i):
                    sat[i] += 1
                else:
                    sat[i] = 1
        print(
            f'core [{rank}]: gset [{globalcset}] nc[{num_color}] nn[{neighbors}] sat[{sat}]\n'
        )
        # wait until all task are done
    # color local vertices independently
    print(f'core [{rank}]: uncolored [{uncolored}] \n')
    while len(uncolored):
        neighbors = np.zeros(0, dtype=type(1))
        selected = select_vertex(uncolored,
                                 globalcset,
                                 degrees,
                                 commxchange=False)
        if selected in uncolored:
            neighbors = X[selected].nonzero()[0]
            for i in range(1, num_color + 1):
                if not neighbors_of_color(coloring, neighbors, i):
                    coloring[selected] = i
                    break
            # if uncolored, color it (maybe with a new color)
            if (isinstance(coloring, dict)
                    and not coloring.get(selected)) or (isinstance(
                        coloring, np.ndarray) and not coloring[selected]):
                num_color += 1
                coloring[selected] = num_color
            uncolored.remove(selected)
            print(
                f'core [{rank}]: selected [{selected}] colored [{coloring[selected]}]\n'
            )
            # update saturation
            for i in neighbors:
                subneighbors = X[i].nonzero()[0]
                print(f'core [{rank}]: [{i}] subnn_ [{subneighbors}]\n')
                if neighbors_of_color(coloring, subneighbors,
                                      coloring.get(selected)) == 1:
                    if sat.get(i):
                        sat[i] += 1
                    else:
                        sat[i] = 1
            print(
                f'core [{rank}]: gset [{globalcset}] nc[{num_color}] nn[{neighbors}] sat[{sat}]\n'
            )
    print(f'coloring  [{num_color}]: {coloring}\n')
    # recv = 
    for i in recv:
        if i[0] > num_color:
            num_color = i[0]
        if len(i[1]):
            finalcoloring.update(i[1])
    return num_color, finalcoloring


def setup():
    """
    read graph, create adjacency matrix and split it
    """

    X = np.zeros(1)
    if rank == 0:
        filename = input(
            'enter the path of the graph in clq (DIMACS) format: ')
        X, ne, assigned = read_clq(filename, directed=False)
        print(f'cores: {size}\n')
        print(f'G(V[{X.shape[0]}], E[{ne}])\n\n {X}\n\n')
    # broadcast number of vertices
    #ndim = 
    # distribute data to other cores
    #startval = 
    #endval =
    print(f'core [{rank}]: recv [{ndim[0]}] \t [{startval}, {endval}]\n')
    if rank:
        X = np.empty(ndim, dtype=type(1))
    # broadcast matrix instead of block scheduling (cheating part)
    print(f'core [{rank}]: recv [{X.shape}] \n')
    return X, startval, endval


def do_permute_plot(colors, coloring, asize):
    """
    plot the colored permutation
    """

    if rank == 0:
        perm = color_permutation(coloring, asize)
        print(f'coloring [{colors}]: {coloring}\n')
        print(f'permutation: {perm}\n')
        pm = matrix_permutation(X, perm)
        plot_pbm(X)
        plot_pbm(pm)


if __name__ == '__main__':
    X, startval, endval = setup()
    colors, coloring = color_graph_mpi(X, startval, endval)
    do_permute_plot(colors, coloring, X.shape[0])
