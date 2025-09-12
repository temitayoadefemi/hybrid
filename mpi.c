#include "mpi.h"
#include <stdio.h>
#include "structs.h"



void hybrid_send(void *data, int count, MPI_Datatype datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Send(data, count, datatype, dest, tag, comm);
}

void hybrid_recv(void *data, int count, MPI_Datatype datatype, int source, int tag, hybrid_interface_t *hybrid_root_interface, MPI_Status *status) {
    return MPI_Recv(data, count, datatype, source, tag, comm, status);

}

void hybrid_bcast(void *data, int count, MPI_Datatype datatype, int root, hybrid_interface_t *hybrid_root_interface, ) {
    return MPI_Bcast(data, count, datatype, root, hybrid_root_interface->mpi_struct.comm);

}

int hybrid_barrier(hybrid_interface_t *hybrid_root_interface) {
    return MPI_Barrier(hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_sendrecv(void *send_data, int send_count, MPI_Datatype send_datatype, int dest, int send_tag, void *recv_data, int recv_count, MPI_Datatype recv_datatype, int source, int recv_tag, hybrid_interface_t *hybrid_root_interface, MPI_Status *status) {
   return MPI_Sendrecv(send_data, send_count, send_datatype, dest, send_tag, recv_data, recv_count, recv_datatype, source, recv_tag, hybrid_root_interface->mpi_struct.comm, status);
    
}

void hybrid_irecv(void *data, int count, MPI_Datatype datatype, int source, int tag, hybrid_interface_t *hybrid_root_interface, MPI_Request *request) {
    return MPI_Irecv(data, count, datatype, source, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

void hybrid_isend(void *data, int count, MPI_Datatype datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, MPI_Request *request) {
    return MPI_Isend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

void hybrid_dims_create(int nnodes, int ndims, int *dims) {
    return MPI_Dims_create(nnodes, ndims, dims);
    
}

void hybrid_cartesian_create(hybrid_interface_t *hybrid_root_interface, int ndims, int *dims, int *periods, int reorder, MPI_Comm *newcomm) {
    return MPI_Cart_create(hybrid_root_interface->mpi_struct.comm, ndims, dims, periods, reorder, newcomm);
    
}

void hybrid_cartesian_coords(hybrid_interface_t *hybrid_root_interface, int rank, int maxdims, int *coords) {
    return MPI_Cart_coords(hybrid_root_interface->mpi_struct.comm, rank, maxdims, coords);
    
}

void hybrid_cartesian_shift(hybrid_interface_t *hybrid_root_interface, int direction, int disp, int *source, int *dest) {
    return MPI_Cart_shift(hybrid_root_interface->mpi_struct.comm, direction, disp, source, dest);
    
}

void hybrid_graph_create_adjacent(hybrid_interface_t *hybrid_root_interface, int nnodes, int nedges, int *index, int *edges, int reorder, MPI_Comm *newcomm) {
    return MPI_Graph_create(hybrid_root_interface->mpi_struct.comm, nnodes, nedges, index, edges, reorder, newcomm);

}
void hybrid_graph_create(hybrid_interface_t *hybrid_root_interface, int nnodes, int nedges, int *index, int *edges, int *newcomm) {
    return MPI_Graph_create(hybrid_root_interface->mpi_struct.comm, nnodes, nedges, index, edges, 0, newcomm);

}

void hybrid_graph_neighbors_count(hybrid_interface_t *hybrid_root_interface, int rank, int *nneighbors) {
    return MPI_Graph_neighbors_count(hybrid_root_interface->mpi_struct.comm, rank, nneighbors);
    
}

void hybrid_graph_neighbors(hybrid_interface_t *hybrid_root_interface, int rank, int maxneighbors, int *neighbors) {
    return MPI_Graph_neighbors(hybrid_root_interface->mpi_struct.comm, rank, maxneighbors, neighbors);
    
}