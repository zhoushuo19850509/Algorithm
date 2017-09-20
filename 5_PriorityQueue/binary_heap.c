#include <stdio.h>
#include "binary_heap.h"

int main(){
    printf("hello");

    PriorityQueue H;
    H = Initialize(100);

    Insert(4,H);
    Insert(100,H);
    Insert(36,H);
    Insert(77,H);
    Insert(2,H);
    Insert(300,H);
    printf("\n size of priority queue: %d \n",H->Size );
    PrintQueue(H); 
}


