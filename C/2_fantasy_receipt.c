#include <stdio.h>

typedef struct { /* typedef makes struct use the alias "Item" for comodity */
    char name[50];
    int price; /* Prices are in a virtual currency that's why it's int */
} Item;

Item shop[] = { /* REMEMBER TO ADD = WHEN MAKING LISTS */
    {"Healing Potion", 20},
    {"Orc Meat", 33},
    {"Element Core", 60},
    {"Wand", 26},
    {"Sorcery Manual", 41},
};




int main() {
    /* Declare n inside main, sizeof can't be evaluated at global scope */
    int n = sizeof(shop) / sizeof(shop[0]);
    int sum = 0;
    
    for (int i = 0; i < n; i++) { /* "for" needs ; not , */
        printf("%-20s %d G\n", shop[i].name, shop[i].price);
        
        sum += shop[i].price; /* C runs code line for line 
        that's why sum is AFTER shop[i].price is read after.
        This runs in "for" cus it adds the price every time
        the loop runs.*/
        
        /* it actually runs statement by statement but for the sake
        of my own understanding, I'll think of it as line by line. */
    }
    printf("\nTOTAL               %d G\n", sum );

    return 0;
}
