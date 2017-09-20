
#include <stdio.h>
#include "InsertionSort.h"
#include <stdlib.h>

int main(){
    printf("hello\n");
    int a[10];
    a[0] = 1;
    a[1] = 19;
    a[2] = 5;
    a[3] = 11;
    int N = 4;


    int i;
    printf("sort before");
    for(i = 0; i < N; i++){
        printf("a[%d]:%d \n",i,a[i]);
    }

    InsertionSort(a,4);
    printf("after before");
    for(i = 0; i < N; i++){
        printf("a[%d]:%d \n",i,a[i]);
    }


    // test rand() function
    unsigned int seed = 10;
    srand(seed);
    printf("print random");
    for(i = 0; i < 10; i++){
        printf("%i \n",rand());
    }

    swap(a,0,1);
    printf("%d,\t %d",a[0],a[1]);
}
