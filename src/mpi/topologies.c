#include "mpi.h"
#include <stdio.h>
#include "structs.h"



int hybrid_dims_create(int nnodes, int ndims, int *dims) {
    return MPI_Dims_create(nnodes, ndims, dims);
    
}

int hybrid_cartesian_create(hybrid_interface_t *hybrid_root_interface, int ndims, int *dims, int *periods, int reorder,  hybrid_comm_t *newcomm) {
    return MPI_Cart_create(hybrid_root_interface->mpi_struct.comm, ndims, dims, periods, reorder, newcomm);
    
}

int hybrid_cartesian_coords(hybrid_interface_t *hybrid_root_interface, int rank, int maxdims, int *coords) {
    return MPI_Cart_coords(hybrid_root_interface->mpi_struct.comm, rank, maxdims, coords);
    
}

int hybrid_cartesian_shift(hybrid_interface_t *hybrid_root_interface, int direction, int disp, int *source, int *dest) {
    return MPI_Cart_shift(hybrid_root_interface->mpi_struct.comm, direction, disp, source, dest);
    
}

int hybrid_cartesian_sub(hybrid_interface_t *hybrid_root_interface, int remain_dims, hybrid_comm_t *newcomm) {
    return MPI_Cart_shift(hybrid_root_interface->mpi_struct.comm, direction, disp, source, dest);
    
}

int hybrid_graph_create_adjacent(hybrid_interface_t *hybrid_root_interface, int nnodes, int nedges, int *index, int *edges, int reorder,  hybrid_comm_t *newcomm) {
    return MPI_Graph_create(hybrid_root_interface->mpi_struct.comm, nnodes, nedges, index, edges, reorder, newcomm);

}

int hybrid_graph_create(hybrid_interface_t *hybrid_root_interface, int nnodes, int nedges, int *index, int *edges, hybrid_comm_t *newcomm) {
    return MPI_Graph_create(hybrid_root_interface->mpi_struct.comm, nnodes, nedges, index, edges, 0, newcomm);

}

int hybrid_graph_neighbors_count(hybrid_interface_t *hybrid_root_interface, int rank, int *nneighbors) {
    return MPI_Graph_neighbors_count(hybrid_root_interface->mpi_struct.comm, rank, nneighbors);
    
}

int hybrid_graph_neighbors(hybrid_interface_t *hybrid_root_interface, int rank, int maxneighbors, int *neighbors) {
    return MPI_Graph_neighbors(hybrid_root_interface->mpi_struct.comm, rank, maxneighbors, neighbors);
    
}

int hybrid_topo_test(hybrid_interface_t *hybrid_root_interface, int *status) {
    return MPI_Topo_test(hybrid_root_interface->mpi_struct.comm, status);
    
}

int hybrid_graphdims_get(hybrid_interface_t *hybrid_root_interface, int *nnodes, int *nedges) {
    return MPI_Graphdims_get(hybrid_root_interface->mpi_struct.comm, nnodes, nedges);
    
}
int hybrid_graph_get(hybrid_interface_t *hybrid_root_interface, int maxindex, int maxedges, int *index, int *edges) {
    return MPI_Graph_get(hybrid_root_interface->mpi_struct.comm, maxindex, maxedges, index, edges);
    
}

int hybrid_cartdim_get(hybrid_interface_t *hybrid_root_interface, int *ndims) {
    return MPI_Cartdim_get(hybrid_root_interface->mpi_struct.comm, ndims);
    
}
int hybrid_cart_get(hybrid_interface_t *hybrid_root_interface, int maxdims, int *dims, int *periods, int *coords) {
    return MPI_Cart_get(hybrid_root_interface->mpi_struct.comm, maxdims, dims, periods, coords);
    
}

int hybrid_cart_rank(hybrid_interface_t *hybrid_root_interface, int *coords, int *rank) {
    return MPI_Cart_rank(hybrid_root_interface->mpi_struct.comm, coords, rank);
    
}

int hybrid_cart_map(hybrid_interface_t *hybrid_root_interface, int ndims, int *dims, int *periods, int *newrank) {
    return MPI_Cart_map(hybrid_root_interface->mpi_struct.comm, ndims, dims, periods, newrank);
    
}

int hybrid_graph_map(hybrid_interface_t *hybrid_root_interface, int nnodes, int nedges, int *index, int *edges, int *newrank) {
    return MPI_Graph_map(hybrid_root_interface->mpi_struct.comm, nnodes, nedges, index, edges, newrank);
    
}

int hybrid_neighbor_allgather(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Neighbor_allgather(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_neighbor_allgatherv(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Neighbor_allgatherv(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_neighbor_alltoall(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Neighbor_alltoall(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_neighbor_alltoallv(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Neighbor_alltoallv(send_data, send_counts, sdispls, send_datatype, recv_data, recv_counts, rdispls, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_neighbor_alltoallw(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatypes, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatypes, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Neighbor_alltoallw(send_data, send_counts, sdispls, send_datatypes, recv_data, recv_counts, rdispls, recv_datatypes, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_ineighbor_allgather(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_allgather(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_allgather_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_allgather(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_allgatherv(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_allgatherv(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_allgatherv_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_allgatherv(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_alltoall(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_alltoall(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_alltoall_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_alltoall(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_alltoallv(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_alltoallv(send_data, send_counts, sdispls, send_datatype, recv_data, recv_counts, rdispls, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_alltoallv_c(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_alltoallv(send_data, send_counts, sdispls, send_datatype, recv_data, recv_counts, rdispls, recv_datatype, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_alltoallw(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatypes, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatypes, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_alltoallw(send_data, send_counts, sdispls, send_datatypes, recv_data, recv_counts, rdispls, recv_datatypes, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ineighbor_alltoallw_c(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatypes, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatypes, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ineighbor_alltoallw(send_data, send_counts, sdispls, send_datatypes, recv_data, recv_counts, rdispls, recv_datatypes, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_neighbor_allgather_init(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_allgather_init(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_allgather_init_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_allgather_init(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_allgatherv_init(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_allgatherv_init(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_allgatherv_init_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_allgatherv_init(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_alltoall_init(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_alltoall_init(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_alltoall_init_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_alltoall_init(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_alltoallv_init(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_alltoallv_init(send_data, send_counts, sdispls, send_datatype, recv_data, recv_counts, rdispls, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_alltoallv_init_c(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_alltoallv_init(send_data, send_counts, sdispls, send_datatype, recv_data, recv_counts, rdispls, recv_datatype, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_alltoallw_init(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatypes, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatypes, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_alltoallw_init(send_data, send_counts, sdispls, send_datatypes, recv_data, recv_counts, rdispls, recv_datatypes, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}

int hybrid_neighbor_alltoallw_init_c(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatypes, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatypes, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Neighbor_alltoallw_init(send_data, send_counts, sdispls, send_datatypes, recv_data, recv_counts, rdispls, recv_datatypes, hybrid_root_interface->mpi_struct.comm, MPI_INFO_NULL, request);
    
}




