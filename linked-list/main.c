#include <stdio.h>
#include "singly-linked-list.h"

int main(void){
    List *linkedList = createSinglyLinkedList();

    linkedList = addElementToSinglyLinkedList(linkedList, 10);
    linkedList = addElementToSinglyLinkedList(linkedList, 11);
    linkedList = addElementToSinglyLinkedList(linkedList, 12);
    linkedList = addElementToSinglyLinkedList(linkedList, 13);

    printSinglyLinkedList(linkedList);

    List *element = searchElementFromSinglyLinkedList(linkedList, 10);

    printf("%d\n", *getValueFromElement(element));

    setValueToElement(element, 20);

    printSinglyLinkedList(linkedList);

    linkedList = removeElementFromSinglyLinkedList(linkedList, element);

    printSinglyLinkedList(linkedList);

    linkedList = freeSinglyLinkedList(linkedList);

    printSinglyLinkedList(linkedList);
    return 0;
}