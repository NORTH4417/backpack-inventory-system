#include <stdio.h>

#define NUM_ITEMS 5 // Number of distinct items the backpack can hold

// Uses the arrays with index i being the same across all 3
char itemNames[NUM_ITEMS][30] = {
    "Pencil", "Pen", "Notebook", "Calculator", "Eraser"
};
// creates the indexes of each item type 
int itemMaxCap[NUM_ITEMS] = {10, 10, 3, 1, 5};
// these are the max amount of items you can put for each type 
int itemCounts[NUM_ITEMS] = {0, 0, 0, 0, 0};
// these are the default number of items in the backpack, since the backpack is empty this is going to start at zero 


// Adds amount of the item at index to the backpack.
// Returns 1 on success and 0 if it goes over the max or is invalid. This is for
// boolean purposes.
int addItem(int index, int amount) {
    if (index < 0 || index >= NUM_ITEMS) {
        printf("Invalid item selection.\n");
        return 0;
    }
    // this basically checks if the index is within the bounds that are given in NUM_ITEMS

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return 0;
    }
    // when adding an item, this makes sure the number of items you are adding are positive 

    if (itemCounts[index] + amount > itemMaxCap[index]) {
        printf(
            "Cannot add %d to %s(s), only room for %d more.\n",
            amount,
            itemNames[index],
            itemMaxCap[index] - itemCounts[index]
        );
        return 0;
    }
    // if you are trying to put too much of a certain item in the backpack the program prints out a statement
    // that tells how much of that item you can add to the backpack

    itemCounts[index] += amount;
    // adds the amount of items you want to put into your backpack 

    printf(
        "Added %d to %s(s). Now have %d/%d.\n",
        amount,
        itemNames[index],
        itemCounts[index],
        itemMaxCap[index]
    );
    return 1;
    // 
}

// Removes amount of the item at index to the backpack.
// Returns 1 on success and 0 if it goes under the 0 or is invalid. This is for
// boolean purposes.
int removeItem(int index, int amount) {
    if (index < 0 || index >= NUM_ITEMS) {
        printf("Invalid item selection.\n");
        return 0;
    }
    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return 0;
    }
    if (itemCounts[index] - amount < 0) {
        printf(
            "Cannot remove %d %s(s), only have %d.\n",
            amount,
            itemNames[index],
            itemCounts[index]
        );
        return 0;
    }

    itemCounts[index] -= amount;
    printf(
        "Removed %d %s(s). Now have %d/%d.\n",
        amount,
        itemNames[index],
        itemCounts[index],
        itemMaxCap[index]
    );
    return 1;
}

// function to view current inventory
int viewInventory(void) {
    printf("Current Inventory:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%ss: %d/%d\n", itemNames[i], itemCounts[i], itemMaxCap[i]);
    }
    return 0;
}

// Quick demo
int main(void) {
    addItem(0, 3);
    addItem(2, 1);
    addItem(2, 5);
    removeItem(0, 1);
    removeItem(3, 1);
    viewInventory();

    return 0;
}
