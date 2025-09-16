#include "mpi.h"
#include <stdio.h>
#include "structs.h"


int hybrid_grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, hybrid_request_t *request) {
    return MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request);
    
}

int hybrid_grequest_complete(hybrid_request_t *request) {
    return MPI_Grequest_complete(request);
    
}

int hybrid_status_set_elements(hybrid_status_t *status, hybrid_datatype_t *datatype, int count) {
    return MPI_Status_set_elements(&status->mpi_status, datatype->mpi_type, count);
    
}

int hybrid_status_set_elements_c(hybrid_status_t *status, hybrid_datatype_t *datatype, int count) {
    return MPI_Status_set_elements(&status->mpi_status, datatype->mpi_type, count);
    
}

int hybrid_status_set_cancelled(hybrid_status_t *status, int flag) {
    return MPI_Status_set_cancelled(&status->mpi_status, flag);
    
}

int hybrid_status_set_source(hybrid_status_t *status, int source) {
    return MPI_Status_set_source(&status->mpi_status, source);
    
}

int hybrid_status_set_tag(hybrid_status_t *status, int tag) {
    return MPI_Status_set_tag(&status->mpi_status, tag);
    
}

int hybrid_file_open(hybrid_interface_t *hybrid_root_interface, char *filename, int amode, hybrid_info_t *info, hybrid_file_t *fh) {
    return MPI_File_open(hybrid_root_interface->mpi_struct.comm, filename, amode, info->mpi_info, &fh->mpi_file);
    
}

int hybrid_file_close(hybrid_file_t *fh) {
    return MPI_File_close(&fh->mpi_file);
    
}

int hybrid_file_delete(char *filename, hybrid_info_t *info) {
    return MPI_File_delete(filename, info->mpi_info);
    
}

int hybrid_file_set_size(hybrid_file_t *fh, hybrid_offset_t size) {
    return MPI_File_set_size(fh->mpi_file, size.mpi_offset);
    
}

int hybrid_file_preallocate(hybrid_file_t *fh, hybrid_offset_t size) {
    return MPI_File_preallocate(fh->mpi_file, size.mpi_offset);
    
}

int hybrid_file_get_size(hybrid_file_t *fh, hybrid_offset_t *size) {
    MPI_Offset mpi_size;
    int ret = MPI_File_get_size(fh->mpi_file, &mpi_size);
    size->mpi_offset = mpi_size;
    return ret;
    
}

int hybrid_get_group(hybrid_interface_t *hybrid_root_interface, hybrid_group_t *group) {
    return MPI_Comm_group(hybrid_root_interface->mpi_struct.comm, &group->mpi_group);
    
}

int hybrid_get_amode(hybrid_file_t *fh, int *amode) {
    return MPI_File_get_amode(fh->mpi_file, amode);
    
}

int hybrid_file_set_info(hybrid_file_t *fh, hybrid_info_t *info) {
    return MPI_File_set_info(fh->mpi_file, info->mpi_info);
    
}

int hybrid_file_get_info(hybrid_file_t *fh, hybrid_info_t *info) {
    return MPI_File_get_info(fh->mpi_file, &info->mpi_info);
    
}

int hybrid_file_set_view(hybrid_file_t *fh, hybrid_offset_t disp, hybrid_datatype_t *etype, hybrid_datatype_t *filetype, char *datarep, hybrid_info_t *info) {
    return MPI_File_set_view(fh->mpi_file, disp.mpi_offset, etype->mpi_type, filetype->mpi_type, datarep, info->mpi_info);
    
}

int hybrid_file_get_view(hybrid_file_t *fh, hybrid_offset_t *disp, hybrid_datatype_t *etype, hybrid_datatype_t *filetype, char *datarep) {
    MPI_Offset mpi_disp;
    int ret = MPI_File_get_view(fh->mpi_file, &mpi_disp, &etype->mpi_type, &filetype->mpi_type, datarep);
    disp->mpi_offset = mpi_disp;
    return ret;
    
}

