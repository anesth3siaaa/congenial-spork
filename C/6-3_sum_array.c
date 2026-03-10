#include <stdio.h>
// this one is really similar to 2_fantasy_receipt
int numbers[] = {3, 1, 4, 1, 5};



int main()
{
    int lenght = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;
    for (int i = 0; i < lenght; i++) {
        sum += numbers[i];
    }
    printf("%d", sum);
    
    return 0;
}
