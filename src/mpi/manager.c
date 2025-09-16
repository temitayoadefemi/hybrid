#include "mpi.h"
#include <stdio.h>
#include "structs.h"


int hybrid_comm_spawn(char *command, char *argv[], int maxprocs, hybrid_info_t *info, int root, hybrid_interface_t *hybrid_root_interface, hybrid_interface_t *intercomm) {
    return MPI_Comm_spawn(command, argv, maxprocs, info->mpi_info, root, hybrid_root_interface->mpi_struct.comm, &intercomm->mpi_struct.comm, MPI_ERRCODES_IGNORE);
    
}

int hybrid_comm_get_parent(hybrid_interface_t *intercomm) {
    return MPI_Comm_get_parent(&intercomm->mpi_struct.comm);
    
}

int hybrid_comm_spawn_multiple(int count, char *commands[], char **argv[], int maxprocs[], hybrid_info_t *info[], int root, hybrid_interface_t *hybrid_root_interface, hybrid_interface_t *intercomm) {
    return MPI_Comm_spawn_multiple(count, commands, argv, maxprocs, info->mpi_info, root, hybrid_root_interface->mpi_struct.comm, &intercomm->mpi_struct.comm, MPI_ERRCODES_IGNORE);
    
}

int hybrid_open_port(hybrid_info_t *info, char *port_name) {
    return MPI_Open_port(info->mpi_info, port_name);
    
}

int hybrid_close_port(const char *port_name) {
    return MPI_Close_port(port_name);
    
}

int hybrid_comm_accept(const char *port_name, hybrid_info_t *info, int root, hybrid_interface_t *hybrid_root_interface, hybrid_interface_t *intercomm) {
    return MPI_Comm_accept(port_name, info->mpi_info, root, hybrid_root_interface->mpi_struct.comm, &intercomm->mpi_struct.comm);
    
}

int hybrid_comm_connect(const char *port_name, hybrid_info_t *info, int root, hybrid_interface_t *hybrid_root_interface, hybrid_interface_t *intercomm) {
    return MPI_Comm_connect(port_name, info->mpi_info, root, hybrid_root_interface->mpi_struct.comm, &intercomm->mpi_struct.comm);
    
}

int hybrid_publish_name(const char *service_name, hybrid_info_t *info, const char *port_name) {
    return MPI_Publish_name(service_name, info->mpi_info, port_name);
    
}

int hybrid_unpublish_name(const char *service_name, hybrid_info_t *info) {
    return MPI_Unpublish_name(service_name, info->mpi_info);
    
}

int hybrid_lookup_name(const char *service_name, hybrid_info_t *info, char *port_name) {
    return MPI_Lookup_name(service_name, info->mpi_info, port_name);
    
}


int hybrid_comm_disconnect(hybrid_interface_t *intercomm) {
    return MPI_Comm_disconnect(&intercomm->mpi_struct.comm);
    
}

int hybrid_comm_join(hybrid_interface_t *intercomm, hybrid_interface_t *newintracomm) {
    return MPI_Comm_join(intercomm->mpi_struct.comm, &newintracomm->mpi_struct.comm);
    
}

int hybrid_win_create(void *base, hybrid_aint_t *size, int disp_unit, hybrid_info_t *info, hybrid_interface_t *hybrid_root_interface, hybrid_win_t *win) {
    return MPI_Win_create(base, size, disp_unit, info->mpi_info, hybrid_root_interface->mpi_struct.comm, &win->mpi_win);
    
}

int hybrid_win_allocate(hybrid_aint_t *size, int disp_unit, hybrid_info_t *info, hybrid_interface_t *hybrid_root_interface, void *baseptr, hybrid_win_t *win) {
    return MPI_Win_allocate(size, disp_unit, info->mpi_info, hybrid_root_interface->mpi_struct.comm, baseptr, &win->mpi_win);
    
}

int hybrid_win_allocate_shared(hybrid_aint_t *size, int disp_unit, hybrid_info_t *info, hybrid_interface_t *hybrid_root_interface, void *baseptr, hybrid_win_t *win) {
    return MPI_Win_allocate_shared(size, disp_unit, info->mpi_info, hybrid_root_interface->mpi_struct.comm, baseptr, &win->mpi_win);
    
}

int hybrid_win_shared_query(hybrid_win_t *win, int rank, hybrid_aint_t *size, int *disp_unit, void *baseptr) {
    return MPI_Win_shared_query(win->mpi_win, rank, size, disp_unit, baseptr);
    
}

int hybrid_win_create_dynamic(hybrid_info_t *info, hybrid_interface_t *hybrid_root_interface, hybrid_win_t *win) {
    return MPI_Win_create_dynamic(info->mpi_info, hybrid_root_interface->mpi_struct.comm, &win->mpi_win);
    
}

int hybrid_win_attach(hybrid_win_t *win, void *base, hybrid_aint_t *size) {
    return MPI_Win_attach(win->mpi_win, base, size);
    
}

int hybrid_win_detach(hybrid_win_t *win, const void *base) {
    return MPI_Win_detach(win->mpi_win, base);
    
}

