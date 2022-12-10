#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree{
  int data;
  struct binaryTree *left, *right;
}binaryTree;

binaryTree *binaryTree_init(void);
binaryTree *binaryTree_create(int root, binaryTree *left, binaryTree *right);

void binaryTree_print_pre(binaryTree *node);
void binaryTree_print_pos(binaryTree *node);
void binaryTree_print_sim(binaryTree *node);
void binaryTree_print_ident(binaryTree *node);

void binaryTree_free(binaryTree *node);

binaryTree *binaryTree_search(binaryTree *node, int elem);
binaryTree *binaryTree_delete(binaryTree *node, int elem);