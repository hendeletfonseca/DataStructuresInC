#include <stdio.h>
#include <stdlib.h>

typedef struct binarySearchTree{
    int data;
    struct binarySearchTree *left, *right;
}binarySearchTree;

binarySearchTree *binarySearchTree_init(void);
binarySearchTree *binarySearchTree_create(int root, binarySearchTree *left, binarySearchTree *right);

void binarySearchTree_print_pre(binarySearchTree *node);
void binarySearchTree_print_pos(binarySearchTree *node);
void binarySearchTree_print_sim(binarySearchTree *node);
void binarySearchTree_print_ident(binarySearchTree *node);

void binarySearchTree_free(binarySearchTree *node);

binarySearchTree *binarySearchTree_search(binarySearchTree *node, int elem);

binarySearchTree *binarySearchTree_insert(binarySearchTree *node, int elem);
binarySearchTree *binarySearchTree_delete(binarySearchTree *node, int elem);