#include <string.h>
#include "binaryTree.h"

int main(void) {
    int node, dad;
    printf("Enter the root of the tree: ");
    scanf("%d", &node);
    binaryTree *tree = binaryTree_create(node, NULL, NULL);
    binaryTree *answer;
    char repeat;
    do {
        char side[2];
        printf("Do you want to continue inserting nodes into the tree (type N or n to stop)? ");
        scanf(" %c", &repeat);
        if ((repeat == 'N') || (repeat == 'n')) break;
        printf("Type the parent (which must exist), the child to be inserted in the tree and the position L(LEFT) or R(RIGHT)...");
        scanf("%d%d%s", &dad, &node, side);
        answer = binaryTree_search(tree, dad);
        if (!answer){
            binaryTree_free(tree);
            return 0;
        }
        if ((strcmp(side, "L") == 0) || (strcmp(side, "l") == 0)) answer->left = binaryTree_create(node, NULL, NULL);
        else answer->right = binaryTree_create(node, NULL,NULL);
    }while(1);

    binaryTree_print_ident(tree);
    printf("\n");

    binaryTree_free(tree);

    return 0;
}