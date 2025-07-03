#include "SearchType.h"
#include<stdio.h>

int RBinarySearch(Element A[], int low, int high, Element x){
    if(low>high){
        return -1;
    }
    else{
        int mid = (low+high)/2;
        if ( x == A[mid]) 
            return mid;
        else if (x > A[mid]) 
            return RBinarySearch(A, mid+1, high,  x);
        else 
            return RBinarySearch(A, low, mid-1,  x);
    }

}
