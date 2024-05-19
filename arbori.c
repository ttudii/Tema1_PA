#include "arbori.h"

//structura noua pentru noduri de tip arbore

NodeBST* newNode (Team data){

    NodeBST* node = (NodeBST*)malloc(sizeof(NodeBST));
    node->team = data;
    node->left = node->right = NULL ;

    return node;
}

NodeBST* insert (NodeBST* node,Team data) {

    // daca ( sub ) arborele este gol , creaza nod
        if (node == NULL) return newNode(data);

    // altfel , coboara la stanga sau dreapta
        if (data.points < node->team.points)
            node->left = insert(node->left, data);
        else if (data.points > node->team.points)
            node->right = insert(node->right,data);
        else if (data.points==node->team.points){
            if(strcmp(node->team.team_name,data.team_name)<0){
            node->right=insert(node->right,data);
            }
            else
            node->left=insert(node->left,data);
        }
    // ! pointerul node se intoarce nemodificat pe acest return
    return node ;
 
} // ! nu se adauga elemente egale

void ReverseInorder(NodeBST* root,FILE *f,char file[]){

    if(root){
        ReverseInorder(root->right,f,file);
        fprintf(f,"%s",root->team.team_name);
		for(int i=0;i<34-strlen(root->team.team_name);i++){
			fprintf(f," ");
		}
		fprintf(f,"-  ");
		fprintf(f,"%.2f\n",root->team.points);
        ReverseInorder(root->left,f,file);
    }
}