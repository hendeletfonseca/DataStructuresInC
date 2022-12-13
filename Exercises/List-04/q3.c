#include "../../Structs/graph/graph.h"

int not_same_color(graph *g) {
    if (!g) return 1;
    graph *aux = g;
    while (aux->next_node) {
        if (!((aux->id) == (aux->next_node->id))) return 0;
        aux = aux->next_node;
    }
    return 1;
}