int hybrid_file_read_at(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_at_c(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_at_all(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_at_all_c(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_at(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_at_c(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_at_all(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_at_all_c(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_iread_at(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_at_c(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_at(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_at_c(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_write_at_all(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_iwrite_at_all(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_at(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_at_c(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_at_all(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_at_all_c(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_at(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}
int hybrid_file_iwrite_at_c(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_at(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_at_all(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_at_all_c(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_at_all(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_read(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_all(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_all(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_all_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_all(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_all(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_all(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_all_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_all(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_iread(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_all(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_all(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_all_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_all(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_all(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_all(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_all_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_all(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_seek(hybrid_file_t *fh, hybrid_offset_t offset, int whence) {
    return MPI_File_seek(fh->mpi_file, offset.mpi_offset, whence);
    
}

int hybrid_file_get_position(hybrid_file_t *fh, hybrid_offset_t *offset) {
    MPI_Offset mpi_offset;
    int ret = MPI_File_get_position(fh->mpi_file, &mpi_offset);
    offset->mpi_offset = mpi_offset;
    return ret;
    
}

int hybrid_file_get_byte_offset(hybrid_file_t *fh, hybrid_offset_t offset, hybrid_aint_t *disp) {
    return MPI_File_get_byte_offset(fh->mpi_file, offset.mpi_offset, disp);
    
}

int hybrid_file_read_shared(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_shared(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_shared_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_shared(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_shared(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_shared(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_shared_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_shared(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_iread_shared(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_shared(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iread_shared_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iread_shared(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_shared(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_shared(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_iwrite_shared_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_request_t *request) {
    return MPI_File_iwrite_shared(fh->mpi_file, buf, count, datatype->mpi_type, &request->mpi_request);
    
}

int hybrid_file_read_ordered(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_ordered(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_read_ordered_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_read_ordered(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_write_ordered(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_ordered(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}
int hybrid_file_write_ordered_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype, hybrid_status_t *status) {
    return MPI_File_write_ordered(fh->mpi_file, buf, count, datatype->mpi_type, &status->mpi_status);
    
}

int hybrid_file_seek_shared(hybrid_file_t *fh, hybrid_offset_t offset, int whence) {
    return MPI_File_seek_shared(fh->mpi_file, offset.mpi_offset, whence);
    
}

int hybrid_file_get_position_shared(hybrid_file_t *fh, hybrid_offset_t *offset) {
    MPI_Offset mpi_offset;
    int ret = MPI_File_get_position_shared(fh->mpi_file, &mpi_offset);
    offset->mpi_offset = mpi_offset;
    return ret;
    
}


int hybrid_file_read_at_all_begin(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_read_at_all_begin(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type);
    
}

int hybrid_file_read_at_all_begin_c(hybrid_file_t *fh, hybrid_offset_t offset, void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_read_at_all_begin(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type);
    
}

int hybrid_file_read_at_all_end(hybrid_file_t *fh, void *buf, hybrid_status_t *status) {
    return MPI_File_read_at_all_end(fh->mpi_file, buf, &status->mpi_status);
    
}

int hybrid_file_read_at_all_end_c(hybrid_file_t *fh, void *buf, hybrid_status_t *status) {
    return MPI_File_read_at_all_end(fh->mpi_file, buf, &status->mpi_status);
    
}


int hybrid_file_read_all_begin(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_read_all_begin(fh->mpi_file, buf, count, datatype->mpi_type);
    
}

int hybrid_file_read_all_begin_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_read_all_begin(fh->mpi_file, buf, count, datatype->mpi_type);
    
}

int hybrid_file_read_all_end(hybrid_file_t *fh, void *buf, hybrid_status_t *status) {
    return MPI_File_read_all_end(fh->mpi_file, buf, &status->mpi_status);
    
}

int hybrid_file_read_all_end_c(hybrid_file_t *fh, void *buf, hybrid_status_t *status) {
    return MPI_File_read_all_end(fh->mpi_file, buf, &status->mpi_status);
    
}

int hybrid_file_write_at_all_begin(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_write_at_all_begin(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type);
    
}

int hybrid_file_write_at_all_begin_c(hybrid_file_t *fh, hybrid_offset_t offset, const void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_write_at_all_begin(fh->mpi_file, offset.mpi_offset, buf, count, datatype->mpi_type);
    
}

int hybrid_file_write_all_end(hybrid_file_t *fh, const void *buf, hybrid_status_t *status) {
    return MPI_File_write_all_end(fh->mpi_file, buf, &status->mpi_status);
    
}

int hybrid_file_read_ordered_begin(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_read_ordered_begin(fh->mpi_file, buf, count, datatype->mpi_type);
    
}

int hybrid_file_read_ordered_begin_c(hybrid_file_t *fh, void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_read_ordered_begin(fh->mpi_file, buf, count, datatype->mpi_type);
    
}

int hybrid_file_read_ordered_end(hybrid_file_t *fh, void *buf, hybrid_status_t *status) {
    return MPI_File_read_ordered_end(fh->mpi_file, buf, &status->mpi_status);
    
}

int hybrid_file_write_ordered_begin(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_write_ordered_begin(fh->mpi_file, buf, count, datatype->mpi_type);
    
}

int hybrid_file_write_ordered_begin_c(hybrid_file_t *fh, const void *buf, int count, hybrid_datatype_t *datatype) {
    return MPI_File_write_ordered_begin(fh->mpi_file, buf, count, datatype->mpi_type);
    
}

int hybrid_file_write_ordered_end(hybrid_file_t *fh, const void *buf, hybrid_status_t *status) {
    return MPI_File_write_ordered_end(fh->mpi_file, buf, &status->mpi_status);
    
}

int hybrid_file_get_type_extent(hybrid_file_t *fh, hybrid_datatype_t *datatype, hybrid_aint_t *extent) {
    return MPI_File_get_type_extent(fh->mpi_file, datatype->mpi_type, extent);
    
}

int hybrid_file_get_type_extent_c(hybrid_file_t *fh, hybrid_datatype_t *datatype, int *extent) {
    return MPI_File_get_type_extent(fh->mpi_file, datatype->mpi_type, extent);
    
}

int hybrid_register_datarep(char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
    return MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
    
}

int hybrid_register_datarep_c(char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
    return MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
    
}

int hybrid_file_set_atomicity(hybrid_file_t *fh, int atomicity) {
    return MPI_File_set_atomicity(fh->mpi_file, atomicity);
    
}

int hybrid_file_get_atomicity(hybrid_file_t *fh, int *atomicity) {
    return MPI_File_get_atomicity(fh->mpi_file, atomicity);
    
}

int hybrid_file_sync(hybrid_file_t *fh) {
    return MPI_File_sync(fh->mpi_file);
    
}

int hybrid_pcontrol(int level, ...) {
    return MPI_Pcontrol(level);
    
}

int hybrid_t_init_thread(int *required, int *provided) {
    return MPI_T_init_thread(required, provided);
    
}

int hybrid_t_finalize() {
    return MPI_T_finalize();
    
}

int hybrid_t_enum_get_item(MPI_T_enum enumtype, int index, int *value) {
    return MPI_T_enum_get_item(enumtype, index, value);
    
}

int hybrid_t_cvar_get_num(int *num_cvar) {
    return MPI_T_cvar_get_num(num_cvar);
    
}

int hybrid_t_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, int *datatype, int *enumtype, char *desc, int *desc_len, int *bind, int *scope) {
    return MPI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, scope);
    
}

int hybrid_t_get_index(char *name, int *index) {
    return MPI_T_get_index(name, index);
    
}

int hybrid_t_cvar_handle_alloc(int cvar_index, void *obj, MPI_T_cvar_handle *handle, int *count) {
    return MPI_T_cvar_handle_alloc(cvar_index, obj, handle, count);
    
}

int hybrid_t_cvar_read(MPI_T_cvar_handle handle, void *buf) {
    return MPI_T_cvar_read(handle, buf);
    
}

int hybrid_t_pvar_get_num(int *num_pvar) {
    return MPI_T_pvar_get_num(num_pvar);
    
}

int hybrid_t_pvar_get_index(char *name, int *index) {
    return MPI_T_pvar_get_index(name, index);
    
}

int hybrid_t_pvar_session_create(MPI_T_pvar_session *session) {
    return MPI_T_pvar_session_create(session);
    
}

int hybrid_t_pvar_session_free(MPI_T_pvar_session *session) {
    return MPI_T_pvar_session_free(session);
    
}

int hybrid_t_pvar_handle_alloc(int pvar_index, MPI_T_pvar_session session, void *obj, MPI_T_pvar_handle *handle, int *count) {
    return MPI_T_pvar_handle_alloc(pvar_index, session, obj, handle, count);
    
}

int hybrid_t_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle) {
    return MPI_T_pvar_handle_free(session, handle);
    
}

int hybrid_t_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle) {
    return MPI_T_pvar_start(session, handle);
    
}

int hybrid_t_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle) {
    return MPI_T_pvar_stop(session, handle);
    
}

int hybrid_t_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) {
    return MPI_T_pvar_read(session, handle, buf);
    
}

int hybrid_t_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, const void *buf) {
    return MPI_T_pvar_write(session, handle, buf);
    
}


int hybrid_t_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle) {
    return MPI_T_pvar_reset(session, handle);
    
}

int hybrid_t_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) {
    return MPI_T_pvar_readreset(session, handle, buf);
    
}

int hybrid_t_source_get_info(char *name, int *name_len, int *verbosity, char *desc, int *desc_len) {
    return MPI_T_source_get_info(name, name_len, verbosity, desc, desc_len);
    
}

int hybrid_t_source_get_timestamp(int *timestamp) {
    return MPI_T_source_get_timestamp(timestamp);
    
}

int hybrid_t_event_get_info(int event_index, char *name, int *name_len, int *verbosity, char *desc, int *desc_len, int *num_states, int *bind) {
    return MPI_T_event_get_info(event_index, name, name_len, verbosity, desc, desc_len, num_states, bind);
    
}

int hybrid_t_event_get_index(char *name, int *index) {
    return MPI_T_event_get_index(name, index);
    
}

int hybrid_t_event_handle_alloc(int event_index, MPI_T_event_handle *handle) {
    return MPI_T_event_handle_alloc(event_index, handle);
    
}

int hybrid_t_event_handle_set_info(MPI_T_event_handle handle, int state) {
    return MPI_T_event_handle_set_flow(handle, state);
    
}

int hybrid_t_event_handle_get_info(MPI_T_event_handle handle, int *state) {
    return MPI_T_event_handle_get_info(handle, state);
    
}

int hybrid_t_event_register_callback(MPI_T_event_handle handle, MPI_T_event_callback_function *callback, void *client_data) {
    return MPI_T_event_register_callback(handle, callback, client_data);
    
}

int hybrid_t_event_handle_free(MPI_T_event_handle *handle) {
    return MPI_T_event_handle_free(handle);
    
}

int hybrid_t_event_set_dropped_handler(MPI_T_event_dropped_function *callback) {
    return MPI_T_event_set_dropped_handler(callback);
    
}

int hybrid_t_event_read(MPI_T_event_handle handle, int *num_events, int *total_events, void *event_data) {
    return MPI_T_event_read(handle, num_events, total_events, event_data);
    
}

int hybrid_t_event_copy(MPI_T_event_handle handle, MPI_T_event_handle *newhandle) {
    return MPI_T_event_copy(handle, newhandle);
    
}

int hybrid_t_event_get_timestamp(int *timestamp) {
    return MPI_T_event_get_timestamp(timestamp);
    
}

int hybrid_t_event_get_source(int *source) {
    return MPI_T_event_get_source(source);
    
}

int hybrid_t_category_get_num(int *num_categories) {
    return MPI_T_category_get_num(num_categories);
    
}

int hybrid_t_category_get_info(int category_index, char *name, int *name_len, int *verbosity, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_events) {
    return MPI_T_category_get_info(category_index, name, name_len, verbosity, desc, desc_len, num_cvars, num_pvars, num_events);
    
}

int hybrid_t_category_get_num_events(int category_index, int *num_events) {
    return MPI_T_category_get_num_events(category_index, num_events);
    
}

int hybrid_t_category_get_index(char *name, int *index) {
    return MPI_T_category_get_index(name, index);
    
}

int hybrid_t_category_get_cvars(int category_index, int *cvar_indices, int len) {
    return MPI_T_category_get_cvars(category_index, cvar_indices, len);
    
}

int hybrid_t_category_get_pvars(int category_index, int *pvar_indices, int len) {
    return MPI_T_category_get_pvars(category_index, pvar_indices, len);
    
}

int hybrid_t_category_get_events(int category_index, int *event_indices, int len) {
    return MPI_T_category_get_events(category_index, event_indices, len);
    
}

int hybrid_t_category_get_categories(int category_index, int *category_indices, int len) {
    return MPI_T_category_get_categories(category_index, category_indices, len);
    
}

int hybrid_t_category_changed(int *update_number) {
    return MPI_T_category_changed(update_number);
    
}

int hybrid_t_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *datatype, int *enumtype, char *desc, int *desc_len, int *bind, int *readonly, int *continuous, int *atomic) {
    return MPI_T_pvar_get_info(pvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, bind, readonly, continuous, atomic);
    
}

int hybrid_t_query_thread(int *provided) {
    return MPI_T_query_thread(provided);
    
}

