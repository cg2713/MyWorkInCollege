#
import matplotlib.pyplot as plt
import argparse
import matplotlib
import numpy as np
import time

matplotlib.use('Agg')

# colormap
plt.rcParams['image.cmap'] = 'BrBG'


def evolve(u, u_previous, a, dt, dx2, dy2):
    """Explicit time evolution.
       u:            new temperature field
       u_previous:   previous field
       a:            diffusion constant
       dt:           time step """
    n, m = u.shape
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            u[i, j] = u_previous[i, j] + a * dt * (
                (u_previous[i + 1, j] - 2 * u_previous[i, j] +
                 u_previous[i - 1, j]) / dx2 +
                (u_previous[i, j + 1] - 2 * u_previous[i, j] +
                 u_previous[i, j - 1]) / dy2)
    u_previous[:] = u[:]


def iterate(field, field0, a, dx, dy, timesteps, image_interval):
    """Run fixed number of time steps of heat equation"""
    dx2 = dx**2
    dy2 = dy**2
    dt = dx2 * dy2 / (2 * a * (dx2 + dy2))
    for m in range(1, timesteps + 1):
        evolve(field, field0, a, dt, dx2, dy2)
        if m % image_interval == 0:
            write_field(field, m)


def init_fields(filename):
    """ Read the initial temperature field from file """
    field = np.loadtxt(filename)
    field0 = field.copy()
    return field, field0


def write_field(field, step):
    plt.gca().clear()
    plt.imshow(field)
    plt.axis('off')
    plt.savefig('heat_{0:03d}.png'.format(step))


def main(input_file='bottle.dat',
         a=0.5,
         dx=0.1,
         dy=0.1,
         timesteps=200,
         image_interval=4000):
    # initialise the temperature field
    field, field0 = init_fields(input_file)

    print('heat equation solver')
    print(f'diffusion constant: {a}')
    print(f'input file: {input_file}')
    print('parameters')
    print('----------')
    print(f'  nx={field.shape[0]} ny={field.shape[1]} dx={dx} dy={dy}')
    print(f'  time steps={timesteps}  image interval={image_interval}')

    # plot and save initial field
    write_field(field, 0)
    # iterate
    t0 = time.time()
    iterate(field, field0, a, dx, dy, timesteps, image_interval)
    t1 = time.time()
    # plot and save final field
    write_field(field, timesteps)

    print(f'simulation finished in {t1 - t0} s')


if __name__ == '__main__':
    # process command line arguments
    parser = argparse.ArgumentParser(description='heat equation')
    parser.add_argument('-dx',
                        type=float,
                        default=0.01,
                        help='grid spacing in x-direction')
    parser.add_argument('-dy',
                        type=float,
                        default=0.01,
                        help='grid spacing in y-direction')
    parser.add_argument('-a',
                        type=float,
                        default=0.5,
                        help='diffusion constant')
    parser.add_argument('-n',
                        type=int,
                        default=200,
                        help='number of time steps')
    parser.add_argument('-i', type=int, default=4000, help='image interval')
    parser.add_argument('-f',
                        type=str,
                        default='bottle.dat',
                        help='input file')
    args = parser.parse_args()
    main(args.f, args.a, args.dx, args.dy, args.n, args.i)
