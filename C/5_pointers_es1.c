#include <stdio.h>


void swap(int *p1, int *p2) { 
    int temp = *p1; // temp grabs the value of *p1 (6)
    *p1 = *p2;      // *p1 now grabs the value of *p2 (7)
    *p2 = temp;     // *p2 now grabs the value of temp (6, which grabbed from *p1)
}
/* By giving the swap function these parameters I'm telling it what the 
    pointers are pointing towards when the values I want it to swap
    are declared inside of the swap call of main */


int main()
{
    
    int a = 6;
    int b = 7;
    printf("Before swap: %d, %d\n", a, b);
    swap(&a, &b); /* This tells swap that p1 = &a and p2 = %b */
    printf("After swap: %d, %d\n", a, b);

    return 0;
}
