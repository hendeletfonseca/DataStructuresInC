#include "graph.h"

graph *graph_init(void) {
    return NULL;
}

void graph_print(graph *g) {
    while (g) {
        printf("%d -> ", g->id);
        successor *s = g->first_successor;
        while (s) {
            printf("%d ", s->id);
            s = s->next;
        }
        printf("\n");
        g = g->next_node;
    }
}

void free_successor(successor *s) {
    while (s) {
        successor *temp = s;
        s = s->next;
        free(temp);
    }
}
void graph_free(graph *g) {
    while (g) {
        free_successor(g->first_successor);
        graph *temp = g;
        g = g->next_node;
        free(temp);
    }
}

graph *graph_search_node(graph *g, int x) {
    if ((!g) || (g->id == x)) return g;
    return (graph_search_node(g->next_node, x));
}
successor *graph_search_edge(graph *g, int node1, int node2) {
    graph *n1 = graph_search_node(g, node1), *n2 = graph_search_node(g, node2);
    if ((!n1) || (!n2)) return NULL;
    successor *answer = n1->first_successor;
    while ((answer) && (answer->id != node2)) answer = answer->next;
    return answer;
}

graph *graph_insert_node(graph *g, int x) {
    graph *new = graph_search_node(g,x);
    if (new) return g;
    new = (graph *) malloc(sizeof(graph));
    new->id = x;
    new->next_node = g;
    new->first_successor = NULL;
    return new;
}
void aux_insert_edge(graph *g, int node1, int node2) {
    graph *node = graph_search_node(g, node1);
    if (!node) return;
    successor *new = (successor *) malloc(sizeof(successor));
    new->id = node2;
    new->next = node->first_successor;
    node->first_successor = new;
}
void graph_insert_edge(graph *g, int node1, int node2) {
    successor *s = graph_search_edge(g, node1, node2);
    if (s) return;
    aux_insert_edge(g,node1,node2);
    aux_insert_edge(g,node2,node1);
}

void aux_remove_edge(graph *g, int node1, int node2) {
    graph *node = graph_search_node(g, node1);
    if (!node) return;
    successor *previous = NULL, *current = node->first_successor;
    while ((current) && (current->id != node2)) {
        previous = current;
        current = current->next;
    }
    if (!previous) node->first_successor = current->next;
    else previous->next = current->next;
    free(current);
}
void graph_delete_edge(graph *g, int node1, int node2) {
    successor *s = graph_search_edge(g, node1, node2);
    if (!s) return;
    aux_remove_edge(g, node1, node2);
    aux_remove_edge(g, node2, node1);
}

graph *graph_delete_node(graph *g, int node) {
    graph *current = g, *previous = NULL;
    while ((current) && (current->id != node)) {
        previous = current;
        current = current->next_node;
    }
    if (!current) return g;
    while (current->first_successor) graph_delete_edge(g, node, current->first_successor->id);
    if (!previous) g = g->next_node;
    else previous->next_node = current->next_node;
    free(current);
    return g;
}