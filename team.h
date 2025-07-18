#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Player{
    
    char *firstname;
    char *secondname;
    int points;
};

typedef struct Player Player;

struct Team{

    int players;
    float points;
    char* team_name;
    Player *player;

};

typedef struct Team Team;

struct Node{
    Team team;
    struct Node *next;
};

typedef struct Node Node;

struct Match{
    Team team[2];
};

typedef struct Match Match;