int hybrid_win_free(hybrid_win_t *win) {
    return MPI_Win_free(&win->mpi_win);
    
}

int hybrid_win_get_group(hybrid_win_t *win, hybrid_group_t *group) {
    return MPI_Win_get_group(win->mpi_win, &group->mpi_group);
    
}

int hybrid_win_set_info(hybrid_win_t *win, hybrid_info_t *info) {
    return MPI_Win_set_info(win->mpi_win, info->mpi_info);
    
}

int hybrid_win_get_info(hybrid_win_t *win, hybrid_info_t *info) {
    return MPI_Win_get_info(win->mpi_win, &info->mpi_info);
    
}

int hybrid_put(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_win_t *win) {
    return MPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win->mpi_win);
    
}

int hybrid_get(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_win_t *win) {
    return MPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win->mpi_win);
    
}

int hybrid_accumulate(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_op_t *op, hybrid_win_t *win) {
    return MPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op->mpi_op, win->mpi_win);
    
}

int hybrid_get_accumulate(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, void *result_addr, int result_count, hybrid_datatype_t *result_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_op_t *op, hybrid_win_t *win) {
    return MPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op->mpi_op, win->mpi_win);
    
}

int hybrid_fetch_and_op(void *origin_addr, void *result_addr, hybrid_datatype_t *datatype, int target_rank, hybrid_aint_t *target_disp, hybrid_op_t *op, hybrid_win_t *win) {
    return MPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op->mpi_op, win->mpi_win);
    
}

int hybrid_compare_and_swap(void *origin_addr, void *compare_addr, void *result_addr, hybrid_datatype_t *datatype, int target_rank, hybrid_aint_t *target_disp, hybrid_win_t *win) {
    return MPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win->mpi_win);
    
}

int hybrid_rput(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_win_t *win, hybrid_request_t *request) {
    return MPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win->mpi_win, request);
    
}

int hybrid_rget(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_win_t *win, hybrid_request_t *request) {
    return MPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win->mpi_win, request);
    
}

int hybrid_raccumulate(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_op_t *op, hybrid_win_t *win, hybrid_request_t *request) {
    return MPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op->mpi_op, win->mpi_win, request);
    
}

int hybrid_rget_accumulate(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, void *result_addr, int result_count, hybrid_datatype_t *result_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_op_t *op, hybrid_win_t *win, hybrid_request_t *request) {
    return MPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op->mpi_op, win->mpi_win, request);
    
}

int hybrid_rget_accumulate_c(void *origin_addr, int origin_count, hybrid_datatype_t *origin_datatype, void *result_addr, int result_count, hybrid_datatype_t *result_datatype, int target_rank, hybrid_aint_t *target_disp, int target_count, hybrid_datatype_t *target_datatype, hybrid_op_t *op, hybrid_win_t *win, hybrid_request_t *request) {
    return MPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op->mpi_op, win->mpi_win, request);
    
}

int hybrid_win_fence(int assert, hybrid_win_t *win) {
    return MPI_Win_fence(assert, win->mpi_win);
    
}

int hybrid_win_start(hybrid_group_t *group, int assert, hybrid_win_t *win) {
    return MPI_Win_start(group->mpi_group, assert, win->mpi_win);
    
}

int hybrid_win_complete(hybrid_win_t *win) {
    return MPI_Win_complete(win->mpi_win);
    
}

int hybrid_win_post(hybrid_group_t *group, int assert, hybrid_win_t *win) {
    return MPI_Win_post(group->mpi_group, assert, win->mpi_win);
    
}

int hybrid_win_wait(hybrid_win_t *win) {
    return MPI_Win_wait(win->mpi_win);
    
}

int hybrid_win_test(hybrid_win_t *win, int *flag) {
    return MPI_Win_test(win->mpi_win, flag);
    
}

int hybrid_win_lock(int lock_type, int rank, int assert, hybrid_win_t *win) {
    return MPI_Win_lock(lock_type, rank, assert, win->mpi_win);
    
}

int hybrid_win_lock_all(int assert, hybrid_win_t *win) {
    return MPI_Win_lock_all(assert, win->mpi_win);
    
}

int hybrid_win_unlock(int rank, hybrid_win_t *win) {
    return MPI_Win_unlock(rank, win->mpi_win);
    
}

int hybrid_win_unlock_all(hybrid_win_t *win) {
    return MPI_Win_unlock_all(win->mpi_win);
    
}

int hybrid_win_flush(int rank, hybrid_win_t *win) {
    return MPI_Win_flush(rank, win->mpi_win);
    
}

int hybrid_win_flush_all(hybrid_win_t *win) {
    return MPI_Win_flush_all(win->mpi_win);
    
}

int hybrid_win_flush_local(int rank, hybrid_win_t *win) {
    return MPI_Win_flush_local(rank, win->mpi_win);
    
}

int hybrid_win_flush_local_all(hybrid_win_t *win) {
    return MPI_Win_flush_local_all(win->mpi_win);
    
}

int hybrid_win_sync(hybrid_win_t *win) {
    return MPI_Win_sync(win->mpi_win);
    
}




