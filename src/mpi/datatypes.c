#include "mpi.h"
#include <stdio.h>
#include "structs.h"


int hybrid_type_create_vector(int count, int blocklength, int stride, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_vector(count, blocklength, stride, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}

int hybrid_type_create_hvector(int count, int blocklength, hybrid_aint_t stride, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_hvector(count, blocklength, stride, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}

int hybrid_type_create_contiguous(int count, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_contiguous(count, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}

int hybrid_type_create_struct(int count, int *blocklengths, hybrid_aint_t *displacements, hybrid_datatype_t *oldtypes, hybrid_datatype_t *newtype) {
    MPI_Type_create_struct(count, blocklengths, displacements, oldtypes, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}


int hybrid_type_create_struct_c(int count, int *blocklengths, int *displacements, hybrid_datatype_t *oldtypes, hybrid_datatype_t *newtype) {
    MPI_Type_create_struct(count, blocklengths, displacements, oldtypes, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}

int hybrid_type_create_subarray(int ndims, int *sizes, int *subsizes, int *starts, int order, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_create_subarray(ndims, sizes, subsizes, starts, order, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}

int hybrid_type_create_subarray_c(int ndims, int *sizes, int *subsizes, int *starts, int order, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_create_subarray(ndims, sizes, subsizes, starts, order, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}

int hybrid_type_create_darray(int size, int rank, int ndims, int *array_of_gsizes, int *array_of_distribs, int *array_of_dargs, int *array_of_psizes, int order, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

} 

int hybrid_get_address(const void *location, hybrid_aint_t *address) {
    return MPI_Get_address(location, address);
    
}

int hybrid_aint_add(hybrid_aint_t base, hybrid_aint_t disp, hybrid_aint_t *result) {
    return MPI_Aint_add(base, disp, result);
    
}

int hybrid_type_size(hybrid_datatype_t type, hybrid_aint_t *size) {
    return MPI_Type_sizeof(type, size);
    
}

int hybrid_type_size_c(hybrid_datatype_t type, int *size) {
    return MPI_Type_size(type, size);
    
}

int hybrid_type_get_extent(hybrid_datatype_t type, hybrid_aint_t *extent) {
    return MPI_Type_extent(type, extent);
    
}

int hybrid_type_get_extent_c(hybrid_datatype_t type, hybrid_aint_t *lb, hybrid_aint_t *extent) {
    return MPI_Type_get_extent(type, lb, extent);
    
}
int hybrid_type_get_true_extent(hybrid_datatype_t type, int *lb, int *extent) {
    return MPI_Type_get_extent(type, lb, extent);
    
}

int hybrid_type_get_true_extent_c(hybrid_datatype_t type, hybrid_aint_t *lb, hybrid_aint_t *extent) {
    return MPI_Type_get_true_extent(type, lb, extent);
    
}

int hybrid_type_create_resized(hybrid_datatype_t oldtype, hybrid_aint_t lb, hybrid_aint_t extent, hybrid_datatype_t *newtype) {
    MPI_Type_create_resized(oldtype, lb, extent, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}

int hybrid_type_create_resized_c(hybrid_datatype_t oldtype, int lb, int extent, hybrid_datatype_t *newtype) {
    MPI_Type_create_resized(oldtype, lb, extent, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}


int hybrid_aint_diff(hybrid_aint_t addr1, hybrid_aint_t addr2, hybrid_aint_t *result) {
    return MPI_Aint_diff(addr1, addr2, result);
    
}

int hybrid_type_size(hybrid_datatype_t type, hybrid_aint_t *size) {
    return MPI_Type_size(type, size);
    
}

int hybrid_type_size_c(hybrid_datatype_t type, int *size) {
    return MPI_Type_size(type, size);
    
}

int hybrid_type_extent(hybrid_datatype_t type, hybrid_aint_t *extent) {
    return MPI_Type_extent(type, extent);
    
}

int 
int hybrid_type_create_contigious_c(int count, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_contiguous(count, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;
    
}


int hybrid_type_create_indexed(int count, int *blocklengths, int *displacements, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_indexed(count, blocklengths, displacements, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}


int hybrid_type_create_hindexed(int count, int *blocklengths, hybrid_aint_t *displacements, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_hindexed(count, blocklengths, displacements, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}


int hybrid_type_create_indexed_block(int count, int blocklength, int *displacements, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_indexed(count, blocklength, displacements, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}

int hybrid_type_create_subarray(int ndims, int *sizes, int *subsizes, int *starts, int order, hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_create_subarray(ndims, sizes, subsizes, starts, order, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}
int hybrid_get_elements(hybrid_status_t *status, hybrid_datatype_t *datatype, int *count) {
    return MPI_Get_elements(status, datatype->mpi_type, count);
    
}

int hybrid_get_elements_c(hybrid_status_t *status, hybrid_datatype_t *datatype, int *count) {
    return MPI_Get_elements(status, datatype->mpi_type, count);
    
}

int hybrid_type_get_contents(hybrid_datatype_t type, int max_integers, int max_addresses, int max_datatypes, int *array_of_integers, hybrid_aint_t *array_of_addresses, hybrid_datatype_t *array_of_datatypes) {
    return MPI_Type_get_contents(type, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);
    
}

int hybrid_pack(const void *inbuf, int incount, hybrid_datatype_t datatype, void *outbuf, int outsize, int *position) {
    return MPI_Pack(inbuf, incount, datatype, outbuf, outsize, position);
    
}

int hybrid_pack_c(const void *inbuf, int incount, hybrid_datatype_t datatype, void *outbuf, int outsize, int *position) {
    return MPI_Pack(inbuf, incount, datatype, outbuf, outsize, position);
    
}

int hybrid_unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, hybrid_datatype_t datatype) {
    return MPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype);
    
}

int hybrid_unpack_c(const void *inbuf, int insize, int *position, void *outbuf, int outcount, hybrid_datatype_t datatype) {
    return MPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype);
    
}

int hybrid_pack_size(int incount, hybrid_datatype_t datatype, int *size) {
    return MPI_Pack_size(incount, datatype, size);
    
}

int hybrid_pack_external(const char *datarep, const void *inbuf, int incount, hybrid_datatype_t datatype, void *outbuf, hybrid_aint_t *position) {
    return MPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, position);
    
}

int hybrid_pack_external_c(const char *datarep, const void *inbuf, int incount, hybrid_datatype_t datatype, void *outbuf, int *position) {
    return MPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, position);
    
}

int hybrid_pack_size_c(int incount, hybrid_datatype_t datatype, int *size) {
    return MPI_Pack_size(incount, datatype, size);
    
}

int hybrid_pack_external_size(const char *datarep, int incount, hybrid_datatype_t datatype, hybrid_aint_t *size) {
    return MPI_Pack_external_size(datarep, incount, datatype, size);
    
}

int hybrid_pack_external_size_c(const char *datarep, int incount, hybrid_datatype_t datatype, int *size) {
    return MPI_Pack_external_size(datarep, incount, datatype, size);
    
}


int hybrid_type_get_envelope(hybrid_datatype_t type, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) {
    return MPI_Type_get_envelope(type, num_integers, num_addresses, num_datatypes, combiner);
    
}
int hybrid_type_get_envelope_c(hybrid_datatype_t type, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) {
    return MPI_Type_get_envelope(type, num_integers, num_addresses, num_datatypes, combiner);
    
}

int hybrid_type_create_datatype(hybrid_datatype_t *newtype, int count, hybrid_datatype_t oldtype) {
    MPI_Type_contigious(count, oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}

int hybrid_type_duplicate(hybrid_datatype_t oldtype, hybrid_datatype_t *newtype) {
    MPI_Type_dup(oldtype, &newtype->mpi_type);
    MPI_Type_commit(&newtype->mpi_type);
    return newtype;

}

int hybrid_type_commit(hybrid_datatype_t *type) {
    return MPI_Type_commit(&type->mpi_type);
    
}


int hybrid_type_free(hybrid_datatype_t *type) {
    return MPI_Type_free(&type->mpi_type);
    
}

int hybrid_get_count(hybrid_status_t *status, hybrid_datatype_t *datatype, int *count) {
    return MPI_Get_count(status, datatype->mpi_type, count);
    
}

