#include <stdio.h>


int numbers[] = {3, 1, 4, 1, 5};
int lenght = sizeof(numbers) / sizeof(numbers[0]);

int findMin(int numbers[], int lenght) { // DECLARE TYPE IN FUNC
    int min = numbers[0];
    for (int i = 0; i < lenght; i++) { // ALWAYS DECLARE THAT I IS AN INTEGER
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int findMax(int numbers[], int lenght) { // DECLARE TYPE IN FUNC
     int max = numbers[0];
    for (int i = 0; i < lenght; i++) {
        if (numbers[i] > max) { // for max change "<" to ">"
            max = numbers[i];
        }
    }
    return max;
}

int findSum(int numbers[], int lenght) { // DECLARE TYPE IN FUNC
    int sum = 0;
    for (int i = 0; i < lenght; i++) {
        sum += numbers[i];
    }
    return sum;
}

float findAvg(int numbers[], int lenght) { // did you get it by now?
     float sum = 0;
    for (int i = 0; i < lenght; i++) {
        sum += numbers[i];
    }
    sum /= lenght;
    return sum; //.n tells floats and doubles how many decimals
}




int main()
{
    printf("The array: ");
    for (int i = 0; i < lenght; i++) {
        if (i == lenght -1 ) { // to check for last digit in array
            printf("%d\n", numbers[i]);
        } else {
            printf("%d, ", numbers[i]);
        }
    }
    
    printf("Smallest: %d\n", findMin(numbers, lenght));
    printf("Biggest: %d\n", findMax(numbers, lenght));
    printf("Sum: %d\n", findSum(numbers, lenght));
    printf("Average: %.1f", findAvg(numbers, lenght));
    // when returning, just write the name and nothing else. AND NO INT.
    
    return 0; // build this habit
}
