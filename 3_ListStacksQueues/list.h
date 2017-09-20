/**
this header file contains the 
definition of the list data structure and the implement
*/

#include <stdio.h>

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
Position FindPrevious(ElementType X, List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void PrintList(List L);
// void PrintNode(Position P);
int SizeOfList(List L); 

struct Node{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L){
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    TmpCell->Next = NULL;
    // TmpCell->Element = NULL;
    return TmpCell;
}

int IsEmpty(List L){
    return L->Next == NULL;
}

int IsLast(Position P, List L){
    return P->Next == NULL;
}

Position Find(ElementType X, List L){
    Position P;

    P = L->Next;
    while( P != NULL && P->Element != X){
	P = P-> Next;
    }
    return P;
}


void Delete(ElementType X, List L){
    Position P,TmpCell;
    P = FindPrevious(X,L);   // find Positon of Element X in List L

    if(!IsLast(P,L)){   // assume header of P
	TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L){
    Position P;

    P = L;
    while( P->Next != NULL && P->Next->Element != X){
	P = P-> Next;
    }
    return P;
}

// insert the Element X into the position after P
void Insert(ElementType X, List L, Position P){
    Position TmpCell;
    // allocate memory for the new Inserted Node
    TmpCell = malloc(sizeof(struct Node));   
    if(TmpCell == NULL){
	printf("Out of Space");
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;

}

void DeleteList(List L){
    Position P,Tmp;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL){
	Tmp = P->Next;
        free(P); 
        P = Tmp;
    } 
}

void PrintList(List L){
    printf("start print list");
    Position P;
    P = L->Next;
    while(P != NULL){
        printf("%d ",P->Element);
        // printNode(P);
        P = P->Next;
    } 
}

// print the Element
// 注意:这个方法需要根据ElementType的不同,而作适当的调整
// 因为ElementType不一定是基本数据类型
/*
void PrintNode(Position P){
    printf("%d",P->Element);
}
*/
int SizeOfList(List L){
    int size = 0;
    Position P;
    P = L->Next;
    while(P != NULL){
	size++;
        P = P->Next;
    }
    return size;
} 

