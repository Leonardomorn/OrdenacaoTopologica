#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>
#include <graphviz/cdt.h>

// typedef struct node_t
// {
//     char name [256];
//     int state;
//     struct node_t *
// }node_t

typedef struct pros_stack_t {
    int capacity;
    int top;
    int* array;
} pros_stack_t;

void print_matrix(int **matrix_adjacency, int num_nodes);
void convert_into_adjacency(Agnode_t *node, Agraph_t *graph, int **adjacencyMatrix, int num_nodes);
void toposort (int num_nodes, int** matrix_adjacency, int* states, pros_stack_t* processed);
void sort(int ** matrix_adjacency, int source, int* states,
 pros_stack_t* processed, int num_nodes);

pros_stack_t* createStack(int capacity);
int isEmpty(pros_stack_t* stack) ;
int isFull(pros_stack_t* stack) ;
void push(pros_stack_t* stack, int item);
int pop(pros_stack_t* stack);
int peek(pros_stack_t* stack);
void freeStack(pros_stack_t* stack);
void print_array(int* array, int size);


