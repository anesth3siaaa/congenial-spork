#include <stdio.h>

int numbers[] = {3, 1, 4, 1, 5};



int main()
{
    int lenght = sizeof(numbers) / sizeof(numbers[0]);
    int min = numbers[0];
    for (int i = 0; i < lenght; i++) { // ALWAYS DECLARE THAT I IS AN INTEGER
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    printf("%d", min);
    
    return 0;
}
