#include "../../Structs/binary_trees/binary_tree/binaryTree.h"

binaryTree *mirror(binaryTree *root) {
    if (!root) return NULL;
    binaryTree *new = (binaryTree *) malloc(sizeof(binaryTree));
    new->data = root->data;
    new->left = mirror(root->right);
    new->right = mirror(root->left);
    return new;
}