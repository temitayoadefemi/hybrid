#include "mpi.h"
#include <stdio.h>
#include "structs.h"


int hybrid_get_version(int *version, int *subversion) {
    return MPI_Get_version(version, subversion);
    
}

int hybrid_get_library_version(char *version, int *resultlen) {
    return MPI_Get_library_version(version, resultlen);
    
}

int hybrid_get_processor_name(char *name, int *resultlen) {
    return MPI_Get_processor_name(name, resultlen);
    
}

int hybrid_get_hw_resource_name(int resource_type, int index, char *name, int *resultlen) {
    return MPI_Get_hw_resource_name(resource_type, index, name, resultlen);
    
}

int hybrid_alloc_mem(size_t size, hybrid_info_t *info, void *baseptr) {
    return MPI_Alloc_mem(size, info->mpi_info, baseptr);
    
}
int hybrid_free_mem(void *base) {
    return MPI_Free_mem(base);
    
}

int hybrid_comm_set_errhandler(hybrid_interface_t *hybrid_root_interface, hybrid_errhandler_t *errhandler) {
    return MPI_Comm_set_errhandler(hybrid_root_interface->mpi_struct.comm, errhandler->mpi_errhandler);
    
}
int hybrid_comm_get_errhandler(hybrid_interface_t *hybrid_root_interface, hybrid_errhandler_t *errhandler) {
    return MPI_Comm_get_errhandler(hybrid_root_interface->mpi_struct.comm, &errhandler->mpi_errhandler);
    
}

int hybrid_win_create_errhandler(hybrid_errhandler_t *errhandler) {
    return MPI_Win_create_errhandler(MPI_Win_errhandler_function, &errhandler->mpi_errhandler);
    
}

int hybrid_win_set_errhandler(hybrid_win_t *win, hybrid_errhandler_t *errhandler) {
    return MPI_Win_set_errhandler(win->mpi_win, errhandler->mpi_errhandler);
    
}

int hybrid_win_get_errhandler(hybrid_win_t *win, hybrid_errhandler_t *errhandler) {
    return MPI_Win_get_errhandler(win->mpi_win, &errhandler->mpi_errhandler);
    
}

int hybrid_file_create_errhandler(hybrid_errhandler_t *errhandler) {
    return MPI_File_create_errhandler(MPI_File_errhandler_function, &errhandler->mpi_errhandler);
    
}

int hybrid_file_set_errhandler(hybrid_file_t *file, hybrid_errhandler_t *errhandler) {
    return MPI_File_set_errhandler(file->mpi_file, errhandler->mpi_errhandler);
    
}

int hybrid_file_get_errhandler(hybrid_file_t *file, hybrid_errhandler_t *errhandler) {
    return MPI_File_get_errhandler(file->mpi_file, &errhandler->mpi_errhandler);
    
}

int hybrid_session_create_errhandler(hybrid_errhandler_t *errhandler) {
    return MPI_Session_create_errhandler(MPI_Session_errhandler_function, &errhandler->mpi_errhandler);
    
}

int hybrid_session_set_errhandler(hybrid_session_t *session, hybrid_errhandler_t *errhandler) {
    return MPI_Session_set_errhandler(session->mpi_session, errhandler->mpi_errhandler);
    
}

int hybrid_session_get_errhandler(hybrid_session_t *session, hybrid_errhandler_t *errhandler) {
    return MPI_Session_get_errhandler(session->mpi_session, &errhandler->mpi_errhandler);
    
}

int hybrid_err_string(int errcode, char *string, int *resultlen) {
    return MPI_Error_string(errcode, string, resultlen);
    
}

int hybrid_err_class(int errcode, int *errorclass) {
    return MPI_Error_class(errcode, errorclass);
    
}

int hybrid_add_error_class(int *errorclass) {
    return MPI_Add_error_class(errorclass);
    
}

int hybrid_remove_error_class(int *errorclass) {
    return MPI_Remove_error_class(errorclass);
    
}

int hybrid_add_error_code(int errorclass, int *errorcode) {
    return MPI_Add_error_code(errorclass, errorcode);
    
}

int hybrid_remove_error_code(int *errorcode) {
    return MPI_Remove_error_code(errorcode);
    
}

int hybrid_add_error_string(int errorcode, const char *string) {
    return MPI_Add_error_string(errorcode, string);
    
}

int hybrid_remove_error_string(int errorcode) {
    return MPI_Remove_error_string(errorcode);
    
}

int hybrid_comm_call_errhandler(hybrid_interface_t *hybrid_root_interface, int errcode) {
    return MPI_Comm_call_errhandler(hybrid_root_interface->mpi_struct.comm, errcode);
    
}

int hybrid_win_call_errhandler(hybrid_win_t *win, int errcode) {
    return MPI_Win_call_errhandler(win->mpi_win, errcode);
    
}

int hybrid_file_call_errhandler(hybrid_file_t *file, int errcode) {
    return MPI_File_call_errhandler(file->mpi_file, errcode);
    
}

int hybrid_session_call_errhandler(hybrid_session_t *session, int errcode) {
    return MPI_Session_call_errhandler(session->mpi_session, errcode);
    
}

int hybrid_info_create(hybrid_info_t *info) {
    return MPI_Info_create(&info->mpi_info);
    
}

int hybrid_info_set(hybrid_info_t *info, const char *key, const char *value) {
    return MPI_Info_set(info->mpi_info, key, value);
    
}

int hybrid_info_delete(hybrid_info_t *info, const char *key) {
    return MPI_Info_delete(info->mpi_info, key);
    
}

int hybrid_info_get_string(hybrid_info_t *info, const char *key, int valuelen, char *value, int *flag) {
    return MPI_Info_get_string(info->mpi_info, key, valuelen, value, flag);
    
}

int hybrid_info_get_nkeys(hybrid_info_t *info, int *nkeys) {
    return MPI_Info_get_nkeys(info->mpi_info, nkeys);
    
}

int hybrid_info_get_nthkey(hybrid_info_t *info, int n, char *key) {
    return MPI_Info_get_nthkey(info->mpi_info, n, key);
    
}

int hybrid_info_dup(hybrid_info_t *info, hybrid_info_t *newinfo) {
    return MPI_Info_dup(info->mpi_info, &newinfo->mpi_info);
    
}

int hybrid_info_free(hybrid_info_t *info) {
    return MPI_Info_free(&info->mpi_info);
    
}

int hybrid_info_create_env(hybrid_info_t *info) {
    return MPI_Info_create_env(&info->mpi_info);
    
}







