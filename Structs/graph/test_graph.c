#include "graph.h"

int main(void) {
    
    graph *graph = graph_init();
    int node;
    printf("Type Graph Nodes (to stop type -1)\n");
    while (1) {
        scanf("%d", &node);
        if (node == -1) break;
        graph = graph_insert_node(graph, node);
    }
    graph_print(graph);

    int edge;
    printf("Type Node and Edge (to stop type -1 -1)\n");
    while (1) {
        scanf("%d %d", &node, &edge);
        if ((node == -1) || (edge == -1)) break;
        graph_insert_edge(graph, node, edge);
    }
    graph_print(graph);

    char operator;
    printf("Type N to remove node or E to remove Edge\n");
    while (1) {
        scanf(" %c", &operator);
        if ((operator == 'n') || (operator == 'N')) {
            printf("Enter the node to be removed\n");
            scanf("%d", &node);
            graph = graph_delete_node(graph, node);
            graph_print(graph);
        }
        else if ((operator == 'e') || (operator == 'E')) {
            printf("Enter the node and edge to be removed\n");
            scanf("%d %d", &node, &edge);
            graph_delete_edge(graph, node, edge);
            graph_print(graph);
        }
        else break;
    }
    printf("\n");
    graph_print(graph);
    return 0;
}