#ifndef QUEUE
#define QUEUE

// defining the queue structure
typedef struct queue Queue;

// creates a queue and returns a pointer to it
Queue *createQueue();

// returns 1 if the queue if empty, 0 otherwise
int isEmptyQueue(Queue *queue);

// prints all the queue from the beginning to the end
void printQueue(Queue *queue);

// adds the value to the end of the queue
void enqueue(Queue *queue, int value);

// removes the value of the beginning of the queue and free it's memory
// returns 0 if the queue is already empty
int dequeue(Queue *queue);

// returns the value from the beginning of the queue
// returns 0 if the queue is empty
int getBeginQueue(Queue *queue);

// returns the value from the end of the queue
// returns 0 if the queue is empty
int getEndQueue(Queue *queue);

// remove all values and free all the space of the queue
void freeQueue(Queue *queue);

#endif