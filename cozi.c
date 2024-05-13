#include "cozi.h"

Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

void enQueue(Queue* q, Node **headcopy){

	qNode* newNode=(qNode*)malloc(sizeof(qNode));

	newNode->match.team[0]=(*headcopy)->team;
	(*headcopy)=(*headcopy)->next;
	newNode->match.team[1]=(*headcopy)->team;

	newNode->next=NULL;
	if (q->rear==NULL) q->rear=newNode; 

	else{
		(q->rear)->next=newNode;
		(q->rear)=newNode;
	}

	if (q->front==NULL) q->front=q->rear; 
}
 
Match deQueue(Queue*q) {

	qNode* aux; Match d;

	//if (queueEmpty(q)) return;
	
	aux=q->front;

	d=aux->match;

	q->front=(q->front)->next;

	free(aux);

	return d;  	
} 

int queueEmpty(Queue*q){
	return (q->front==NULL);
}

void deleteQueue(Queue*q){
	qNode* aux;
	while (!queueEmpty(q)){
		aux=q->front;
		q->front=q->front->next;
		free(aux);
	}
	free(q);
}	

//functii necesare pentru rezolvarea cerintei 3

void printMatches(Queue *q,FILE *f,char file[],int index){

	if((f=fopen(file,"at"))==NULL){
		fprintf(f,"Error opening file!");
		exit(1);
	}

	qNode* node= q->front;

	fprintf(f,"\n--- ROUND NO:%d\n",index);

	while(node!=NULL){
		fprintf(f,"%s",node->match.team[0].team_name);
		for(int i=0;i<33-strlen(node->match.team[0].team_name);i++){
			fprintf(f," ");
		}
		fprintf(f,"-");
		for(int i=0;i<33-strlen(node->match.team[1].team_name);i++){
			fprintf(f," ");
		}
		fprintf(f,"%s\n",node->match.team[1].team_name);
		node=node->next;
	}	

	fclose(f);

}

void addTeams(Queue *q,Node** Winners,Node** Losers){

	while(q->front!=NULL){

		Match temp = deQueue(q);

		if(temp.team[0].points > temp.team[1].points) {
			temp.team[0].points++;
			push(Winners,temp.team[0]);
			push(Losers,temp.team[1]);
		}
		else
		if(temp.team[0].points <= temp.team[1].points) {
			temp.team[1].points++;
			push(Winners,temp.team[1]);
			push(Losers,temp.team[0]);
		}
	}


}