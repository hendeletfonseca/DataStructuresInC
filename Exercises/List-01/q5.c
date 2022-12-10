#include "../../Structs/binary_trees/binary_tree/binaryTree.h"

int equal(binaryTree *t1, binaryTree *t2) {
    if ((!t1) && (!t2)) return 1;
    if ((!t1) || (!t2)) return 0;
    if (t1->data != t2->data) return 0;
    if ((equal(t1->left, t2->left)) && (equal(t1->right, t2->right))) return 1;
    return 0;
}