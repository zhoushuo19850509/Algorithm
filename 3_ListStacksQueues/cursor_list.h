/**
 * this files contains the implementation of cursor implementation of list
 * which use array instead of pointer
*/


#define SpaceSize 1000

typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, const List L);
void Insert(ElementType X, List L, Position P);
Position FindPrevious(ElementType X, List L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void PrintList(List L);
int SizeOfList(List L);

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[ SpaceSize ];


static Position CursorAlloc(void)
{
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next; 

    return P;
}

/*
 * free() of Position is straightforwd:
 * set the Postion P into the next of array[0]
*/
static void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

int isEmpty(List L)
{
    return CursorSpace[L].Next == 0; 
}
 
int isLast(Position P, List L)
{
    return CursorSpace[P].Next == 0;
}


Position Find(ElementType X, List L)
{
    Position P;
    P = CursorSpace[L].Next;
    while( P && CursorSpace[P].Element != X ){
        P = CursorSpace[P].Next;
    }
    return P;
}

void Delete(ElementType X, const List L)
{
    Position P,TmpCell;
    P = FindPrevious(X,L);
    if( isLast(P,L) ){   // why use isLast() fucntion? see the definition of FindPrevious()
	TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
	CursorFree(TmpCell);
    }
}

// insert the Element X into the position after P
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = CursorAlloc();

    if(TmpCell != 0){
        CursorSpace[TmpCell].Element = X;    // set Element
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;  // set Next
        CursorSpace[P].Next = TmpCell;
    } else{
	printf("error alloc new Postion from List");
    }
}


Position FindPrevious(ElementType X, List L){
    Position P;

    P = L;
    while( CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X){
        P = CursorSpace[P].Next;
    }
    return P;
}







