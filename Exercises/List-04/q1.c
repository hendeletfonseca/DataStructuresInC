#include "../../Structs/graph/graph.h"

int qtd_internal_nodes(graph *g) {
    if (!g) return 0;
    int qtd = 0;
    graph *aux = g;
    while (aux) {
        qtd++;
        aux = aux->next_node;
    }
    return qtd;
}