#include "../../Structs/binary_trees/binary_search_tree/binarySearchTree.h"

binarySearchTree *smaller(binarySearchTree *tree) {
    binarySearchTree *aux = tree;
    while (aux->left) aux = aux->left;
    return aux;
}