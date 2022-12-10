#include "../../Structs/binary_trees/binary_tree/binaryTree.h"

binaryTree *copy(binaryTree *root) {
    if (!root) return NULL;
    binaryTree *new = (binaryTree *) malloc(sizeof(binaryTree));
    new->data = root->data;
    new->left = copy(root->left);
    new->right = copy(root->right);
    return new;
}