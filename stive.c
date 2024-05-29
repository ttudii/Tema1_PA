#include "stive.h"


int stackEmpty(Node*top){
	return top==NULL;
}

Team top(Node *top){
	//if (stackEmpty(top)) return;
	return top->team;
} 

Team pop(Node**top) {

	//if (stackEmpty(*top)) return; 
	
	Node *temp=(*top);  		
	Team aux=temp->team;		

	*top=(*top)->next; 
	     		
	free(temp);

	return aux;
}

void push(Node**top, Team data) {

	Node* newNode=(Node*)malloc(sizeof(Node));

	newNode->team = data;
	newNode->next=*top;
	*top=newNode;

}


void deleteStack(Node**top){
	Node  *temp;
	while ((*top)!=NULL){ // !isEmpty(*top)
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}	

void printStack(Node* stackCopy,FILE *f,char file[],int index){

	if((f=fopen(file,"at"))==NULL){
		fprintf(f,"Error opening file!");
		exit(1);
	}

	fprintf(f,"\nWINNERS OF ROUND NO:%d\n",index);
	while (!stackEmpty(stackCopy)){
		fprintf(f,"%s", stackCopy->team.team_name);
		for(int i=0;i<34-strlen(stackCopy->team.team_name);i++){
			fprintf(f," ");
		}
		fprintf(f,"-  ");
		fprintf(f,"%.2f\n", stackCopy->team.points);
		stackCopy=stackCopy->next;
	}

	fclose(f);

}
