
#include <stdio.h>


#define max(a,b) a > b ? a : b

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode *Tree;

void PrintTree(Tree T);
void PrintElement(ElementType Element);
int Height(Tree T);

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};


void PrintTree(Tree T){
    if(T != NULL){
	PrintTree(T->Left);
        PrintElement(T->Element);
	PrintTree(T->Right);
    }
}

void PrintElement(ElementType Element)
{
    printf("Element: %d",Element);
}

int Height(Tree T)
{
    if(T == NULL){
	return -1;
    }else{
	return 1 + max( Height( T->Left ),
                        Height( T->Right ));
    }    
}





