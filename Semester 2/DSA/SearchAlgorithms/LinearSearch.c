#include "SearchType.h"
#include<stdio.h>

int LinearSearch(Element A[], int n, Element x)
{
	int i;
	for(i=0;i<n;i++){
		if(A[i]== x)
			return i;
	}
	return -1;
}


