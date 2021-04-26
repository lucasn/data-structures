#include <stdio.h>
#include <stdlib.h>
#include "binary-search-tree.h"

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

static Node *replaceNode(Node *tree, Node *original, Node *substitute){
    if (substitute != NULL) substitute->parent = original->parent;
    
    if (original->parent == NULL) return substitute;

    else if (original == original->parent->left) original->parent->left = substitute;
    
    else original->parent->right = substitute;

    return tree;
}

Node *createBinaryTree(){
    return NULL;
}

int isEmpty(Node *node){
    if (node == NULL) return 1;
    return 0;
}

void printFancy(Node *node, int depth){
    if (node == NULL) return;
    
    printFancy(node->right, depth + 1);

    for (int i = 0; i < depth; i++) printf("   ");

    printf("%d\n", node->value);

    printFancy(node->left, depth + 1);
}

void printInOrder(Node *node){
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->value);
    printInOrder(node->right);
}

int getValue(Node *node){
    if (node == NULL){
        printf("Error in 'getValue': NULL pointer\n");
        return 0;
    }

    return node->value;
}

Node *getMinimum(Node *node){
    if (node->left == NULL) return node;
    return getMinimum(node->left);
}

Node *getMaximum(Node *node){
    if (node->right == NULL) return node;
    return getMaximum(node->right);
}

Node *getSucessor(Node *node){
    if (node->right != NULL) return getMinimum(node->right);

    Node *actualParent = node->parent;
    Node *actualNode = node;

    while (actualParent != NULL && actualParent->right == actualNode){
        actualNode = actualParent;
        actualParent = actualParent->parent;
    }

    return actualParent;
}

Node *getPredecessor(Node *node){
    if (node->left != NULL) return getMaximum(node->left);

    Node *actualParent = node->parent;
    Node *actualNode = node;

    while (actualParent != NULL && actualParent->left == actualNode){
        actualNode = actualParent;
        actualParent = actualParent->parent;
    }

    return actualParent;
}

Node *searchNode(Node *tree, int value){
    Node *node = tree;
    while (node != NULL && node->value != value){
        if (value < node->value) node = node->left;
        else node = node->right;
    }
    return node;
}

Node *insertNode(Node *tree, int value){
    Node *node = (Node *) malloc(sizeof(Node));

    if (node == NULL){
        printf("Error in 'insertNode': not enough memory\n");
        exit(1);
    }

    node->value = value;
    node->left = node->right = NULL;

    if (tree == NULL){
        node->parent = NULL;
        return node;
    }

    Node *actualParent = NULL;
    Node *actualNode = tree;

    while (actualNode != NULL){
        if (value < actualNode->value){
            actualParent = actualNode;
            actualNode = actualNode->left;
        }
        else {
            actualParent = actualNode;
            actualNode = actualNode->right;
        }
    }

    node->parent = actualParent;
    if (value < actualParent->value) actualParent->left = node;
    else actualParent->right = node;
    return tree;
}

Node *removeNode(Node *tree, Node *node){
    if (node == NULL) return tree;

    if (node->right == NULL){
        tree = replaceNode(tree, node, node->left);
    }

    else if (node->left == NULL){
        tree = replaceNode(tree, node, node->right);
    }

    else {
        Node *sucessor = getSucessor(node);
        tree = replaceNode(tree, sucessor, sucessor->right);

        sucessor->right = node->right;
        sucessor->left = node->left;

        if (node->right != NULL) node->right->parent = sucessor;
        if (node->left != NULL) node->left->parent = sucessor;

        tree = replaceNode(tree, node, sucessor);
    }
    free(node);
    return tree;
}