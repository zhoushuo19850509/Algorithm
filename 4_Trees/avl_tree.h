
#include <stdio.h>


#define max(a,b) a > b ? a : b

struct AvlNode;
typedef int ElementType;
typedef struct AvlNode *AvlTree;
typedef struct AvlNode *Position;

void PrintTree(AvlTree T);
void PrintElement(ElementType Element);
static int Height(Position P);
AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
// AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
static Position SingleRotateWithLeft(Position P);
static Position DoubleRotateWithLeft(Position P);
static Position SingleRotateWithRight(Position P);
static Position DoubleRotateWithRight(Position P);

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int     Height;
};


AvlTree MakeEmpty(AvlTree T)
{
    if(T != NULL){
	MakeEmpty(T->Left);
	MakeEmpty(T->Right);
	Free(T);
    }
    return NULL;
}

Position Find(ElementType X, AvlTree T)
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

Position FindMin(AvlTree T)
{
    if( T == NULL){
	return NULL;
    }else if( T->Left == NULL){
	return T;      /*the leftest node of the Tree,this is the min one!*/
    }else{
	return FindMin(T->Left);
    }

}

Position FindMax(AvlTree T)
{
    if( T == NULL){
	return NULL;
    }else if( T->Right == NULL){
	return T;      /*the rightest node of the Tree,this is the max one!*/
    }else{
	return FindMax(T->Right);
    }
    
}

AvlTree Insert(ElementType X, AvlTree T)
{
    if(T == NULL){
	T = malloc(sizeof(struct AvlNode));
        if( T == NULL){
	    printf("error alloc new tree node!");
	}
	T->Element = X;
	T->Height = 0;
        T->Left = T->Right = NULL;
    }
    if( X < T->Element){
	T->Left = Insert(X,T->Left);
	if( (Height(T->Left) - Height(T->Right)) == 2){
	    if( X < T->Left->Element){
 	        T = SingleRotateWithLeft(T);
	    }else{
	        T = DoubleRotateWithLeft(T);
	    }
	}
    }else if( X > T->Element){
        T->Right =  Insert(X,T->Right);
	if( (Height(T->Right) - Height(T->Left)) == 2){
	    if( X > T->Right->Element){
 	        T = SingleRotateWithRight(T);
	    }else{
	        T = DoubleRotateWithRight(T);
	    }
	}
    }

    return T;
}


/*
 * @return after delete the Node,return the deleted Tree
*/
// AvlTree Delete(ElementType X, AvlTree T)

ElementType Retrieve(Position P)
{
    return P->Element;
}


void PrintTree(AvlTree T){
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

static int Height(Position P)
{
   if(P == NULL){
	return -1;
    }else{
	return P->Height;
    }    
}

static Position SingleRotateWithLeft(Position P)
{
    Position TmpCell;

    TmpCell = P->Left;
    P->Left = TmpCell->Right;
    TmpCell->Right = P;

    P->Height = Max(Height(P->Right),Height(P->Left)) + 1;
    TmpCell->Height = Max(Height(TmpCell->Left),Height(TmpCell->Right)) + 1;
    return TmpCell;
}
static Position DoubleRotateWithLeft(Position P)
{
    P->Left = SingleRotateWithRight(P->Left);
    return SingleRotateWithLeft(P);
}

static Position SingleRotateWithRight(Position P)
{
    Position TmpCell;

    TmpCell = P->Right;
    P->Right = TmpCell->Left;
    TmpCell->Left = P;

    P->Height = Max(Height(P->Right),Height(P->Left)) + 1;
    TmpCell->Height = Max(Height(TmpCell->Left),Height(TmpCell->Right)) + 1;
    return TmpCell;
    
}

static Position DoubleRotateWithRight(Position P){
    P->Right = SingleRotateWithLeft(P->Right);
    return SingleRotateWithRight(P);
}
