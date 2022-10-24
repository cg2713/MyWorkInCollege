# -*- coding: utf-8 -*-
"""
dsatur (degree of saturation) is a heuristic,
easy-to-follow algorithm for coloring simple graphs
"""

import matplotlib.pyplot as plt
import numpy as np


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


def color_permutation(coloring):
    """
    generate a permutation of vertices based on color classes
    (vertices are clustered by color)
    """

    perm = []
    freq = np.bincount(coloring)
    while freq.max():
        for i in np.where(coloring == freq.argmax())[0]:
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
        if coloring[i] == colorid:
            counter += 1
    return counter


def color_graph(filename, directed=False):
    """
    read graph and create adjacency matrix and obtain
    colored and vertex info
    """

    X, ne, assigned = read_clq(filename, directed=directed)
    nv = X.shape[0]
    num_color = 1
    sat = np.zeros(nv, dtype=type(1))
    coloring = np.zeros(nv, dtype=type(1))
    uncolored = set(range(nv))
    degrees = X.sum(axis=1)
    maxidx = np.argmax(degrees)
    maxdeg = degrees.max()
    # color max degree vertex and colored first
    neighbors = X[maxidx].nonzero()[0]
    for i in neighbors:
        sat[i] += 1
    coloring[maxidx] = num_color
    uncolored.remove(maxidx)
    while len(uncolored):
        # get max degree uncolored vertex
        maxval = -1
        maxdeg = -1
        for i in uncolored:
            if sat[i] > maxval:
                maxval = sat[i]
        for i in (i for i in uncolored if sat[i] == maxval):
            if degrees[i] > maxdeg:
                maxdeg = degrees[i]
                maxidx = i
        # color max degree vertex
        neighbors = X[maxidx].nonzero()[0]
        for i in range(1, num_color + 1):
            if not neighbors_of_color(coloring, neighbors, i):
                coloring[maxidx] = i
                break
        # if uncolored, color it (maybe with a new color)
        if not coloring[maxidx]:
            num_color += 1
            coloring[maxidx] = num_color
        uncolored.remove(maxidx)
        # update saturation
        for i in neighbors:
            subneighbors = X[i].nonzero()[0]
            if neighbors_of_color(coloring, subneighbors,
                                  coloring[maxidx]) == 1:
                sat[i] += 1
    perm = color_permutation(coloring)
    print(f'coloring [{num_color}]: {coloring}\n')
    print(f'permutation: {perm}\n')
    pm = matrix_permutation(X, perm)
    plot_pbm(X)
    plot_pbm(pm)
    return coloring


if __name__ == '__main__':
    filename = input('enter the path of the graph in clq (DIMACS) format: ')
    color_graph(filename)
