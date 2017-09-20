
#include <stdio.h>

#define max(a,b) a > b ? a : b

struct HeapStruct;
typedef int ElementType;
typedef struct TreeNode *PriorityQueue;

void PrintTree(PriorityQueue H);
void PrintElement(ElementType Element);
PriorityQueue Initialize(void );
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int Height(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2 );

#define MinPQSize (10)
#define MinData 0


struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int  Npl;
};

static void SwapChildren( PriorityQueue H)
{
     PriorityQueue TmpNode;
     TmpNode = H->Left;
     H->Left = H->Right;
     H->Right = TmpNode;    
} 

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2 )
{
    if( H1->Left == NULL){
	H1->Left = H2;
    }else{
	H1->Right = Merge( H1->Right, H2);
        if( H1->Left->Npl < H1->Right->Npl){
	    SwapChildren( H1 );
	}
	H1->Npl = H1->Right->Npl + 1;  
        // 为啥要在这里更新呢?很简单,我们完成合并后,H1左右两个子节点的高度可能发生了变化;
        // 为啥是在右节点的基础上加1呢?很简单,因为右节点is always no greater than the left node
        // so ,the npl of the current node is the right node plus 1;
    }
    return H1;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2 )
{
    if( H1 == NULL ){
	return H2;
    }
    if( H2 == NULL ){
	return H1;
    }
    if( H1->Element < H2->Element ){
	return Merge1( H1, H2 );
    }else{
	return Merge1( H2, H1);
    }
}

int IsEmpty(PriorityQueue H)
{
    return H == NULL;
}

int IsFull(PriorityQueue H)
{
    return 0;
}

void PrintQueue(PriorityQueue H){
}

/*
 * Initialize the priority queue
 * alloc the memory for the priority struct nodes
*/
PriorityQueue Initialize(void)
{
    return NULL;
}

void Destroy(PriorityQueue H){

}

void MakeEmpty(PriorityQueue H){

}

ElementType FindMin(PriorityQueue H)
{
    if( IsEmpty(H) ){
	printf("Empty Priority Queue!");
    }
    return H->Element;
}


/*
 * Insert an element into the priority queue,we should arrange a proper place for the new element
 * we search this proper place from leaves to top
*/
PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode));
    if( SingleNode == NULL ){
	printf("error create new node");
    }else{
	SingleNode->Element = X;
	SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode, H);
    }
    return H;
}

/*
 * Delete the minimum element in the tree;
 * When the min element is deleted , leave a an empty hole in the tree!
 * So we should fill the hole ,from top to down
*/
PriorityQueue DeleteMin1(PriorityQueue H)
{
    int i,child;   
    PriorityQueue LeftHeap, RightHeap;

    if( IsEmpty( H )){
	printf("Priority queue is empty!");
    }

    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap,RightHeap);

}



/*
 * @return after delete the Node,return the deleted Tree
*/
PriorityQueue Delete(ElementType X, PriorityQueue H)
{
    return NULL;
}



void PrintTree(PriorityQueue H){
     if(H != NULL){
        PrintTree(H->Left);
        PrintElement(H->Element);
        PrintTree(H->Right);
    }
}

void PrintElement(ElementType Element)
{
    printf("Element: %d",Element);
}

int Height(PriorityQueue H)
{
    return 0;
}




