#include <stdio.h>
#include "ShellSort.h"
#include "InsertionSort.h"
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 1000000

/**
 * 这个文件用来比较算法效率，验证排序结果是否正确
 */


int main(){
    
    // generate random array
    int i,randomNum;
    
    int size = 200000;
    printf("start generate random array\n");

    int dataForShell[MAXSIZE];   // array for shell sort copy from original array
    int dataForInsertSort[MAXSIZE];   // array for insertion sort copy from original array
    for(i = 0; i < size; i++){
        randomNum = rand();
	dataForShell[i] = randomNum;
        dataForInsertSort[i] = randomNum;
	// printf("%i \n",randomNum);
    }



    clock_t start,finish;
    double duration;

    printf("start sort the array in shell sort\n");
    start = clock();
    ShellSort(dataForShell,size);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    printf("finish sort the random array by shell sort ");
    printf( " in %f seconds\n", duration ); 

    printf("start sort the array in insertion sort\n");
    start = clock();
    InsertionSort(dataForInsertSort,size);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    printf("finish sort the random array in insertion sort ");
    printf( " in %f seconds\n", duration ); 

    printf("start comparing the sorted arrays: \n ");
    for( i = 0 ; i < size; i++){
	if( dataForShell[i] != dataForInsertSort[i] ){
             printf("diff element ,index: %d " ,i);
             break;
        }else{
	    // printf(" result: dataForShell[%d]: %d  dataForInsertSort[%d]: %d \n",i,dataForShell[i],i,dataForInsertSort[i]);
        }
    }
    printf(" finish comaring sorted arrays!");
    
}









