#include <stdio.h>
#include <stdlib.h>

typedef struct successors {
    int id;
    struct successors *next;
}successor;

typedef struct graph {
    int id;
    successor *first_successor;
    struct graph *next_node;
}graph;

graph *graph_init(void);

void graph_print(graph *g);

void graph_free(graph *g);

graph *graph_search_node(graph *g, int x);
successor *graph_search_edge(graph *g, int node1, int node2);

graph *graph_insert_node(graph *g, int x);
void graph_insert_edge(graph *g, int node1, int node2);

graph *graph_delete_node(graph *g, int node);
void graph_delete_edge(graph *g, int node1, int node2);