


#include <stdio.h>

int main(){
    printf("hello\n");
    int a[10];
    a[0] = 1;
    a[1] = 19;
    a[2] = 5;
    a[3] = 11;
    int N = 4;


    int i;
    printf("start print array A\n");
    for(i = 0; i < N; i++){
        printf("a[%d]:%d \n",i,a[i]);
    }

    int b[10];
    for(i = 0; i < N; i++){
        b[i] = a[i];
    }

    // a[0] = 99;
    printf("start print array B\n");
    for(i = 0; i < N; i++){
        printf("b[%d]:%d \n",i,b[i]);
    }

    int c[10];
    for(i = 0; i < N; i++){
        c[i] = a[i];
    }

    printf("start print array C\n");
    for(i = 0; i < N; i++){
        printf("c[%d]:%d \n",i,c[i]);
    }

}
