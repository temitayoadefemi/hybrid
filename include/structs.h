#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <mpi.h>
#include <omp.h>

typedef mpi_struct {
    int rank;
    int size;
    int provided;
    MPI_Comm comm;
} mpi_str;


typedef openmp_struct {
    int thread_id;
} openmp_str;


typedef struct hybrid_root_interface {
    int process_size;
    int thread_size;
    mpi_str mpi_struct;
    openmp_str openmp_struct;
} hybrid_interface_t;


typedef struct hybrid_node_object {
    char *node_type;
    int size;
    int object_container[100]
    hybrid_interface_t *hybrid_root
} hybrid_node_object;



#endif	//__STRUCTS_H__