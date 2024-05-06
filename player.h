struct Player{
    char firstname[30];
    char secondname[30];
    int points;
};

typedef struct Player Player;

struct Team{

    int players;
    char *team_name;
    Player player[5];

};

typedef struct Team Team;