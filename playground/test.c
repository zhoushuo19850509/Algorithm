#include <stdio.h>

int sum(int N);

int main(){
    printf("test algorithm ...\n");
    int result = sum(10);
    printf("result: %d \n", result);
}

int sum(int N){
    int sum;
    int i;

    for(i = 1; i <= N ; i++){
        sum += i * i * i;
    }

    return sum;
}
