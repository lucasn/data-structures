#include <stdio.h>
#include "queue.h"

int main(void){
    Queue *queue = createQueue();

    printf("%d\n", isEmptyQueue(queue));

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d\n", isEmptyQueue(queue));

    printQueue(queue);

    dequeue(queue);

    printf("Begin: %d -- End:%d\n", getBeginQueue(queue), getEndQueue(queue));

    printQueue(queue);

    freeQueue(queue);
    return 0;
}