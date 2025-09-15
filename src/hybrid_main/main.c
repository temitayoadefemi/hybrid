#include "mpi.h"
#include "omp.h"
#include "../include/structs.h"
#include "hybrid_structure.h"


int hybrid_init() {
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


int hybrid_finalise() {
    MPI_Finalize();
    return 0;
}