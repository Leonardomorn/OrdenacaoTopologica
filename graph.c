#include "graph.h"



void convert_into_adjacency(Agnode_t *node, Agraph_t *graph, int **adjacencyMatrix, int num_nodes)
{
        for (node = agfstnode(graph); node; node = agnxtnode(graph, node)) {
        int sourceIndex = agnameof(node)[0] - 'A';  // Adjust as per your node naming convention
        Agnode_t *targetNode;
        Agedge_t *edge;
        for (edge = agfstout(graph, node); edge; edge = agnxtout(graph, edge)) {
            targetNode = aghead(edge);
            int targetIndex = agnameof(targetNode)[0] - 'A';  // Adjust as per your node naming convention
            adjacencyMatrix[sourceIndex][targetIndex] = 1;
        }
    }
    
}

void print_matrix(int **matrix_adjacency, int num_nodes)
{
    printf("   ");
    for (int i = 0; i < num_nodes; i++)
    {
        printf("%c ", i + 'A');   
    }
    printf("\n___");

    for (int i = 0; i < num_nodes; i++)
    {
        printf("__");
    }
    printf("\n");
    

    
    for (int i = 0; i < num_nodes; i++)
    {
        printf("%c |", i + 'A');
        for (size_t j = 0; j < num_nodes; j++)
        {
            printf("%d ",matrix_adjacency[i][j]);
        }
        printf("\n");      
    }
    
}


void toposort (int num_nodes, int** matrix_adjacency, int* states, pros_stack_t* processed)
{
    //make it zero the state of all nodes
    for (int i = 0; i < num_nodes; i++)
        states[i] = 0;
    
    for (int i = 0; i < num_nodes; i++)
    {
        if(states[i] == 0)
        {
            sort(matrix_adjacency, i, states, processed, num_nodes);
        }

    }

}

void sort(int ** matrix_adjacency, int source, int* states,
 pros_stack_t* processed, int num_nodes)
{
    states[source] = 1;
    for (int target = 0; target<num_nodes; target++)
    {
        if(matrix_adjacency[source][target] == 1)
        {
            if (states[target] == 0)
            {
                sort(matrix_adjacency, target, states, processed, num_nodes);        
            }
            if(states[target] == 1)
            {
                printf("erro: grafo é cíclico");
                exit(-1);
            }
        }
    }

    push(processed, source);
    
    states[source] = 2;
}

pros_stack_t* createStack(int capacity) 
{
    pros_stack_t* stack = (pros_stack_t*)malloc(sizeof(pros_stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(pros_stack_t* stack) 
{
    return stack->top == -1;
}

int isFull(pros_stack_t* stack) 
{
    return stack->top == stack->capacity - 1;
}

void push(pros_stack_t* stack, int item)
{
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(pros_stack_t* stack) 
{
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(pros_stack_t* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek element.\n");
        return -1;
    }
    return stack->array[stack->top];
}

void freeStack(pros_stack_t* stack)
 {
    free(stack->array);
    free(stack);
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d",array[i]);
    printf("\n");
    
}
