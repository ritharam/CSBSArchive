#include<stdio.h>
#include "polyhead.h"

int main () {
	POLY A, B, C;
	printf("Enter the details of Polynomial A:");
	A = createPoly();
	printf("Enter the details of Polynomial B:");
	B = createPoly();
	C = addPoly(A,B);
	printf("\nPolynomial A: ");
	displayPoly(A);
	printf("\nPolynomial B: ");
	displayPoly(B);
	printf("\nPolynomial C: ");
	displayPoly(C);
	deletePoly(A);
	deletePoly(B);
	deletePoly(C);
	return 0;
}