#include "team.h"

typedef struct Node Node;
int stackEmpty(Node*top);
Team top(Node *top);
Team pop(Node**top);
void push(Node**top, Team data);
void deleteStack(Node**top);
void printStack(Node* stackCopy,FILE *f,char file[],int index);