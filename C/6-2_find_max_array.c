#include <stdio.h>

int numbers[] = {3, 1, 4, 1, 5};



int main()
{
    int lenght = sizeof(numbers) / sizeof(numbers[0]);
    int max = numbers[0];
    for (int i = 0; i < lenght; i++) {
        if (numbers[i] > max) { // for max change "<" to ">"
            max = numbers[i];
        }
    }
    printf("%d", max);
    
    return 0;
}
// only changes are the first mentioned and changing every mention of min to max
