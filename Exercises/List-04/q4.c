#include "../../Structs/graph/graph.h"

int testk(graph *g, int k) {
    graph *aux_node = g;
    while (aux_node) {
        int qtd = 0;
        successor *aux_edge = g->first_successor;
        while(aux_edge) {
            qtd++;
            aux_edge = aux_edge->next;
        }
        if (qtd != k) return 0;
        aux_node = aux_node->next_node;
    }
    return 1;
}