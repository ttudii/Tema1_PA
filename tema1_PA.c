#include "liste.c"

int cerinta_1(Node **head, FILE *f1,FILE *f2,char file1[],char file2[]){

    if((f1=fopen(file1,"rt"))==NULL){
        printf("Error opening file!\n\n");
        exit(1);
    }

    int nr_teams;
    fscanf(f1,"%d",&nr_teams);

    while(!feof(f1)){
        Team temp=addPlayers(f1);
        if(feof(f1)) break;
        addAtBeginning(head,temp);
    }

    fclose(f1);

    Node* headcopy=*head;

    printTeams(&headcopy,f2,file2,nr_teams);

    return nr_teams;
    
}

int* readRequirement(FILE *f,char file[]){

    if((f=fopen(file,"rt"))==NULL){
        fprintf(stdout,"Error opening file!\n");
        exit(1);
    }

    int *v;

    v=(int*)malloc(sizeof(int)*5);

    int i=0;

    while(i<5){
        fscanf(f,"%d",&v[i]);
        i++;
    }

    fclose(f);

    return v;

}

int main(int argc,char *argv[]){

    FILE *f1,*f2,*f3;

    Node *head=(Node*)malloc(sizeof(Node));

    int *requirement = (int*)malloc(sizeof(int)*5);

    requirement=readRequirement(f1,argv[1]);

    int numberofTeams;

    //cerinta 1
    if(requirement[0]==1) numberofTeams = cerinta_1(&head,f2,f3,argv[2],argv[3]);

    return 0;
}

