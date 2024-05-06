#include "team.h"

void addAtBeginning(Node **head, Team data);
Team addPlayers(FILE *f2);
void printTeams(Node** Node,FILE *f,char file[], int number);
float pointsCalculator(Node *node);
float lowestPoints(Node* head);
void eliminateTeam(Node **head, float aux);
bool twoPower(int number);
void addAtEnd(Node** head, Team data);
