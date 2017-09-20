/*
Copyright (c) 2017,zs

This header file contains the 
definition of the Queue data structure and the implement  
using Array version

 */

#include <stdio.h>

struct QueueRecord;
typedef int ElementType;
typedef struct QueueRecord *Queue;

void MakeEmpty(Queue Q);
int IsEmpty(Queue Q);
void PrintQueue(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void Enqueque(ElementType X, Queue Q);
void Dequeue(Queue Q);
ElementType Front(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#define MinQueueSize (10)

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

void MakeEmpty(Queue Q){
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value,Queue Q)
{
    if( ++Value == Q->Size){
	Value = 0;
    }
    return Value;
}


// Array index return to (-1)
int IsEmpty(Queue Q){
    return Q->Size == 0;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;
    if(MaxElements < MinQueueSize){
	printf("Queue size is too small!");
    }

    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL){
	printf("Out of space! Error create Queue!");
    }

    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if(Q->Array == NULL){
	printf("Out of space! Error create Queue!");
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    
    return Q;
}

void DisposeQueue(Queue Q)
{
    if(Q != NULL){
	free(Q->Array);
	free(Q);
    }
}

int isFull(Queue Q){
    return Q->Size = Q->Capacity;
}

void Enqueque(ElementType X, Queue Q)
{
    if(isFulle(Q)){
	printf("Queue is full ,error Enqueue()");
    }else{
        Q->Size++;
	Q->Rear = Succ(Q->Rear,Q);
        Q->Array[Q->Rear] = X;
    }

}

void Dequeue(Queue Q)
{
    if(isEmpty(Q)){
	printf("Queue is empty ,dequeue failed!");
    }else{
	Q->Size--;
   	Q->Front = Succ(Q->Front,Q);
    }

}

ElementType Front(Queue Q)
{
    if(isEmtpy(Q)){
   	printf("Queue is empty ,front is NULL");
        return 0;
    }else{
        return Q->Array[Q->Front];
    }
}

ElementType FrontAndDequeue(Queue Q)
{
    if(isEmtpy(Q)){
   	printf("Queue is empty ,front is NULL");
        return 0;
    }else{
        ElementType front;
        front = Front(Q);
        Dequeue(Q);
        return front;
    }
}


void PrintQueue(Queue Q){
    printf("start print list");
    if(isEmpty(Q)){
	printf("Empty Queue,print nothing!");
    }else{
	while(!isEmpty(Q)){
	    print("%d",FrontAndDequeue(Q));
        }    
    } 
}


