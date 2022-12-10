#include "../../Structs/binary_trees/binary_search_tree/binarySearchTree.h"

int len_array(binarySearchTree *tree, int n) {
    if (!tree) return 0;
    int len = 0;
    len += len_array(tree->left, n);
    if (tree->data < n) {
        len += len_array(tree->right, n);
        len++;
    }
    return len;
}

void aux_smaller_than_n(int *array, binarySearchTree *tree, int *pos, int n) {
    if (!tree) return;
    aux_smaller_than_n(array, tree->left, pos, n);
    if (tree->data < n) {
        aux_smaller_than_n(array, tree->right, pos, n);
        array[*pos] = tree->data;
        *pos++;
    }
    return;
}

int *smaller_than_n(binarySearchTree *tree, int n) {
    int len = len_array(tree, n);
    int *array = (int *) malloc(sizeof(int) * len), pos = 0;
    aux_smaller_than_n(array, tree, &pos, n);
    return array;
}