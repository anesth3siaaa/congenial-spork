/*Second pointer esercise.
Prints x, resets (sets to 0) x with p,
prints x again.*/
#include <stdio.h>

int x = 20;
int *q = &x;

int reset() {
    int *p = &x;
    *p = 0;
    return x;
}

int main()
{
    printf("%d, %d\n", x, *q); reset(); printf("%d, %d\n", x, *q);
    return 0;
}
/*q changes immediately because it's constantly pointing to x.*/
