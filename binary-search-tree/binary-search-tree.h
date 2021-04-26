#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

typedef struct node Node;

// Returns a NULL pointer that iniciates a empty Binary Tree
Node *createBinaryTree();

// Returns 1 if the subtree is empty, 0 otherwise
int isEmpty(Node *node);

// Prints the Binary Tree in a structured way
void printFancy(Node *node, int depth);

// Prints the elements of the Binary Tree in order
void printInOrder(Node *node);

// Returns the value of a node of the Binary Tree
// If the Binary Tree is empty, then returns 0 and prints a error
int getValue(Node *node);

// Returns the minimum value of a subtree
Node *getMinimum(Node *node);

// Returns the maximum value of a subtree
Node *getMaximum(Node *node);

// Returns the sucessor of node of the Binary Tree
// Returns NULL pointer if the node is the biggest value
Node *getSucessor(Node *node);

// Returns the predecessor of node of the Binary Tree
// Returns NULL pointer if the node is smallest value
Node *getPredecessor(Node *node);

// Returns the node that contain the specified value
// If the value is not inside the subtree, returns NULL
Node *searchNode(Node *tree, int value);

// Create and insert a new node to the Binary Tree with the specified value
// Returns the new Tree with the node inserted
Node *insertNode(Node *tree, int value);

// Remove the node with the specified value and keeps
// the properties of the Binary Tree
Node *removeNode(Node *tree, Node *node);

#endif