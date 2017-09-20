


typedef int ElementType;

void ShellSort(ElementType A[], int N)
{

    int i;
    int j;
    int Increment;
    ElementType Tmp;

    for( Increment = N / 2 ; Increment > 0 ; Increment /= 2 ){
	for( i = Increment; i < N; i++){
            Tmp = A[i];
	    for( j = i; j - Increment >= 0 ; j -= Increment){
		if( Tmp < A[ j - Increment]){
		    A[j] = A[ j - Increment];
		}else{
		    break;
		}
	    }   // end of j loop
	    A[j] = Tmp;
	}   // end of i loop
    }   // end of Increment loop
}

