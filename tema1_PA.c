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

    Node* headcopy = *head;

    printTeams(&headcopy,f2,file2,nr_teams);

    return nr_teams;
    
}

void cerinta_2(Node **head,FILE *f,char file[],int *numberofTeams){

    //raman n echipe, n maxim si n putere a lui 2
    //daca doua echipe au acelasi punctaj se elimina  prima echipa gasita in lista

    float minimum_points;

    while(twoPower(*numberofTeams)==0){

        minimum_points=lowestPoints(*head);//cauta echipa cu cel mai mic punctaj din cele ramase
        eliminateTeam(head,minimum_points); //return la numarul de echipe ramase dupa eliminare
        *numberofTeams=*numberofTeams-1;
        
    }

    printTeams(head,f,file,*numberofTeams); //afisarea listei noi in fisierul out

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

    //declarari

    FILE *f1,*f2,*f3;

    Node* head=(Node*)malloc(sizeof(Node));

    int numberofTeams;

    //extragerea datelor din fisierul c.in
    int *requirement = (int*)malloc(sizeof(int)*5);

    requirement=readRequirement(f1,argv[1]);

    //cerinta 1
    if(requirement[0]==1) numberofTeams = cerinta_1(&head,f2,f3,argv[2],argv[3]);

    //cerinta 2

    if(requirement[1]==1) cerinta_2(&head,f3,argv[3],&numberofTeams);


    return 0;
}

