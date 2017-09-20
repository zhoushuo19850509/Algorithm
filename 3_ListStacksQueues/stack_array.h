/*
Copyright (c) 2017,zs

This header file contains the 
definition of the Stack data structure and the implement  
using array version

 */

#include <stdio.h>

struct StackRecord;
typedef int ElementType;
typedef struct StackRecord *Stack;

void MakeEmpty(Stack S);
int IsEmpty(Stack S);
void PrintStack(Stack S);
int SizeOfStack(Stack S); 
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void Push(ElementType X, Stack S);
void Pop(Stack S);
ElementType Top(Stack S);
ElementType TopAndPot(Stack S);


#define EmptyTOS (-1)   // 这个变量是空Stack的Top标志.Top Of Stack
#define MinStackSize (10)

struct StackRecord{
    int Capacity;
    int TopOfStack;
    ElementType *array;
};

void MakeEmpty(Stack S){
   S->TopOfStack = EmptyTOS; 
}

// array index return to (-1)
int IsEmpty(Stack S){
    return S->TopOfStack == EmptyTOS;
}

Stack CreateStack(int MaxElements)
{
    Stack S;
    if(MaxElements < MinStackSize){
	printf("Stack size if too small!");
    }

    S = malloc(sizeof(struct StackRecord));
    if(S == NULL){
	printf("Out of space! Error create Stack!");
    }

    S->array = malloc(sizeof(ElementType) * MaxElements);
    if(S->array == NULL){
	printf("Out of space! Error create Stack!");
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    
    return S;
}

void DisposeStack(Stack S)
{
    if(S != NULL){
	free(S->array);
	free(S);
    }
}

void Push(ElementType X, Stack S)
{
    if(isFull(S)){
	printf("Full Stack");
    }else{
	S->array[++S->TopOfStack] = X;
    }
}


int isFull(Stack S){
    return S->TopOfStack == ( S->Capacity -1 );
}

void Pop(Stack S)
{
    if(isEmpty(S)){
	printf("Empty Stack ,can not pop() from Stack!");
    }else{
	S->TopOfStack--;
    }
}

ElementType Top(Stack S)
{
    if(!isEmpty(S)){
	return S->array[S->TopOfStack];
    }
    printf("Empty Stack!");
    return 0;
}

ElementType TopAndPop(Stack S)
{
    if(!isEmpty(S)){
	return S->array[S->TopOfStack--];
    }
    printf("Empty Stack!");
    return 0;
}

void PrintStack(Stack S){
    printf("start print list");
    if(isEmpty(S)){
	printf("Empty Stack,print nothing!");
    }else{
	while(!isEmpty(S)){
	    print("%d",S->array[S->TopOfStack--]);
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
    if(isEmpty(S)){
	printf("empty Stack !");
	return 0;
    }else{
	return S->TopOfStack + 1;
    }    
} 

