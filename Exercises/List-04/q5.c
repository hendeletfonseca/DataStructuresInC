#include "../../Structs/graph/graph.h"

int equal(graph *g1, graph *g2) {
    graph *aux_node1 = g1, *aux_node2 = g2;
    while (aux_node1 && aux_node2) {
        successor *s1 = aux_node1->first_successor, *s2 = aux_node2->first_successor;
        while (s1 || s2) {
            if (!s1 || !s2) return 0;
            if (s1->id != s2->id) return 0;
            s1 = s1->next;
            s2 = s2->next;
        }
        aux_node1 = aux_node1->next_node;
        aux_node2 = aux_node2->next_node;
    }
    if (aux_node1 || aux_node2) return 0;
    return 1;
}