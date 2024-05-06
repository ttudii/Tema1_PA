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

float pointsCalculator(Node *node){
	
	float points=0;
	int i=0;

	while(i<node->team.players){
		points+=(float)node->team.player[i].points;
		i++;
	}

	points=points/(float)node->team.players;

	return points;

}

float lowestPoints(Node* head){

	Node *headcopy=head;

	float points;

	float temp = __INT_MAX__;

	while(headcopy!=NULL){

		points = pointsCalculator(headcopy);

		if(points<temp) temp=points;
		headcopy=headcopy->next;
	}

	return temp;

}

void eliminateTeam(Node **head, float aux){	

	if (*head==NULL) return; 

	Node* headcopy = *head;

	if (pointsCalculator(headcopy)==aux){
		*head = (*head)->next;
		free(headcopy);
		return; 
	}

	Node *prev = *head;

	while (headcopy!=NULL){
		if(pointsCalculator(headcopy->next)!=aux){
			headcopy = headcopy->next;
		}else{
			Node *found=headcopy->next;
			headcopy->next= headcopy->next->next;
			free(found); 
			return; 
		} 

	}

}


bool twoPower(int number){

	if(number == 0) return 0;
	else
	{
		while(number!=1){
			if(number%2==0) number/=2;
			else
			return 0;
		}
	}

	if(number==1) return 1;

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

