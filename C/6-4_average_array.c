#include <stdio.h>
// this one is really similar to 2_fantasy_receipt
int numbers[] = {3, 1, 4, 1, 5};



int main()
{
    int lenght = sizeof(numbers) / sizeof(numbers[0]);
    float sum = 0;
    for (int i = 0; i < lenght; i++) {
        sum += numbers[i];
    }
    sum /= lenght;
    printf("%.1f", sum); //.n tells floats and doubles how many decimals
    
    return 0;
}
