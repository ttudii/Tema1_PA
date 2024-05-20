#include "liste.c"
#include "stive.c"
#include "cozi.c"
#include "arbori.c"

int cerinta_1(Node **head, FILE *f1,FILE *f2,char file1[],char file2[]){

    if((f1=fopen(file1,"rt"))==NULL){
        printf("Error opening file!\n\n");
        exit(1);
    }

//functi pt stergerea ultimului spatiu si citire echipe pana cand este egal cu numarul de echipe citit initial

    int nr_teams;
    fscanf(f1,"%d",&nr_teams);

    int i=0;

    while(i<nr_teams){

        Team temp = addPlayers(f1);

        if(feof(f1)) break;

        addAtBeginning(head,temp);

        i++;
    }

    fclose(f1);

    Node* headcopy = *head;

    printTeams(&headcopy,f2,file2);

    return nr_teams;
    
}

void cerinta_2(Node **head,FILE *f,char file[],int *numberofTeams){

    //raman n echipe, n maxim si n putere a lui 2
    //daca doua echipe au acelasi punctaj se elimina  prima echipa gasita in lista

    float minimum_points;

    Node *aux = *head;

    while(aux->next!=NULL){
        pointsCalculator(&aux);
        aux=aux->next;

    }

    while(twoPower(*numberofTeams) == 0){

        minimum_points=lowestPoints(*head);//cauta echipa cu cel mai mic punctaj din cele ramase
        eliminateTeam(head,minimum_points); //return la numarul de echipe ramase dupa eliminare
        *numberofTeams=*numberofTeams-1;
        
    }

    Node* headcopy = *head;

    printTeams(&headcopy,f,file); //afisarea listei noi in fisierul out

}

void cerinta_3(Node **head, Queue **q,Node** topWinners,Node** topLosers,Node** newList, int *numberofTeams,FILE *f, char file[]){

    //problema print castigator
    //problema alegere castigator meci la punctaj egal

    Node *headcopy=*head;

    while(headcopy->next!=NULL){
        enQueue(*q,&headcopy);
        headcopy=headcopy->next;
    }

    int rounds=0;

    rounds++;
    printMatches(*q,f,file,rounds);

    while(*numberofTeams!=2){

        //populare dintr-o singura functie?
        addTeams(*q,topWinners,topLosers);
        
        //coada goala dupa adaugare in stive
        Node *stackCopy=*topWinners;

        printStack(stackCopy,f,file,rounds);

        deleteStack(topLosers);

        *numberofTeams=*numberofTeams/2;

        if(queueEmpty(*q)) (*q)->rear=NULL;

        if(*numberofTeams==8){

            stackCopy=*topWinners;

            while(stackCopy!=NULL){

                addAtBeginning(newList,stackCopy->team);
                stackCopy=stackCopy->next;
            }

        }


        while(!stackEmpty(*topWinners)){
            enQueue(*q,topWinners);
            pop(topWinners);
        }

        rounds++;

        printMatches(*q,f,file,rounds);

    }

    addTeams(*q,topWinners,topLosers);

    Node*stackCopy=*topWinners;

    printStack(stackCopy,f,file,rounds);

}

void cerinta_4(Node *newList,NodeBST *root,FILE *f,char file[],Node **listAVL){

    Node *headcopy=newList;

    while(headcopy->next!=NULL){
        root=insertBST(root,headcopy->team);
        headcopy=headcopy->next;
    }

    if((f=fopen(file,"at"))==NULL){
        fprintf(f,"Error opening file!\n");
        exit(1);
    }

    fprintf(f,"\nTOP 8 TEAMS:\n");
    
    //am duplicate
    ReverseInorder(root,f,listAVL);

    //trebuie in plus adaugat ultimul (functie de adaugare)
    addAtEnd(listAVL,root->team);

    fclose(f);

}

void cerinta_5(Node *listAVL,NodeAVL *Root,FILE *f,char file[]){

    while(listAVL->next!=NULL){
        Root=insertAVL(Root,listAVL->team);
        listAVL=listAVL->next;
    }

    if((f=fopen(file,"at"))==NULL){
        fprintf(f,"Error opening file!\n");
        exit(1);
    }

    fprintf(f,"\nTHE LEVEL 2 TEAMS ARE: \n");

    printLevel(Root,3,f);

    fclose(f);

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

    Node* topWinners=NULL;
    Node* topLosers=NULL;
    Node* newList=(Node*)malloc(sizeof(Node));
    NodeBST* root=NULL;
    Node* listAVL=NULL;
    NodeAVL* Root=NULL; 

    Queue *q=createQueue();

    int numberofTeams;

    //extragerea datelor din fisierul c.in
    int *requirement = (int*)malloc(sizeof(int)*5);

    requirement=readRequirement(f1,argv[1]);

    //cerinta 1
    if(requirement[0]==1) numberofTeams = cerinta_1(&head,f2,f3,argv[2],argv[3]);

    //cerinta 2
    if(requirement[1]==1) cerinta_2(&head,f3,argv[3],&numberofTeams);

    //cerinta 3
    if(requirement[2]==1) cerinta_3(&head,&q,&topWinners,&topLosers,&newList,&numberofTeams,f3,argv[3]);

    //cerinta 4
    if(requirement[3]==1) cerinta_4(newList,root,f3,argv[3],&listAVL);

    //cerinta 5
    if(requirement[4]==1) cerinta_5(listAVL,Root,f3,argv[3]);


    return 0;
}

