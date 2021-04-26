#include <stdio.h>
#include "binary-search-tree.h"

int main(void){
    Node *tree = createBinaryTree();

    printf("The tree is empty: %d\n", isEmpty(tree));

    tree = insertNode(tree, 7);
    tree = insertNode(tree, 20);
    tree = insertNode(tree, 15);
    tree = insertNode(tree, 3);
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 1);

    printFancy(tree, 0);
    printf("\n");

    printInOrder(tree);
    printf("\n");

    printf("The minimum value of the tree is: %d\n", getValue(getMinimum(tree)));
    printf("The maximum value of the tree is: %d\n", getValue(getMaximum(tree)));

    printf("The sucessor of 15 is: %d\n", getValue(getSucessor(searchNode(tree, 15))));
    printf("The predecessor of 4 is: %d\n", getValue(getPredecessor(searchNode(tree, 4))));

    tree = removeNode(tree, searchNode(tree, 3));
    tree = removeNode(tree, searchNode(tree ,7));

    printFancy(tree, 0);
    printf("\n");

    printInOrder(tree);
    printf("\n");
    return 0;
}