#include "team.h"

void freeNode(Node* node){

	//free(node->team.team_name); problema la eliberare de memorie

	for(int i=0;i<node->team.players;i++){
		free(node->team.player[i].firstname);
		free(node->team.player[i].secondname);
	}
	free(node->team.player);
	free(node);

}

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


	if(*(temp.team_name+strlen(temp.team_name)-2)==' ') 
		*(temp.team_name+strlen(temp.team_name)-2)='\0';
	else
		*(temp.team_name+strlen(temp.team_name)-1)='\0';

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

void printTeams(Node** Node,FILE *f,char file[]){

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

void pointsCalculator(Node **node){

	int i=0;

	while(i<(*node)->team.players){
		(*node)->team.points+=(float)(*node)->team.player[i].points;
		i++;
	}

	(*node)->team.points=(*node)->team.points/(float)(*node)->team.players;
}

float lowestPoints(Node* head){

	Node *headcopy=head;

	float temp = __INT_MAX__;

	while(headcopy->next!=NULL){

		if(headcopy->team.points < temp) temp=headcopy->team.points;
		headcopy=headcopy->next;
	}

	return temp;

}

void deleteList(Node** head){

	Node  *temp;
	while ((*head)!=NULL){ // !isEmpty(*top)
		temp=*head;
		*head=(*head)->next;
		freeNode(temp);
	}
}	



void eliminateTeam(Node **head, float aux){	

	if (*head==NULL) return; 

	Node* headcopy = *head;

	if (headcopy->team.points == aux){
		
		*head = (*head)->next;
		free(headcopy);
		return; 
	}

	Node * prev = * head ; // predecesorul elementului cautat
		while ( headcopy != NULL ){
			if ( headcopy->team.points != aux ){
				prev = headcopy ;
				headcopy = headcopy->next ;
			}
			else{
				prev->next = headcopy->next ;
				free(headcopy); // sterge elementul
				return ;
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


void addAtEnd(Node** head, Team team){

	Node *aux = *head;

	Node *newNode = (Node*)malloc(sizeof(Node)); 
	newNode->team= team; 

	if (*head == NULL) addAtBeginning(head, team);
	
	else{ 
	
		while (aux->next!=NULL) aux = aux->next;
		
		aux->next = newNode;
		newNode->next = NULL; 
	}
}


