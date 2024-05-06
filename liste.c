#include "liste.h"


void addAtBeginning(Node **head, Team data){

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->team = data;
	newNode->next = *head;
	*head = newNode;
}

Team addPlayers(FILE *f2){
	
	Team temp;

	temp.team_name=(char*)malloc(sizeof(char)*30);

	char car;
	
	fscanf(f2,"%d%c%[^\n]\n",&temp.players,&car,temp.team_name);

    int j=0;

	temp.player=malloc(sizeof(Player)*temp.players);

    while(j<temp.players){

		temp.player[j].firstname=(char*)malloc(sizeof(char)*30);
		temp.player[j].secondname=(char*)malloc(sizeof(char)*30);

        fscanf(f2,"%s",temp.player[j].firstname);
        fscanf(f2,"%s",temp.player[j].secondname);
        fscanf(f2,"%d",&temp.player[j].points);

    	j++;
    }

	return temp;

}

void printTeams(Node** Node,FILE *f,char file[], int number){

	if((f=fopen(file,"wt"))==NULL){
        fprintf(stdout,"Error opening file!\n");
        exit(1);
    }

	while((*Node)->next!=NULL){
		fprintf(f,"%s\n",(*Node)->team.team_name);
		*Node = (*Node)->next;
	}

	fclose(f);
	
}


void addAtEnd(Node** head, Team data){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	newNode->team= data; 
	if (*head == NULL) addAtBeginning(head, data);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}

