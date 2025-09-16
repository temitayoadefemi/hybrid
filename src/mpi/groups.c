#include "mpi.h"
#include <stdio.h>
#include "structs.h"

int hybrid_group_size(hybrid_group_t *group, int *size) {
    return MPI_Group_size(group->mpi_group, size);
    
}

int hybrid_group_rank(hybrid_group_t *group, int *rank) {
    return MPI_Group_rank(group->mpi_group, rank);
    
}

int hybrid_group_translate_ranks(hybrid_group_t *group1, int n, int *ranks1, hybrid_group_t *group2, int *ranks2) {
    return MPI_Group_translate_ranks(group1->mpi_group, n, ranks1, group2->mpi_group, ranks2);
    
}

int hybrid_group_compare(hybrid_group_t *group1, hybrid_group_t *group2, int *result) {
    return MPI_Group_compare(group1->mpi_group, group2->mpi_group, result);
    
}

int hybrid_group_union(hybrid_group_t *group1, hybrid_group_t *group2, hybrid_group_t *newgroup) {
    return MPI_Group_union(group1->mpi_group, group2->mpi_group, &newgroup->mpi_group);
    
}

int hybrid_group_intersection(hybrid_group_t *group1, hybrid_group_t *group2, hybrid_group_t *newgroup) {
    return MPI_Group_intersection(group1->mpi_group, group2->mpi_group, &newgroup->mpi_group);
    
}

int hybrid_group_include(hybrid_group_t *group, int n, int *ranks, hybrid_group_t *newgroup) {
    return MPI_Group_incl(group->mpi_group, n, ranks, &newgroup->mpi_group);
    
}

int hybrid_group_exclude(hybrid_group_t *group, int n, int *ranks, hybrid_group_t *newgroup) {
    return MPI_Group_excl(group->mpi_group, n, ranks, &newgroup->mpi_group);
    
}

int hybrid_group_range_incl(hybrid_group_t *group, int n, int ranges[][3], hybrid_group_t *newgroup) {
    return MPI_Group_range_incl(group->mpi_group, n, ranges, &newgroup->mpi_group);
    
}

int hybrid_group_range_excl(hybrid_group_t *group, int n, int ranges[][3], hybrid_group_t *newgroup) {
    return MPI_Group_range_excl(group->mpi_group, n, ranges, &newgroup->mpi_group);
    
}

int hybrid_group_from_session(hybrid_session_t *session, int n, int *ranks, hybrid_group_t *group) {
    return MPI_Group_from_session(session->mpi_session, n, ranks, &group->mpi_group);
    
}

int hybrid_group_free(hybrid_group_t *group) {
    return MPI_Group_free(&group->mpi_group);
    
}

int hybrid_comm_size(hybrid_interface_t *hybrid_root_interface, int *size) {
    return MPI_Comm_size(hybrid_root_interface->mpi_struct.comm, size);
    
}

int hybrid_comm_rank(hybrid_interface_t *hybrid_root_interface, int *rank) {
    return MPI_Comm_rank(hybrid_root_interface->mpi_struct.comm, rank);
    
}

int hybrid_comm_compare(hybrid_interface_t *hybrid_interface1, hybrid_interface_t *hybrid_interface2, int *result) {
    return MPI_Comm_compare(hybrid_interface1->mpi_struct.comm, hybrid_interface2->mpi_struct.comm, result);
    
}

