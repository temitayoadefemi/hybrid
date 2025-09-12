#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


#define HYBRID_ARRAY[6] = { "ROOT", "PROCESSES", "TEAMS" , "THREADS", "TASKS", "SIMD"};


typedef struct node {
    struct node *next;
    char *node_type;
} node;


node *root;


node create_hybrid_linked_list(node **root) {
    *root = (node *)malloc(sizeof(node));
    (*root)->next = NULL;
    (*root)->hybrid_level = NULL;
    (*root)->node_type = (char *)malloc(20 * sizeof(char));

    (*root)->node_type = "hybrid_root";

    return (*root);
}


int add_hybrid_node(node *root, node *new_node) {
    node *current = root;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->next = NULL;
    return 1;
}


int find_node(node *root, char *node_type) {
    node *current = root;
    while (current != NULL) {
        if (strcmp(current->node_type, node_type) == 0) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}
