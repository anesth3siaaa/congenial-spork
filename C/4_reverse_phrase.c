#include <stdio.h>
#include <string.h>

int main() {

    char string[] = "hello";
    int i = 0;
    int j = strlen(string) - 1;
    char temp;
    
    while (i < j) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
    printf("%s", string);
    /*used to be printf(string), but as claude said:
    Using a variable directly as the format string can cause security issues down the line if the string ever contains % characters.
    */

    return 0;
}
