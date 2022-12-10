#include "../../Structs/binary_trees/binary_search_tree/binarySearchTree.h"

binarySearchTree *larger(binarySearchTree *tree) {
    binarySearchTree *aux = tree;
    while (aux->right) aux = aux->right;
    return aux;
}