#include "../../Structs/graph/graph.h"

int qtd_edges(graph *g) {
    if (!g) return 0;
    int qtd = 0;
    graph *aux_node = g;
    successor *aux_edge;
    while (aux_node) {
        aux_edge = aux_node->first_successor;
        while (aux_edge) {
            qtd++;
            aux_edge = aux_edge->next;
        }
        aux_node = aux_node->next_node;
    }
    return qtd;
}