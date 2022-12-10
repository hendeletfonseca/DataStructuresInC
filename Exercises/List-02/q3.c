#include "../../Structs/binary_trees/binary_search_tree/binarySearchTree.h"

binarySearchTree *remove_odds(binarySearchTree *tree) {
    if (!tree) return NULL;
    if (tree->left) tree->left = remove_odds(tree->left);
    if (tree->right) tree->right = remove_odds(tree->right);
    if (tree->data % 2 != 0) tree = binarySearchTree_delete(tree, tree->data);
    return tree;
}