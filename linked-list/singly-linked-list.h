#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

//define the list data type as a singly linked list of integers
typedef struct list List;

//returns NULL representing a empty linked list
List *createSinglyLinkedList(void);

//adds a new node with the value to the linked list and returns the new list
List *addElementToSinglyLinkedList(List *linkedList, int value);

//remove a element from the linked list and returns the new list
//use searchElementFromSinglyLinkedList to find the adress of the element to be removed
List *removeElementFromSinglyLinkedList(List *linkedList, List *elementToBeRemoved);

//returns the adress of the node that have the element
//returns NULL if the element isn't in the list
List *searchElementFromSinglyLinkedList(List *linkedList, int elementToBeFound);

//returns a pointer to the value stored in a node of the linked list
//returns NULL if the elements is NULL
int *getValueFromElement(List* element);

//stores the specified value in the element
List *setValueToElement(List *element, int value);

//prints all the elements of the linked list
void printSinglyLinkedList(List *linkedList);

//delete the elements and free the linkedList
List *freeSinglyLinkedList(List *linkedList);


#endif 
