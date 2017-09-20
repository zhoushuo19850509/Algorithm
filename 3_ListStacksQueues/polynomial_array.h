/*
 * this file contains the array implementation of polynomial
*/

#define MaxDegree 1000
#define max(a,b) a > b ? a : b


typedef struct
{    
    int CoeffArray[ MaxDegree + 1 ];
    int HighPower;
}* Polynomial;

void ZeroPolynomial(Polynomial Poly)
{
    int i;
    for( i = 0; i < MaxDegree; i++){
	Poly->CoeffArray[i] = 0;
        Poly->HighPower = 0;
    }
}

void AddPolynomial( Polynomial Poly1, Polynomial Poly2, Polynomial PolySum)
{
    PolySum->HighPower = max(Poly1->HighPower,Poly2->HighPower);
    int i;
    for( i = 0 ; i <= PolySum->HighPower; i++){
	PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }
    
}


void MultPolynomial(const Polynomial Poly1,const Polynomial Poly2, Polynomial PolyProd)
{
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

    if( PolyProd->HighPower > MaxDegree){
	printf("error!");
    }else{
         
        int i,j;
    for( i = 0; i <= PolyProd->HighPower; i++){
	for( j = 0; j <= i; i++){
 	    PolyProd->CoeffArray[i] += Poly1->CoeffArray[j] * Poly2->CoeffArray[i-j];
        }
    }
    }

    int i,j;
    for( i = 0; i <= PolyProd->HighPower; i++){
	for( j = 0; j <= i; i++){
 	    PolyProd->CoeffArray[i] += Poly1->CoeffArray[j] * Poly2->CoeffArray[i-j];
        }
    }
}



