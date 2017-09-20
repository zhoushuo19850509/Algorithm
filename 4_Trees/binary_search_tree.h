
#include <stdio.h>


#define max(a,b) a > b ? a : b

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Position;

void PrintTree(SearchTree T);
void PrintElement(ElementType Element);
int Height(SearchTree T);
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};


SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL){
	MakeEmpty(T->Left);
	MakeEmpty(T->Right);
	Free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if( T == NULL ){
	return NULL;    /* find nothing at this node*/
    } 
    if( X < T->Element){
	return Find( X, T->Left );
    }else if( X > T->Element){
	return Find( X, T->Right );
    }else{
  	return T;    /* finally find Element!*/
    }
}

Position FindMin(SearchTree T)
{
    if( T == NULL){
	return NULL;
    }else if( T->Left == NULL){
	return T;      /*the leftest node of the Tree,this is the min one!*/
    }else{
	return FindMin(T->Left);
    }

}

Position FindMax(SearchTree T)
{
    if( T == NULL){
	return NULL;
    }else if( T->Right == NULL){
	return T;      /*the rightest node of the Tree,this is the max one!*/
    }else{
	return FindMax(T->Right);
    }
    
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL){
	T = malloc(sizeof(struct TreeNode));
        if( T == NULL){
	    printf("error alloc new tree node!");
	}
	T->Element = X;
        T->Left = T->Right = NULL;
    }
    if( X < T->Element){
	return Insert(X,T->Left);
    }else if( X > T->Element){
        return Insert(X,T->Right);
    }
    return T;
}


/*
 * @return after delete the Node,return the deleted Tree
*/
SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if( T == NULL ){
        printf("delete nothing ,element not found");
    }
    if( X < T->Element){
	T->Left = Delete(X, T->Left);
    }else if(X > T->Element){
	T->Right = Delete(X, T->Right);
    }else if( T->Left && T->Right ){  /*two children*/
	TmpCell = FindMin( T->Right );
        T->Element = TmpCell->Element;
	T->Right = Delete(T->Element, T->Right );
    }else{                    /*one or zero children*/
        TmpCell = T;
	if( T->Left == NULL ){
	    TmpCell = T;
            T = T->Right;
	}else if( T->Right == NULL ){
	    TmpCell = T;
	    T = T->Left;
	}
	free(TmpCell);
    }
    return T;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}


void PrintTree(SearchTree T){
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

int Height(SearchTree T)
{
    if(T == NULL){
	return -1;
    }else{
	return 1 + max( Height( T->Left ),
                        Height( T->Right ));
    }    
}





