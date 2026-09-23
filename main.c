#include <stdio.h>

#define NUM_ITEMS 5 // Number of distinct items the backpack can hold

// Uses the arrays with index i being the same across all 3
char itemNames[NUM_ITEMS][30] = {"Pencil", "Pen", "Notebook", "Calculator", "Eraser"};
int itemMaxCap[NUM_ITEMS] = {10, 10, 3, 1, 5};
int itemCounts[NUM_ITEMS] = {0, 0, 0, 0, 0};

// Adds amount of the item at index to the backpack.
// Returns 1 on success and 0 if it goes over the max or is invalid. This is for boolean purposes.
int addItem(int index, int amount) {
    if(index < 0 || index >= NUM_ITEMS){
        printf("Invalid item selection.\n");
        return 0;
    }
    if (amount <= 0){
        printf("Amount must be positive.\n");
        return 0;
    }
    if (itemCounts[index] + amount > itemMaxCap[index]){
        printf("Cannot add %d to %s(s), only room for %d more.\n", amount, itemNames[index], itemMaxCap[index] - itemCounts[index]);
        return 0;
    }

    itemCounts[index] += amount;
    printf("Added %d to %s(s). Now have %d/%d.\n", amount, itemNames[index], itemCounts[index], itemMaxCap[index]);
    return 1;
}

// Removes amount of the item at index to the backpack.
// Returns 1 on success and 0 if it goes under the 0 or is invalid. This is for boolean purposes.
int removeItem(int index, int amount){
    if (index < 0 || index >= NUM_ITEMS){
        printf("Invalid item selection.\n");
        return 0;
    }
    if (amount <= 0){
        printf("Amount must be positive.\n");
        return 0;
    }
    if (itemCounts[index] - amount < 0){
        printf("Cannot remove %d %s(s), only have %d.\n", amount, itemNames[index], itemCounts[index]);
        return 0;
    }

    itemCounts[index] -= amount;
    printf("Removed %d %s(s). Now have %d/%d.\n", amount, itemNames[index], itemCounts[index], itemMaxCap[index]);
    return 1;
}

// Quick demo
int main(void) {
    addItem(0, 3);
    addItem(2, 1);
    addItem(2, 5);
    removeItem(0, 1);
    removeItem(3, 1);

    return 0;
}