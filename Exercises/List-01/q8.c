#include "../../Structs/binary_trees/binary_tree/binaryTree.h"

int qtd_internal_nodes(binaryTree *tree) {
    if (!tree) return 0;
    int qtd = 0;
    qtd += qtd_internal_nodes(tree->left);
    qtd += qtd_internal_nodes(tree->right);
    return qtd;
}