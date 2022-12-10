#include "../../Structs/binary_trees/binary_tree/binaryTree.h"
#include <limits.h>

int aux_larger(binaryTree *node, int larger) {
    if (!node) return larger;
    larger = aux_larger(node->left, larger);
    larger = aux_larger(node->right, larger);
    if (node->data > larger) larger = node->data;
    return larger;
}

binaryTree *larger(binaryTree *root) {
    if (!root) return NULL;
    int larger = INT_MIN;
    larger = aux_larger(root, larger);
    return(binaryTree_search(root, larger));
}