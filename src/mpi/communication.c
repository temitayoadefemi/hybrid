#include "mpi.h"
#include <stdio.h>
#include "structs.h"



int hybrid_send(void *data, int count,  hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Send(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm);
}

int hybrid_recv(void *data, int count,  hybrid_datatype_t *datatype, int source, int tag, hybrid_interface_t *hybrid_root_interface,  hybrid_status_t *status) {
    return MPI_Recv(data, count, datatype, source, tag, hybrid_root_interface->mpi_struct.comm, status);

}

int hybrid_isend(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Isend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
} 

int hybrid_ibsend(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ibsend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_issend(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Issend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_irsend(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Irsend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
}

int hybrid_irecv(void *data, int count, hybrid_datatype_t *datatype, int source, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Irecv(data, count, datatype, source, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_sendrecv(void *send_data, int send_count,  hybrid_datatype_t *send_datatype, int dest, int send_tag, void *recv_data, int recv_count,  hybrid_datatype_t; recv_datatype, int source, int recv_tag, hybrid_interface_t *hybrid_root_interface, hybrid_status_t *status) {
   return MPI_Sendrecv(send_data, send_count, send_datatype, dest, send_tag, recv_data, recv_count, recv_datatype, source, recv_tag, hybrid_root_interface->mpi_struct.comm, status);
    
}

int hybrid_isendrecv(void *send_data, int send_count, hybrid_datatype_t *send_datatype, int dest, int send_tag, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, int source, int recv_tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Issend(send_data, send_count, send_datatype, dest, send_tag, recv_data, recv_count, recv_datatype, source, recv_tag, hybrid_root_interface->mpi_struct.comm, request);
    
}
int hybrid_barrier(hybrid_interface_t *hybrid_root_interface) {
    return MPI_Barrier(hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_bcast(void *data, int count, hybrid_datatype_t *datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Bcast(data, count, datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_gather(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Gather(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_gather_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Gather(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_gatherv(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Gatherv(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_gatherv_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Gatherv(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}


int hybrid_test(hybrid_request_t *request, int *flag, hybrid_status_t *status) {
    return MPI_Test(request, flag, &status->mpi_status);
    
}

int hybrid_scatter(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Scatter(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_scatter_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Scatter(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_scatterv(void *send_data, int *send_counts, int *displs, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Scatterv(send_data, send_counts, displs, send_datatype, recv_data, recv_count, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_scatterv_c(void *send_data, int *send_counts, int *displs, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Scatterv(send_data, send_counts, displs, send_datatype, recv_data, recv_count, recv_datatype, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_allgather(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Allgather(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_allgather_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Allgather(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_allgatherv(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Allgatherv(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_allgatherv_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *displs, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Allgatherv(send_data, send_count, send_datatype, recv_data, recv_counts, displs, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_alltoall(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Alltoall(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}
int hybrid_alltoall_c(void *send_data, int send_count, hybrid_datatype_t *send_datatype, void *recv_data, int recv_count, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Alltoall(send_data, send_count, send_datatype, recv_data, recv_count, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_alltoallv(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Alltoallv(send_data, send_counts, sdispls, send_datatype, recv_data, recv_counts, rdispls, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_alltoallv_c(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatype, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatype, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Alltoallv(send_data, send_counts, sdispls, send_datatype, recv_data, recv_counts, rdispls, recv_datatype, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_alltoallw(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatypes, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatypes, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Alltoallw(send_data, send_counts, sdispls, send_datatypes, recv_data, recv_counts, rdispls, recv_datatypes, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_alltoallw_c(void *send_data, int *send_counts, int *sdispls, hybrid_datatype_t *send_datatypes, void *recv_data, int *recv_counts, int *rdispls, hybrid_datatype_t *recv_datatypes, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Alltoallw(send_data, send_counts, sdispls, send_datatypes, recv_data, recv_counts, rdispls, recv_datatypes, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_reduce(void *send_data, void *recv_data, int count, hybrid_datatype_t *datatype, hybrid_op_t *op, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Reduce(send_data, recv_data, count, datatype, op, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_reduce_c(void *send_data, void *recv_data, int count, hybrid_datatype_t *datatype, hybrid_op_t *op, int root, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Reduce(send_data, recv_data, count, datatype, op, root, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_type_get_value_index(hybrid_datatype_t type, int *array_of_integers, hybrid_datatype_t *array_of_datatypes) {
    return MPI_Type_get_contents(type, array_of_integers, array_of_datatypes);
    
}

int hybrid_op_create(hybrid_user_function_t *function, int commute, hybrid_op_t *op) {
    return MPI_Op_create(function, commute, &op->mpi_op);
    
}
int hybrid_wait(hybrid_request_t *request, hybrid_status_t *status) {
    return MPI_Wait(request, &status->mpi_status);
    
}

int hybrid_waitall(int count, hybrid_request_t *requests, hybrid_status_t *statuses) {
    return MPI_Waitall(count, requests, statuses);
    
}


int hybrid_waitany(int count, hybrid_request_t *requests, int *index, hybrid_status_t *status) {
    return MPI_Waitany(count, requests, index, &status->mpi_status);
    
}
int hybrid_waitall(int count, hybrid_request_t *requests, hybrid_status_t *statuses) {
    return MPI_Waitall(count, requests, statuses);
    
}

int hybrid_waitsome(int count, hybrid_request_t *requests, int *outcount, int *indices, hybrid_status_t *statuses) {
    return MPI_Waitsome(count, requests, outcount, indices, statuses);
    
}

int hybrid_testany(int count, hybrid_request_t *requests, int *flag, hybrid_status_t *status) {
    return MPI_Testany(count, requests, flag, &status->mpi_status);
    
}

int hybrid_testall(int count, hybrid_request_t *requests, int *flag, hybrid_status_t *statuses) {
    return MPI_Testall(count, requests, flag, statuses);
    
}
int hybrid_testsome(int count, hybrid_request_t *requests, int *outcount, int *indices, hybrid_status_t *statuses) {
    return MPI_Testsome(count, requests, outcount, indices, statuses);
    
}

int hybrid_sendrecv_replace(void *data, int count, hybrid_datatype_t *datatype, int dest, int send_tag, int source, int recv_tag, hybrid_interface_t *hybrid_root_interface, hybrid_status_t *status) {
    return MPI_Sendrecv_replace(data, count, datatype, dest, send_tag, source, recv_tag, hybrid_root_interface->mpi_struct.comm, status);
    
}

int hybrid_send_init(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Send_init(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}
int hybrid_recv_init(void *data, int count, hybrid_datatype_t *datatype, int source, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Recv_init(data, count, datatype, source, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}
int hybrid_bsend(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Bsend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_bsend_init(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Bsend_init(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_ssend(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Ssend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_ssend_init(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ssend_init(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_rsend(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface) {
    return MPI_Rsend(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_rsend_init(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Rsend_init(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_psend_init(void *data, int count, hybrid_datatype_t *datatype, int dest, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Psend_init(data, count, datatype, dest, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_pready(int count, hybrid_request_t *request) {
    return MPI_Pready(count, requests);
    
}

int hybrid_pready_range(int start, int end, hybrid_request_t *request) {
    return MPI_Pready_range(start, end, requests);
    
}

int hybrid_pready_list(int count, int *array_of_indices, hybrid_request_t *request) {
    return MPI_Pready_list(count, array_of_indices, requests);
    
}

int hybrid_precv_init(void *data, int count, hybrid_datatype_t *datatype, int source, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Precv_init(data, count, datatype, source, tag, hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_pready_list(int count, int *array_of_indices, hybrid_request_t *request) {
    return MPI_Pready_list(count, array_of_indices, requests);
    
}

int hybrid_parrived(hybrid_request_t *request, int partition int *flag) {
    return MPI_Parrived(request, partition, flag);
    
}
int hybrid_comm_attach_buffer(void *buffer, int size) {
    return MPI_Buffer_attach(buffer, size);
    
}

int hybrid_comm_detach_buffer(void *buffer, int *size) {
    return MPI_Buffer_detach(buffer, size);

}
    
int hybrid_session_attach_buffer(void *buffer, int size) {
    return MPI_Session_attach_buffer(buffer, size);
    
}

int hybrid_session_detach_buffer(void *buffer, int *size) {
    return MPI_Session_detach_buffer(buffer, size);
    
}

int hybrid_comm_flush(hybrid_interface_t *hybrid_root_interface) {
    return MPI_Comm_flush(hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_comm_iflush(hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Comm_iflush(hybrid_root_interface->mpi_struct.comm, request);
    
}

int hybrid_session_flush_buffer(hybrid_session_t *session) {
    return MPI_Session_flush_buffer();
    
}
int hybrid_comm_iflush_buffer(hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Comm_iflush_buffer(hybrid_root_interface->mpi_struct.comm, request);
}

int hybrid_rrecv(void *data, int count, hybrid_datatype_t *datatype, int source, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_status_t *status) {
    return MPI_Rrecv(data, count, datatype, source, tag, hybrid_root_interface->mpi_struct.comm, status);
    
}

int hybrid_mrecv(void *data, int count, hybrid_datatype_t *datatype, hybrid_request_t *message, hybrid_status_t *status) {
    return MPI_Mrecv(data, count, datatype, message, &status->mpi_status);
    
}

int hybrid_imrecv(void *data, int count, hybrid_datatype_t *datatype, hybrid_request_t *message, hybrid_request_t *request) {
    return MPI_Imrecv(data, count, datatype, message, request);
    
}

int hybrid_bcast(void *data, int count,  hybrid_datatype_t *datatype, int root, hybrid_interface_t *hybrid_root_interface, ) {
    return MPI_Bcast(data, count, datatype, root, hybrid_root_interface->mpi_struct.comm);

}

int hybrid_ibcast(void *data, int count,  hybrid_datatype_t *datatype, int root, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *request) {
    return MPI_Ibcast(data, count, datatype, root, hybrid_root_interface->mpi_struct.comm, request);

}
int hybrid_barrier(hybrid_interface_t *hybrid_root_interface) {
    return MPI_Barrier(hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_status_get_source(hybrid_status_t *status, int *source) {
    return MPI_Status_get_source(&status->mpi_status, source);
    
}

int hybrid_status_get_tag(hybrid_status_t *status, int *tag) {
    return MPI_Status_get_tag(&status->mpi_status, tag);
    
}

int hybrid_request_get_status(hybrid_request_t *request, hybrid_status_t *status) {
    return MPI_Request_get_status(request, &status->mpi_status);
    
}

int hybrid_request_get_status_any(int count, hybrid_request_t *requests, int *index, int *flag, hybrid_status_t *status) {
    return MPI_Request_get_status_any(count, requests, index, flag, &status->mpi_status);
    
}

int hybrid_request_get_status_any(int count, hybrid_request_t *requests, int *index, int *flag, hybrid_status_t *status) {
    return MPI_Request_get_status_any(count, requests, index, flag, &status->mpi_status);
    
}
int hybrid_request_get_status_some(int count, hybrid_request_t *requests, int *outcount, int *indices, hybrid_status_t *statuses) {
    return MPI_Request_get_status_some(count, requests, outcount, indices, statuses);
    
}

int hybrid_probe(int source, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_status_t *status) {
    return MPI_Probe(source, tag, hybrid_root_interface->mpi_struct.comm, &status->mpi_status);
    
}

int hybrid_iprobe(int source, int tag, hybrid_interface_t *hybrid_root_interface, int *flag, hybrid_status_t *status) {
    return MPI_Iprobe(source, tag, hybrid_root_interface->mpi_struct.comm, flag, &status->mpi_status);
    
}

int hybrid_mprobe(int source, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *message, hybrid_status_t *status) {
    return MPI_Mprobe(source, tag, hybrid_root_interface->mpi_struct.comm, message, &status->mpi_status);
    
}

int hybrid_improbe(int source, int tag, hybrid_interface_t *hybrid_root_interface, hybrid_request_t *message, int *flag, hybrid_status_t *status) {
    return MPI_Improbe(source, tag, hybrid_root_interface->mpi_struct.comm, message, flag, &status->mpi_status);
    
}

int hybrid_cancel(hybrid_request_t *request) {
    return MPI_Cancel(request);
    
}

int hybrid_test_cancelled(hybrid_status_t *status, int *flag) {
    return MPI_Test_cancelled(&status->mpi_status, flag);
    
}
