#include "mpi.h"
#include "omp.h"
#include "../include/structs.h"
#include "hybrid_structure.h"


int hybrid_init(int *argc, char ***argv, hybrid_node_object *root) {
    int provided;
    MPI_Init_thread(NULL, NULL, MPI_THREAD_MULTIPLE, &provided);
    if (provided < MPI_THREAD_MULTIPLE) {
        printf("The MPI library does not have full thread support\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int thread_count = omp_get_max_threads();
    int thread_id;

    // Print the rank and thread information
    #pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();
        printf("Hello from process %d of %d, thread %d of %d\n", rank, size, thread_id, thread_count);
    }

    hybrid_node_object *hybrid_root;
    hybrid_root = (hybrid_node_object *)malloc(sizeof(hybrid_node_object));
    hybrid_root->node_type = "ROOT";
    hybrid_root->size = 1;
    hybrid_root->object_container[0] = rank;
    hybrid_root->mpi_struct.comm = MPI_COMM_WORLD;
    hybrid_root->thread_size = thread_count;
    hybrid_root->process_size = size;
    create_hybrid_linked_list(&root);


    hybrid_node_object *process_node;
    process_node = (hybrid_node_object *)malloc(sizeof(hybrid_node_object));
    process_node->node_type = "PROCESSES";
    process_node->hybrid_root = hybrid_root;
    process_node->size = size;
    add_hybrid_node(&hybrid_root, process_node);
   


    hybrid_node_object *teams;
    teams = (hybrid_node_object *)malloc(sizeof(hybrid_node_object));
    teams->node_type = "TEAMS";
    teams->hybrid_root = hybrid_root;
    teams.size = 1; // For now, we have only one team per process
    add_hybrid_node(&process_node, teams);



    hybrid_node_object *threads;
    threads = (hybrid_node_object *)malloc(sizeof(hybrid_node_object));
    threads->node_type = "THREADS";
    threads->hybrid_root = hybrid_root;
    threads->size = thread_count;
    threads->object_container[0] = thread_id;
    add_hybrid_node(&teams, threads);



    hybrid_node_object *tasks;
    tasks = (hybrid_node_object *)malloc(sizeof(hybrid_node_object));
    tasks->node_type = "TASKS";
    tasks->hybrid_root = hybrid_root;
    tasks->size = 0; // Initialize with zero tasks
    add_hybrid_node(&threads, tasks);



    hybrid_node_object *simd;
    simd = (hybrid_node_object *)malloc(sizeof(hybrid_node_object));
    simd->node_type = "SIMD";
    simd->hybrid_root = hybrid_root;
    simd->size = 0; // Initialize with zero SIMD lanes
    add_hybrid_node(&tasks, simd);

    return 0;
}

int hybrid_init_thread(int required, int *provided) {
    MPI_Init_thread(NULL, NULL, required, provided);
    if (*provided < required) {
        printf("The MPI library does not have the required thread support\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    return 0;
}

int hybrid_query_thread(int *provided) {
    int thread_support;
    MPI_Query_thread(&thread_support);
    *provided = thread_support;
    return 0;
}

int hybrid_session_init(hybrid_info_t *info, hybrid_session_t *session) {
    return MPI_Session_init(info->mpi_info, MPI_ERRORS_RETURN, &session->mpi_session);
}

int hybrid_session_finalize(hybrid_session_t *session) {
    return MPI_Session_finalize(&session->mpi_session);
}

int hybrid_session_get_num_psets(hybrid_session_t *session, const char *pset_name, int *num_psets) {
    return MPI_Session_get_num_psets(session->mpi_session, pset_name, num_psets);
}

int hybrid_session_get_nth_pset(hybrid_session_t *session, int n, char *pset_name, int *resultlen) {
    return MPI_Session_get_nth_pset(session->mpi_session, n, pset_name, resultlen);
}

int hybrid_session_get_info(hybrid_session_t *session, hybrid_info_t *info) {
    return MPI_Session_get_info(session->mpi_session, &info->mpi_info);
}

int hybrid_session_get_pset_info(hybrid_session_t *session, const char *pset_name, hybrid_info_t *info) {
    return MPI_Session_get_pset_info(session->mpi_session, pset_name, &info->mpi_info);
}

int hybrid_abort(hybrid_interface_t *hybrid_root_interface, int errorcode) {
    return MPI_Abort(hybrid_root_interface->mpi_struct.comm, errorcode);
}

int hybrid_finalized(int *flag) {
    int finalized;
    MPI_Finalized(&finalized);
    *flag = finalized;
    return 0;
}

int hybrid_finalise() {
    MPI_Finalize();
    return 0;
}