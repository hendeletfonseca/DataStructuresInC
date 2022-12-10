#include "../../Structs/binary_trees/binary_tree/binaryTree.h"

binaryTree *remove_pairs(binaryTree *tree) {
    if (!tree) return NULL;
    if (tree->left) tree->left = remove_pairs(tree->left);
    if (tree->right) tree->right = remove_pairs(tree->right);
    if ((tree->data % 2) == 0) tree = binaryTree_delete(tree, tree->data);
    return tree;
}