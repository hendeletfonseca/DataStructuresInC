#include "../../Structs/binary_trees/binary_tree/binaryTree.h"
#include <limits.h>

int aux_smaller(binaryTree *node, int smaller) {
    if (!node) return smaller;
    smaller = aux_smaller(node->left, smaller);
    smaller = aux_smaller(node->right, smaller);
    if (node->data < smaller) smaller = node->data;
    return smaller;
}

binaryTree *smaller(binaryTree *root) {
    if (!root) return NULL;
    int smaller = INT_MAX;
    smaller = aux_smaller(root, smaller);
    return(binaryTree_search(root, smaller));
}