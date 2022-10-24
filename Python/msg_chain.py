from mpi4py import MPI
import numpy
from sys import stdout

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

# send and receive buffers
n = 100000
data = numpy.full(n, rank, int)
buff = numpy.zeros(n, int)

if rank == 0:
    print('Send and Recv:')

# destination and source for messages
tgt = rank + 1
src = rank - 1

# message chain using Send and Recv
if rank == 0:
    comm.Send(data, dest=tgt)
    print(f'  rank {rank}: sent {len(data)} elements to rank {tgt}')
else:
    comm.Recv(buff, source=src)
    print(f'  rank {rank}: received an array filled with {buff[0]}s')
    if rank < size - 1:
        comm.Send(data, dest=tgt)
        print(f'  rank {rank}: sent {len(data)} elements')


# wait for every rank to finish
stdout.flush()
comm.barrier()


if rank == 0:
    print('')
    print('Sendrecv (in the middle of the chain):')

# message chain using Sendrecv when sending AND receiving
tgt = rank + 1
src = rank - 1

# start of chain ==> only send
if rank == 0:
    comm.Send(data, dest=tgt)
    print(f'  rank {rank}: sent {len(data)} elements to rank {tgt}')
# end of chain ==> only receive
elif rank == size - 1:
    comm.Recv(buff, source=src)
    print(f'  rank {rank}: received a message from rank {src}')
    print(f'  rank {rank}: received an array filled with {buff[0]}')
# middle of chain ==> send and receive
else:
    comm.Sendrecv(data, dest=tgt, recvbuf=buff, source=src)
    print(f'  rank {rank}: sent {len(data)} elements to rank {tgt}')
    print(f'  rank {rank}: received a message from rank {src}')
    print(f'  rank {rank}: received an array filled with {buff[0]}')

# wait for every rank to finish
stdout.flush()
comm.barrier()


if rank == 0:
    print('')
    print('Sendrecv (everywhere using PROC_NULL):')

# alternative version using PROC_NULL (no communication)
tgt = rank + 1
src = rank - 1
if tgt >= size:
    tgt = MPI.PROC_NULL
if src < 0:
    src = MPI.PROC_NULL


# use the same MPI call to do all communication
comm.Sendrecv(data, dest=tgt, recvbuf=buff, source=src)
print(f'  rank {rank}: sent {len(data)} elements to rank {tgt}')
print(f'  rank {rank}: received a message from rank {src}')
print(f'  rank {rank}: received an array filled with {buff[0]}')
