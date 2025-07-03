#include "SearchType.h"
#include<stdio.h>

int BinarySearch(Element A[], int n, Element x)
{
	int high = n , low = 0, mid;
	while (low <= high)
	{
		mid = (low + high)/2;
		if ( x == A[mid])
			return mid;
		else if (x > A[mid])
			low = mid +1;
		else if (x < A[mid])
			high = mid -1;
		}
	return -1;
}
