#include <stdio.h>

// structure one with random alignment 
struct Date_1
{
   int day;
   int month;
   char year;
} v1;

// structure two with ordered alignment
struct Date_2
{
   int day : 4;
   //int month : 4;
   float year:1;
} v2;

int main()
{
    // printing size of both structures
    printf("Size of Date_1 is: %lu\n",sizeof(v1)); // 12
    printf("Size of Date_2 is: %lu\n",sizeof(v2)); // 8
}
