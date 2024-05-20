#include "arbori.h"

//structura noua pentru noduri de tip arbore

NodeBST* newNode (Team data){

    NodeBST* node = (NodeBST*)malloc(sizeof(NodeBST));
    node->team = data;
    node->left = node->right = NULL ;

    return node;
}

NodeBST* insertBST(NodeBST* node,Team data) {

    // daca ( sub ) arborele este gol , creaza nod
        if (node == NULL) return newNode(data);

    // altfel , coboara la stanga sau dreapta
        if (data.points < node->team.points)
            node->left = insertBST(node->left, data);
        else if (data.points > node->team.points)
            node->right = insertBST(node->right,data);
        else if (data.points==node->team.points){
            if(strcmp(node->team.team_name,data.team_name)<0){
            node->right=insertBST(node->right,data);
            }
            else
            node->left=insertBST(node->left,data);
        }
    // ! pointerul node se intoarce nemodificat pe acest return
    return node;
 
} // ! nu se adauga elemente egale

void ReverseInorder(NodeBST* root,FILE *f,Node **listAVL){

    if(root!=NULL){

        ReverseInorder(root->right,f,listAVL);

        fprintf(f,"%s",root->team.team_name);
		for(int i=0;i<34-strlen(root->team.team_name);i++){
			fprintf(f," ");
		}
		fprintf(f,"-  ");
		fprintf(f,"%.2f\n",root->team.points);

        addAtEnd(listAVL,root->team);

        //adaugare in lista noua pe masura ce afisez (test)

        ReverseInorder(root->left,f,listAVL);

    }
}

//functii arbore AVL

int nodeHeight(NodeAVL* root){

    int hs,hd;

    if ( root == NULL ) return -1;
    // inaltimea subarborelui stang
    hs = nodeHeight(root->left);

    // inaltimea subarborelui drept
    hd = nodeHeight(root->right);

    // returneaza inaltimea nodului
    return 1+((hs>hd) ? hs : hd );
}

int max(int a,int b){
    return (( a > b )? a : b );
}

NodeAVL* rightRotation(NodeAVL * z){

    NodeAVL* y = z->left ;
    NodeAVL* T3 = y->right;

    y->right = z ;
    z->left = T3 ;
    
    z->height = max(nodeHeight (z->left),nodeHeight (z->right))+1;
    y->height = max(nodeHeight (y->left),nodeHeight (y->right))+1;

    return y ; 
}


NodeAVL* leftRotation(NodeAVL* z){

    NodeAVL* y = z->right ;
    NodeAVL* T2 = y->left ;

    y->left = z ;
    z->right = T2 ;

    z->height = max (nodeHeight(z->left),nodeHeight (z->right))+1;
    y->height = max (nodeHeight(y->left),nodeHeight (y->right))+1;

    return y ;
}


NodeAVL* LRRotation(NodeAVL* Z){
    Z->left = leftRotation(Z->left);
    return rightRotation ( Z );
}

NodeAVL* RLRotation(NodeAVL* Z){
    Z->right = rightRotation (Z->right);
    return leftRotation ( Z );
}


NodeAVL* insertAVL(NodeAVL * node ,Team data){

    // 1. inserare nod
    if ( node == NULL ){
        node = (NodeAVL*)malloc(sizeof(NodeAVL));
        node->team = data ;
        node->height = 0; // adaugare ca frunza
        node->left = node->right = NULL ;
        return node ;
    }

    if (data.points < node->team.points)
        node->left = insertAVL(node->left, data);
    else if (data.points > node->team.points)
        node->right = insertAVL(node->right,data);
    else if (data.points==node->team.points){
        if(strcmp(node->team.team_name,data.team_name)<0){
            node->right=insertAVL(node->right,data);
        }
        else node->left=insertAVL(node->left,data);
    }
    
    // 2. updateaza inaltimea nodurilor stramos

    // de jos in sus la iesirea din apelul recurent
    node->height = 1 + max(nodeHeight(node->left),nodeHeight (node->right));

    // 3. afla factorul de echilibru al nodului stramos

    // testul se face de jos in sus, pentru toate nodurile intre cel adaugat si radacina
    int k = (nodeHeight(node->left) - nodeHeight(node->right));

    // 4. daca nodul nu este echilibrat

    // LL Case
    if ( k>1 && (data.points < node->left->team.points || strcmp(node->left->team.team_name,data.team_name)>0)) return rightRotation(node);

    // RR Case
    if ( k<-1 && (data.points > node->right->team.points || strcmp(node->right->team.team_name,data.team_name)<0)) return leftRotation(node);

    // LR Case
    if ( k>1 && (data.points > node->left->team.points || strcmp(node->left->team.team_name,data.team_name)<0)) return LRRotation(node);

    // RL Case
    if ( k<-1 && (data.points < node->right->team.points || strcmp(node->right->team.team_name,data.team_name)>0)) return RLRotation(node);


    return node ;
}

void printLevel(NodeAVL* root , int level,FILE *f){

    if (root == NULL) return;

    if (level == 1) 
        fprintf (f,"%s\n",root->team.team_name);
    else if (level > 1) {
        printLevel(root->right,level-1,f);
        printLevel(root->left,level-1,f);
    }

}