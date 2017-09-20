#include "list.h"
#include <stdio.h>

List MakeEmpty(List L);
void PrintList(List L);    
// void PrintNode(Position P);

int main(){
    printf("start using list! \n");
    List L;
    L = MakeEmpty(L);
    ElementType t = 3;
    Insert(t,L,L);
    
    int i;
    for(i = 0 ; i < 10 ; i++){
        Insert(i,L,L->Next);
    }

    int size = 0;
    size = SizeOfList(L);
    printf("size of the list: %d \n",size);

    PrintList(L); 
}
