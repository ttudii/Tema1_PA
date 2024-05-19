#include "team.h"

struct BST{
    Team team;
    struct BST *left,*right;
};

typedef struct BST NodeBST;

NodeBST* newNode (Team data);
NodeBST* insert (NodeBST * node, Team team);
void ReverseInorder(NodeBST* root,FILE *f,char file[]);