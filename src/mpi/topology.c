#include "mpi.h"
#include <stdio.h>
#include "structs.h"



void hybrid_dims_create(int nnodes, int ndims, int *dims) {
    return MPI_Dims_create(nnodes, ndims, dims);
    
}

void hybrid_cartesian_create(hybrid_interface_t *hybrid_root_interface, int ndims, int *dims, int *periods, int reorder,  hybrid_comm_t *newcomm) {
    return MPI_Cart_create(hybrid_root_interface->mpi_struct.comm, ndims, dims, periods, reorder, newcomm);
    
}

void hybrid_cartesian_coords(hybrid_interface_t *hybrid_root_interface, int rank, int maxdims, int *coords) {
    return MPI_Cart_coords(hybrid_root_interface->mpi_struct.comm, rank, maxdims, coords);
    
}=

void hybrid_cartesian_shift(hybrid_interface_t *hybrid_root_interface, int direction, int disp, int *source, int *dest) {
    return MPI_Cart_shift(hybrid_root_interface->mpi_struct.comm, direction, disp, source, dest);
    
}

void hybrid_cartesian_sub(hybrid_interface_t *hybrid_root_interface, int remain_dims, hybrid_comm_t *newcomm) {
    return MPI_Cart_shift(hybrid_root_interface->mpi_struct.comm, direction, disp, source, dest);
    
}

void hybrid_graph_create_adjacent(hybrid_interface_t *hybrid_root_interface, int nnodes, int nedges, int *index, int *edges, int reorder,  hybrid_comm_t *newcomm) {
    return MPI_Graph_create(hybrid_root_interface->mpi_struct.comm, nnodes, nedges, index, edges, reorder, newcomm);

}

void hybrid_graph_create(hybrid_interface_t *hybrid_root_interface, int nnodes, int nedges, int *index, int *edges, hybrid_comm_t *newcomm) {
    return MPI_Graph_create(hybrid_root_interface->mpi_struct.comm, nnodes, nedges, index, edges, 0, newcomm);

}

void hybrid_graph_neighbors_count(hybrid_interface_t *hybrid_root_interface, int rank, int *nneighbors) {
    return MPI_Graph_neighbors_count(hybrid_root_interface->mpi_struct.comm, rank, nneighbors);
    
}

void hybrid_graph_neighbors(hybrid_interface_t *hybrid_root_interface, int rank, int maxneighbors, int *neighbors) {
    return MPI_Graph_neighbors(hybrid_root_interface->mpi_struct.comm, rank, maxneighbors, neighbors);
    
}