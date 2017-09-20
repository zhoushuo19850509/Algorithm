#include <stdlib.h>
#include <stdio.h>


#define max(a,b) a > b ? a : b

struct HeapStruct;
typedef int ElementType;
typedef struct HeapStruct *PriorityQueue;

void PrintQueue(PriorityQueue H);
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
int Height(PriorityQueue H);
ElementType FindMin(PriorityQueue H);

#define MinPQSize (10)
#define MinData 0


struct HeapStruct 
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

void PrintQueue(PriorityQueue H){
    int i;
    for( i = 1; i <= H->Size; i++){
	printf("%d ", H->Elements[i]);
    }
}

/*
 * Initialize the priority queue
 * alloc the memory for the priority struct nodes
*/
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;

    if( MaxElements < MinPQSize ){
        printf("Priority queue size is too small!");
    } 

    H = malloc( sizeof( struct HeapStruct ) );
    if( H == NULL ){
        printf("Out of Space! ");
    }

    // Element is actually an arry ,here we alloce the memory for this array
    H->Elements = malloc( (MaxElements + 1) * sizeof( ElementType) ); 
    if( H->Elements == NULL ){
	printf("Out of Space! ");
    }
    
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;

    return H;
}


void Destroy(PriorityQueue H){

}

void MakeEmpty(PriorityQueue H){

}

ElementType FindMin(PriorityQueue H)
{
    if( IsEmpty(H) ){
	printf("Empty Priority Queue!");
	return H->Elements[ 0 ];
    }
    return H->Elements[ 1 ];
}


/*
 * Insert an element into the priority queue,we should arrange a proper place for the new element
 * we search this proper place from leaves to top
*/
void Insert(ElementType X, PriorityQueue H)
{
    int i;

    if( IsFull(H)){
	printf("Priority is full!");
 	return ; 
    } 

    for( i = ++H->Size ; H->Elements[i / 2] > X; i /=2 ){
	H->Elements[i] = H->Elements[ i / 2 ];
    }
    H->Elements[i] = X;
}

/*
 * Delete the minimum element in the tree;
 * When the min element is deleted , leave a an empty hole in the tree!
 * So we should fill the hole ,from top to down
*/
ElementType DeleteMin(PriorityQueue H)
{
    int i,child;   
    ElementType LastElement, MinElement;

    if( IsEmpty( H )){
	printf("Priority queue is empty!");
	return H->Elements[0];
    }

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--]; 
    
    for( i = 1; i *2 <= H->Size; i = child){
 	child = i * 2;
	if( child != H->Size && H->Elements[ child + 1]
 			        < H->Elements[ child ] ){
	    child++; 
	}	
	if( LastElement > H->Elements[ child ])
  	{
	    H->Elements[ i ] = H->Elements[ child];
	}else{
	    break;
  	}
    }
    H->Elements[ i ] = LastElement;
    return MinElement;
}



/*
 * @return after delete the Node,return the deleted Tree
*/
PriorityQueue Delete(ElementType X, PriorityQueue H)
{
    return NULL;
}



void PrintTree(PriorityQueue H){
    int i;
    for( i = 1; i < H->Size; i++){
	printf("%d" , H->Elements[ i ]);
    }


}

int Height(PriorityQueue H)
{
    int i, height;
    if( IsEmpty(H)){
	return 0;
    }
    for( i = H->Size, height = 1; i >1; i /=2 ){
        height++;
    }
    return height;
}




