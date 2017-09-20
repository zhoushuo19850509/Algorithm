/*
Copyright (c) 2017,zs

This header file contains the 
definition of the Stack data structure and the implement  
using list version

 */

#include <stdio.h>

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

void MakeEmpty(Stack S);
int IsEmpty(Stack S);
void PrintStack(Stack S);
int SizeOfStack(Stack S); 
Stack CreateStack(void);
void DisposeStack(Stack S);
void Push(ElementType X, Stack S);
void Pop(Stack S);
ElementType Top(Stack S);

struct Node{
    ElementType Element;
    PtrToNode Next;
};

void MakeEmpty(Stack S){
    if(S == NULL){
	printf("must create a Stack first!");
    }else{
	while(!isEmpty(S)){
	     Pop(S);
	}
    }
    
}

int IsEmpty(Stack S){
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S == NULL){
	printf("out of space!");
    }
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)
{

}

void Push(ElementType X, Stack S)
{
    PtrToNode tmpCell;
    tmpCell = malloc(sizeof(struct Node));
    if(tmpCell ==NULL){
	printf("out of space!");
    }else{
        tmpCell->Element = X;
        tmpCell->Next = S->Next;
        S->Next = tmpCell;
    }
}

void Pop(Stack S)
{
    PtrToNode TmpCell;
    if(isEmpty(S)){
        printf("Empty Stack!");
    }else{
        TmpCell = S->Next;
        S->Next = TmpCell->Next;
        free(TmpCell);
    }
}

ElementType Top(Stack S)
{
    if(!isEmpty(S)){
	return S->Next->Element;
    }
    printf("Empty Stack!");
    return 0;
}

void PrintStack(Stack S){
    printf("start print list");
    PtrToNode P;
    if(isEmpty(S)){
	printf("Empty Stack,print nothing!");
    }else{
        P = S->Next;
        while(P != NULL){
            printf("%d ",P->Element);
            P = P->Next;
        }
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
int SizeOfStack(Stack S){
    int size = 0;
    PtrToNode P;
    if(isEmpty(S)){
	printf("empty Stack !");
	return 0;
    }else{
        P = S->Next;
        while(P != NULL){
 	    size++;
            P = P->Next;
        }
        return size;
    }
} 

