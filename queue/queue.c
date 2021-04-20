#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct queue {
    Node *begin;
    Node *end;
} Queue;

Queue *createQueue(){
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    if (queue == NULL){
        printf("error in createQueue: not enough memory\n");
        exit(1);
    }

    queue->begin = NULL;
    queue->end = NULL;

    return queue;
}

int isEmptyQueue(Queue *queue){
    if (queue->begin == NULL) return 1;
    return 0;
}

void printQueue(Queue *queue){
    if (isEmptyQueue(queue)){
        printf("empty queue");
    }
    else {
        printf("begin->");
        Node *actualNode = queue->begin;
        while (actualNode != NULL){
            printf("%d->", actualNode->value);
            actualNode = actualNode->next;
        }
        printf("end");
    }
    printf("\n");
}

void enqueue(Queue *queue, int value){
    Node *node = (Node *) malloc(sizeof(Node));

    if (node == NULL){
        printf("error in enqueue: not enough memory\n");
        exit(1);
    }

    node->next = NULL;
    node->value = value;

    if (isEmptyQueue(queue)) {
        queue->begin = node;
    }
    else {
        queue->end->next = node;
    }
    queue->end = node;
}

int dequeue(Queue *queue){
    if (isEmptyQueue(queue)){
        printf("error: queue already empty\n");
        return 0;
    }
    Node *node = queue->begin;
    int value = node->value;
    if (queue->begin == queue->end) queue->end = NULL;
    queue->begin = node->next;
    free(node);
    return value;
}

int getBeginQueue(Queue *queue){
    if (isEmptyQueue(queue)){
        printf("empty queue\n");
        return 0;
    }
    return queue->begin->value;
}

int getEndQueue(Queue* queue){
    if (isEmptyQueue(queue)){
        printf("empty queue\n");
        return 0;
    }
    return queue->end->value;
}

void freeQueue(Queue *queue){
    Node *actualNode = queue->begin;
    Node *tmp;
    while (actualNode != NULL){
        Node *tmp = actualNode;
        actualNode = actualNode->next;
        free(tmp);
    }
    free(queue);
}