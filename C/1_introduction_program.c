#include <stdio.h>

int main()
{
    char name[30];      // reserves 30 bytes on the stack for a string (max 29 chars + '\0' terminator)
    int age;
    char activity[64];  // reserves 64 bytes on the stack for a longer string (max 63 chars + '\0')
  
    printf("Your name: ");
    scanf("%s", name);  // name is already a pointer to name[0], so no & needed unlike primitive types
    printf("Your age: ");
    scanf("%d", &age);  // &age passes the memory address of age so scanf knows where to write the value
    getchar();          // consumes the leftover '\n' in the input buffer from the previous scanf
    printf("Your favorite thing to do: ");
    fgets(activity, sizeof(activity), stdin);  // sizeof(activity) = 64, prevents writing past the buffer boundary
    printf("Hello, my name is %s. I'm %d and my favorite activity is %s", name, age, activity);
    return 0;
}
