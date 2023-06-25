#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>
#include <graphviz/cdt.h>
#include "graph.h"
int main()
{

    Agraph_t *graph = agread(stdin, NULL);


    //the number of nodes
    int numNodes = agnnodes(graph);
    int* states = calloc(numNodes, sizeof(int));
    pros_stack_t* processed = createStack(numNodes);

    
    int **adjacencyMatrix = (int **)calloc(numNodes, sizeof(node_t *));
    for (int i = 0; i < numNodes; i++) {
        adjacencyMatrix[i] = (int *)calloc(numNodes, sizeof(int));
    }

    Agnode_t *node;

    convert_into_adjacency(node, graph, adjacencyMatrix, numNodes);
    toposort(numNodes, adjacencyMatrix, states, processed);
    

    for (int i = 0; i < numNodes; i++)
    {
        int vertice = pop(processed);
        printf("%d ", vertice);

    }
    printf("\n");


    return 0;
}



//criar uma pilha para guardar os já processados

