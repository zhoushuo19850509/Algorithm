#include <stdio.h>
#include "ShellSort.h"
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 1000000
int main(){
    
    // generate random array
    int i;
    int data[MAXSIZE];
    int size = 100000;
    printf("generate random array");
    for(i = 0; i < size; i++){
	data[i] = rand();
	// printf("%i \n",data[i]);
    }

    printf("start sort the random array");
    clock_t start,finish;
    double duration;

    start = clock();
    ShellSort(data,size);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    printf("finish sort the random array");
    printf( "%f seconds\n", duration ); 
  
    
}
