#include "binaryTree.h"

binaryTree *binaryTree_init(void){
    return NULL;
}
binaryTree *binaryTree_create(int root, binaryTree *left, binaryTree *right){
    binaryTree *new = (binaryTree *) malloc(sizeof(binaryTree));
    new->data = root;
    new->left = left;
    new->right = right;
    return new;
}

void binaryTree_print_pre(binaryTree *node){
    if (!node) return;
    printf("%d ", node->data);
    binaryTree_print_pre(node->left);
    binaryTree_print_pre(node->right);
}
void binaryTree_print_pos(binaryTree *node){
    if (!node) return;
    binaryTree_print_pre(node->left);
    binaryTree_print_pre(node->right);
    printf("%d ", node->data);
}
void binaryTree_print_sim(binaryTree *node){
    if (!node) return;
    binaryTree_print_pre(node->left);
    printf("%d ", node->data);
    binaryTree_print_pre(node->right);
}
void print_aux(binaryTree *node, int floor){
    int j;
    if(node){
        print_aux(node->left, floor + 1);
        for(j = 0; j <= floor; j++) printf("\t");
        printf("%d\n", node->data);
        print_aux(node->right, floor + 1);
    }
    else{
        for(j = 0; j <= floor; j++) printf("\t");
        printf("N\n");
    }
}
void binaryTree_print_ident(binaryTree *node){
    print_aux(node, 0);
}

void binaryTree_free(binaryTree *node){
    if (!node) return;
    binaryTree_free(node->left);
    binaryTree_free(node->right);
    free(node);
}

binaryTree *binaryTree_search(binaryTree *node, int elem){
    if (!node) return NULL;
    if (node->data == elem) return node;
    binaryTree *answer = binaryTree_search(node->left, elem);
    if (answer) return answer;
    return(binaryTree_search(node->right, elem));
}

binaryTree *binaryTree_delete(binaryTree *node, int elem) {
    if (!node) return NULL;
    if (node->left) node->left = binaryTree_delete(node->left, elem);
    if (node->right) node->right = binaryTree_delete(node->right, elem);
    if (node->data == elem) {
        if ((!node->left) && (!node->right)) { // leaf
            free(node);
            node = NULL;
        }
        else if ((!node->left) || (!node->right)) { // only 1 son
            binaryTree *trash = node;
            if (node->left) node = node->left;
            else node = node->right;
            free(trash);
        }
        else {
            binaryTree *aux = node;
            while (aux->left) aux = aux->left;
            node->data = aux->data;
            aux->data = elem;
            node->left = binaryTree_delete(node->left, elem);
        }
    }
    return node;
}