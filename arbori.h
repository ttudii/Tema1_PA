#include "team.h"

//arbore BST

struct BST{
    Team team;
    struct BST *left,*right;
};

typedef struct BST NodeBST;

NodeBST* newNode(Team data);
NodeBST* insertBST(NodeBST * node, Team team);
void ReverseInorder(NodeBST* root,FILE *f,Node **listAVL);

//arbore AVL

struct AVL{
    Team team;
    int height;
    struct AVL *left,*right;
};

typedef struct AVL NodeAVL;

int nodeHeight(NodeAVL* root);
int max(int a,int b);
NodeAVL* RightRotation(NodeAVL * z);
NodeAVL* LeftRotation(NodeAVL* z);
NodeAVL* LRRotation(NodeAVL* Z);
NodeAVL* RLRotation(NodeAVL* Z);
NodeAVL* insertAVL(NodeAVL * node ,Team data);
void printLevel(NodeAVL * root , int level,FILE *f);