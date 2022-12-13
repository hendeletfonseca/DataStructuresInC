#include <stdio.h>
#include <stdlib.h>

typedef struct bTree {
    int nkeys, leaf, *key;
    struct bTree **children;
}bTree;

bTree *bTree_init();
bTree *bTree_create(int t);

bTree *bTree_free(bTree *tree);

bTree *bTree_search(bTree *tree, int key);

bTree *bTree_insert(bTree *tree, int key, int t);
bTree *bTree_delete(bTree *tree, int key, int t);

void bTree_print(bTree *tree);