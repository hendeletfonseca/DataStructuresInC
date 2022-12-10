#include "binarySearchTree.h"

binarySearchTree *binarySearchTree_init(void) {
    return NULL;
}
binarySearchTree *binarySearchTree_create(int root, binarySearchTree *left, binarySearchTree *right) {
    binarySearchTree *new = (binarySearchTree *)malloc(sizeof(binarySearchTree));
    new->data = root;
    new->left = left;
    new->right = right;
    return new;
}

void binarySearchTree_print_pre(binarySearchTree *node){
    if (!node) return;
    printf("%d ", node->data);
    binarySearchTree_print_pre(node->left);
    binarySearchTree_print_pre(node->right);
}
void binarySearchTree_print_pos(binarySearchTree *node) {
    if (!node) return;
    binarySearchTree_print_pre(node->left);
    binarySearchTree_print_pre(node->right);
    printf("%d ", node->data);
}
void binarySearchTree_print_sim(binarySearchTree *node) {
    if (!node) return;
    binarySearchTree_print_pre(node->left);
    printf("%d ", node->data);
    binarySearchTree_print_pre(node->right);
}
void print_aux(binarySearchTree *node, int floor) {
    int j;
    if (node) {
        print_aux(node->left, floor + 1);
        for(j = 0; j <= floor; j++) printf("\t");
        printf("%d\n", node->data);
        print_aux(node->right, floor + 1);
    }
    else {
        for(j = 0; j <= floor; j++) printf("\t");
        printf("N\n");
    }
}
void binarySearchTree_print_ident(binarySearchTree *node) {
    print_aux(node, 0);
}

void binarySearchTree_free(binarySearchTree *node) {
    if (!node) return;
    binarySearchTree_free(node->left);
    binarySearchTree_free(node->right);
    free(node);
}

binarySearchTree *binarySearchTree_search(binarySearchTree *node, int elem) {
    if ((!node) || (node->data == elem)) return node;
    if (node->data > elem) return binarySearchTree_search(node->left, elem);
    else if (node->data < elem) return binarySearchTree_search(node->right, elem);
    return node;
}

binarySearchTree *binarySearchTree_insert(binarySearchTree *node, int elem) {
    if (!node) return binarySearchTree_create(elem, NULL, NULL);
    if (node->data > elem) node->left = binarySearchTree_insert(node->left, elem);
    else if (node->data < elem) node->right = binarySearchTree_insert(node->right, elem);
    return node;
}
binarySearchTree *binarySearchTree_delete(binarySearchTree *node, int elem) {
    if (!node) return NULL;
    if (elem < node->data) node->left = binarySearchTree_delete(node->left, elem);
    else if (elem > node->data) node->right = binarySearchTree_delete(node->right, elem);
    else {
        if ((!node->left) && (!node->right)) {
            free(node);
            node = NULL;
        }
        else if ((!node->left) || (!node->right)) {
            binarySearchTree *trash = node;
            if (node->left) node = node->left;
            else node = node->right;
            free(trash);
        }
        else {
            binarySearchTree *aux = node->left;
            while (aux->right) aux = aux->right;
            node->data = aux->data;
            aux->data = elem;
            node->left = binarySearchTree_delete(node->left, elem);
        }
    }
    return node;
}