int hybrid_comm_dup(hybrid_interface_t *hybrid_root_interface, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Comm_dup(hybrid_root_interface->mpi_struct.comm, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_comm_dup_with_info(hybrid_interface_t *hybrid_root_interface, hybrid_info_t *info, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Comm_dup_with_info(hybrid_root_interface->mpi_struct.comm, info->mpi_info, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_comm_idup(hybrid_interface_t *hybrid_root_interface, int *comm_id) {
    return MPI_Comm_idup(hybrid_root_interface->mpi_struct.comm, comm_id);
    
}

int hybrid_comm_idup_with_info(hybrid_interface_t *hybrid_root_interface, hybrid_info_t *info, int *comm_id) {
    return MPI_Comm_idup_with_info(hybrid_root_interface->mpi_struct.comm, info->mpi_info, comm_id);
    
}

int hybrid_comm_create(hybrid_interface_t *hybrid_root_interface, hybrid_group_t *group, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Comm_create(hybrid_root_interface->mpi_struct.comm, group->mpi_group, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_comm_create_group(hybrid_interface_t *hybrid_root_interface, hybrid_group_t *group, int tag, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Comm_create_group(hybrid_root_interface->mpi_struct.comm, group->mpi_group, tag, &new_hybrid_interface->mpi_struct.comm);
      
}

int hybrid_comm_split(hybrid_interface_t *hybrid_root_interface, int color, int key, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Comm_split(hybrid_root_interface->mpi_struct.comm, color, key, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_comm_split_type(hybrid_interface_t *hybrid_root_interface, int split_type, int key, hybrid_info_t *info, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Comm_split_type(hybrid_root_interface->mpi_struct.comm, split_type, key, info->mpi_info, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_comm_create_from_group(hybrid_group_t *group, hybrid_info_t *info, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Comm_create_from_group(group->mpi_group, info->mpi_info, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_comm_free(hybrid_interface_t *hybrid_root_interface) {
    return MPI_Comm_free(&hybrid_root_interface->mpi_struct.comm);
    
}

int hybrid_comm_set_info(hybrid_interface_t *hybrid_root_interface, hybrid_info_t *info) {
    return MPI_Comm_set_info(hybrid_root_interface->mpi_struct.comm, info->mpi_info);
    
}

int hybrid_comm_get_info(hybrid_interface_t *hybrid_root_interface, hybrid_info_t *info) {
    return MPI_Comm_get_info(hybrid_root_interface->mpi_struct.comm, &info->mpi_info);
    
}

int hybrid_comm_test_inter(hybrid_interface_t *hybrid_root_interface, int *flag) {
    return MPI_Comm_test_inter(hybrid_root_interface->mpi_struct.comm, flag);
    
}

int hybrid_comm_remote_size(hybrid_interface_t *hybrid_root_interface, int *size) {
    return MPI_Comm_remote_size(hybrid_root_interface->mpi_struct.comm, size);
    
}

int hybrid_comm_remote_group(hybrid_interface_t *hybrid_root_interface, hybrid_group_t *group) {
    return MPI_Comm_remote_group(hybrid_root_interface->mpi_struct.comm, &group->mpi_group);
    
}

int hybrid_intercomm_create(hybrid_interface_t *local_hybrid_interface, int local_leader, hybrid_interface_t *peer_hybrid_interface, int remote_leader, int tag, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Intercomm_create(local_hybrid_interface->mpi_struct.comm, local_leader, peer_hybrid_interface->mpi_struct.comm, remote_leader, tag, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_intercomm_create_from_groups(hybrid_group_t *local_group, int local_leader, hybrid_group_t *remote_group, int remote_leader, hybrid_info_t *info, int tag, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Intercomm_create_from_groups(local_group->mpi_group, local_leader, remote_group->mpi_group, remote_leader, info->mpi_info, tag, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_intercomm_merge(hybrid_interface_t *hybrid_root_interface, int high, hybrid_interface_t *new_hybrid_interface) {
    return MPI_Intercomm_merge(hybrid_root_interface->mpi_struct.comm, high, &new_hybrid_interface->mpi_struct.comm);
    
}

int hybrid_comm_create_keyvalue(hybrid_interface_t *hybrid_root_interface, int *keyval, void *attribute_val, int *flag) {
    return MPI_Comm_create_keyval(MPI_COMM_NULL_COPY_FN, MPI_COMM_NULL_DELETE_FN, keyval, attribute_val);
    
}
int hybrid_comm_set_attr(hybrid_interface_t *hybrid_root_interface, int keyval, void *attribute_val) {
    return MPI_Comm_set_attr(hybrid_root_interface->mpi_struct.comm, keyval, attribute_val);
    
}

int hybrid_comm_get_attr(hybrid_interface_t *hybrid_root_interface, int keyval, void *attribute_val, int *flag) {
    return MPI_Comm_get_attr(hybrid_root_interface->mpi_struct.comm, keyval, attribute_val, flag);
    
}

int hybrid_comm_delete_attr(hybrid_interface_t *hybrid_root_interface, int keyval) {
    return MPI_Comm_delete_attr(hybrid_root_interface->mpi_struct.comm, keyval);
    
}

int hybrid_win_create_keyvalue(int *keyval, void *attribute_val, int *flag) {
    return MPI_Win_create_keyval(MPI_WIN_NULL_COPY_FN, MPI_WIN_NULL_DELETE_FN, keyval, attribute_val);
    
}

int hybrid_win_free_keyvalue(int *keyval) {
    return MPI_Win_free_keyval(keyval);
    
}

int hybrid_win_set_attr(hybrid_win_t *win, int keyval, void *attribute_val) {
    return MPI_Win_set_attr(win->mpi_win, keyval, attribute_val);
    
}

int hybrid_win_get_attr(hybrid_win_t *win, int keyval, void *attribute_val, int *flag) {
    return MPI_Win_get_attr(win->mpi_win, keyval, attribute_val, flag);
    
}

int hybrid_win_delete_attr(hybrid_win_t *win, int keyval) {
    return MPI_Win_delete_attr(win->mpi_win, keyval);
    
}

int hybrid_type_create_keyvalue(int *keyval, void *attribute_val, int *flag) {
    return MPI_Type_create_keyval(MPI_TYPE_NULL_COPY_FN, MPI_TYPE_NULL_DELETE_FN, keyval, attribute_val);
    
}

int hybrid_type_free_keyvalue(int *keyval) {
    return MPI_Type_free_keyval(keyval);
    
}

int hybrid_type_set_attr(hybrid_datatype_t *type, int keyval, void *attribute_val) {
    return MPI_Type_set_attr(type->mpi_type, keyval, attribute_val);
    
}

int hybrid_type_get_attr(hybrid_datatype_t *type, int keyval, void *attribute_val, int *flag) {
    return MPI_Type_get_attr(type->mpi_type, keyval, attribute_val, flag);
    
}

int hybrid_type_delete_attr(hybrid_datatype_t *type, int keyval) {
    return MPI_Type_delete_attr(type->mpi_type, keyval);
    
}

int hybrid_comm_set_name(hybrid_interface_t *hybrid_root_interface, const char *comm_name) {
    return MPI_Comm_set_name(hybrid_root_interface->mpi_struct.comm, comm_name);
    
}

int hybrid_comm_get_name(hybrid_interface_t *hybrid_root_interface, char *comm_name, int *resultlen) {
    return MPI_Comm_get_name(hybrid_root_interface->mpi_struct.comm, comm_name, resultlen);
    
}
int hybrid_type_set_name(hybrid_datatype_t *type, const char *type_name) {
    return MPI_Type_set_name(type->mpi_type, type_name);
    
}

int hybrid_type_get_name(hybrid_datatype_t *type, char *type_name, int *resultlen) {
    return MPI_Type_get_name(type->mpi_type, type_name, resultlen);
    
}
int hybrid_win_set_name(hybrid_win_t *win, const char *win_name) {
    return MPI_Win_set_name(win->mpi_win, win_name);
    
}

int hybrid_win_get_name(hybrid_win_t *win, char *win_name, int *resultlen) {
    return MPI_Win_get_name(win->mpi_win, win_name, resultlen);
    
}


