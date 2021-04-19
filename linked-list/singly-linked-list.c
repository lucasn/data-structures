#include <stdio.h>
#include <stdlib.h>
#include "singly-linked-list.h"

typedef struct list {
    int value;
    struct list *next;
} List;

List *createSinglyLinkedList(void){
    return NULL;
}

List *addElementToSinglyLinkedList(List *linkedList, int value){
    List *newNode = (List *) malloc(sizeof(List));

    if (newNode == NULL) {
        printf("out of memory\n");
        exit(1);
    }

    newNode->value = value;
    newNode->next = linkedList;

    return newNode;
}

void printSinglyLinkedList(List *linkedList){
    List *actualElement = linkedList;

    while (actualElement != NULL){
        if (actualElement->next != NULL) printf("%d ", actualElement->value);
        else printf("%d\n", actualElement->value);

        actualElement = actualElement->next;
    }
}

List *searchElementFromSinglyLinkedList(List *linkedList, int elementToBeFound){
    List *actualElement = linkedList;
    
    while (actualElement != NULL && actualElement->value != elementToBeFound){
        actualElement = actualElement->next;
    }

    return actualElement;
}

int *getValueFromElement(List* element){
    if (element != NULL) return &(element->value);
    return NULL;
}

List *setValueToElement(List *element, int value){
    if (element != NULL){
        element->value = value;
        return element;
    }
    return NULL;
}

List *removeElementFromSinglyLinkedList(List *linkedList, List *elementToBeRemoved){
    List *previousElement = NULL;
    List *actualElement = linkedList;

    while (actualElement != NULL && actualElement != elementToBeRemoved){
        previousElement = actualElement;
        actualElement = actualElement->next;
    }

    if (actualElement == NULL){
        return linkedList;
    }
    else if (previousElement == NULL){
        List *newList = actualElement->next;
        free(actualElement);
        return newList;
    } 
    else {
        previousElement->next  = actualElement->next;
        free(actualElement);
        return linkedList;
    }
}

List *freeSinglyLinkedList(List *linkedList){
    List *actualElement = linkedList;
    List *nextElement = actualElement->next;

    while (nextElement != NULL){
        actualElement = nextElement;
        nextElement = actualElement->next;
        free(actualElement);
    }
    
    return NULL;
}