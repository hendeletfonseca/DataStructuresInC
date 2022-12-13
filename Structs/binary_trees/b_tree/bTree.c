#include "bTree.h"

bTree *bTree_init() {
    return NULL;
}
bTree *bTree_create(int t) {
    bTree *new = (bTree *) malloc(sizeof(bTree));
    new->nkeys = 0;
    new->key = (int *) malloc(sizeof(int*) * ((2 * t) - 1));
    new->leaf = 1;
    new->children = (bTree **) malloc(sizeof(bTree*) * 2 * t);
    for (int i = 0; i < (t * 2); i++) new->children[i] = NULL;
    return new;
}

bTree *bTree_free(bTree *tree) {
    if (!tree) return NULL;
    for (int i = 0; i <= tree->nkeys; i++) bTree_free(tree->children[i]);
    free(tree->key);
    free(tree->children);
    free(tree);
    return NULL;
}

bTree *bTree_search(bTree *tree, int key) {
    if (!tree) return NULL;
    int i = 0;
}

bTree *bTree_insert(bTree *tree, int key, int t);
bTree *bTree_delete(bTree *tree, int key, int t);

void bTree_print(bTree *tree);