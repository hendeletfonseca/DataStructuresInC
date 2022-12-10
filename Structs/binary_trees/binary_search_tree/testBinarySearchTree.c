#include "binarySearchTree.h"

int main(void) {
    binarySearchTree *tree = binarySearchTree_init();
    int n;

    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        tree = binarySearchTree_insert(tree, n);
    }
    binarySearchTree_print_ident(tree);
    binarySearchTree_free(tree);
    return 0;
}