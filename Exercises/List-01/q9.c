#include "../../Structs/binary_trees/binary_tree/binaryTree.h"

int qtd_leaf_node(binaryTree *tree) {
    if (!tree) return 0;
    if ((!tree->left) && (!tree->right)) return 1;
    int qtd = 0;
    qtd += qtd_leaf_node(tree->left);
    qtd += qtd_leaf_node(tree->right);
    return qtd;
}