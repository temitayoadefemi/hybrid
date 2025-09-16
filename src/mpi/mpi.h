#ifndef __MPI_STRUCTS_H_
#define __MPI_STRUCTS_H__

#include "mpi.h"

struct HYBRID_DATATYPE {
    MPI_Datatype mpi_type;
}; hybrid_datatype_t;

struct HYBRID_REQUEST {
    MPI_Request mpi_request;
}; hybrid_request_t;

struct HYBRID_STATUS {
    MPI_Status mpi_status;
}; hybrid_status_t;

struct HYBRID_OP {
    MPI_Op mpi_op;
}; hybrid_op_t;

struct HYBRID_COMM {
    MPI_Comm mpi_comm;
}; hybrid_comm_t;

struct HYBRID_GROUP {
    MPI_Group mpi_group;
}; hybrid_group_t;

struct HYBRID_ERRHANDLER {
    MPI_Errhandler mpi_errhandler;
}; hybrid_errhandler_t;

struct HYBRID_FILE {
    MPI_File mpi_file;
}; hybrid_file_t;

struct HYBRID_AINT {
    MPI_Aint mpi_aint;
}; hybrid_aint_t;

struct HYBRID_OFFSET {
    MPI_Offset mpi_offset;
}; hybrid_offset_t;

struct HYBRID_COUNT {
    MPI_Count mpi_count;
}; hybrid_count_t;

struct HYBRID_SESSION {
    MPI_Session mpi_session;
}; hybrid_session_t;

struct HYBRID_AINT {
    MPI_Aint mpi_aint;
}; hybrid_aint_t;

struct HYBRID_USER_FUNCTION {
    MPI_User_function *mpi_user_function;
}; hybrid_user_function_t;

struct HYBRID_GROUP {
    MPI_Group mpi_group;
}; hybrid_group_t;

struct HYBRID_WTIME {
    double mpi_wtime;
}; hybrid_wtime_t;

struct HYBRID_WTICK {
    double mpi_wtick;
}; hybrid_wtick_t;

struct HYBRID_WIN {
    MPI_Win mpi_win;
}; hybrid_win_t;

struct HYBRID_T_ENUM {
    MPI_T_enum mpi_t_enum;
}; hybrid_t_enum_t;

#endif	//__MPI__STRUCTS_H__
