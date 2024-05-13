#include "team.h"

struct queueNode{
    Match match;
    struct queueNode *next;
};

typedef struct queueNode qNode;

struct Queue{
    qNode *front,*rear;
};

typedef struct Queue Queue;

Queue* createQueue();
void enQueue(Queue *q, Node **head);
Match deQueue(Queue*q);
int queueEmpty(Queue*q);
void deleteQueue(Queue*q);
