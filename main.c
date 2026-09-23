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
        return 1;
    }
    // this basically checks if the index is within the bounds that are given in NUM_ITEMS

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return 1;
    }
    // when adding an item, this makes sure the number of items you are adding are positive 

    if (itemCounts[index] + amount > itemMaxCap[index]) {
        printf(
            "Cannot add %d to %s(s), only room for %d more.\n",
            amount,
            itemNames[index],
            itemMaxCap[index] - itemCounts[index]
        );
        return 1;
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
    // gotta figure out what to do with this 1, gonna use it as a pseudo boolean value
}

// Removes amount of the item at index to the backpack.
// Returns 1 on success and 0 if it goes under the 0 or is invalid. This is for
// boolean purposes.
int removeItem(int index, int amount) {
    if (index < 0 || index >= NUM_ITEMS) {
        printf("Invalid item selection.\n");
        return 1;
    }

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return 1;
    }

    if (itemCounts[index] - amount < 0) {
        printf(
            "Cannot remove %d %s(s), only have %d.\n",
            amount,
            itemNames[index],
            itemCounts[index]
        );
        return 1;
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
    // Uses a simple for loop to display the backpacks items 
}



int userBackpackInput(void) {
    int userIndex;
    int userAmount;
    int userChoice;
    int returnedNumber;
    int loopDestroyer = 1;

    // asks the user to add or remove an item from their backpack or if they want to do neither 
    printf("Would you like to add or remove an item from your backpack?(1/2/3):\n");
    scanf(" %d", &userChoice);
    
    // here we process the user's choice and run the program accordingly 
    
    if(userChoice == 1 || userChoice == 2) {
        // asks the user for an index and amount as this is required for the arguments in both add and remove 
        printf("Please enter a index and amount please:");
        scanf(" %d %d", &userIndex, &userAmount);
            
            // here we add to the backpack
        if(userChoice == 1) {
            returnedNumber = addItem(userIndex, userAmount);
            // here we get the number that is returned from the function while also running the function 
                
            return returnedNumber;
        } 
        else /* if the user doesn't enter 'a' it will automatically assume that the input is r which works off our prior conditional  */ {
            returnedNumber = removeItem(userIndex, userAmount);
            return returnedNumber;
        }
            
        // default return value is given but if everything goes according to plan this will never be used  
        return 0;
    } else if(userChoice == 3)/* here the user is effectively going to break out of the loop that we are going to build later and stop the program */ {
        printf("This is your backpack for the school day!!\n");

         return 0;
        } else { 
            // going to use this as a safeguard against malicious use
            printf("Enter either 1, 2, or 3 please!\n");
            return 2;
        }
    
        return 0;
}
// Quick demo
int main(void) {

    int loopConditional = 1;

    while(loopConditional == 1) {
        loopConditional = userBackpackInput();
    }

    printf("Here is your backpack for the day: ");
    viewInventory();

   return 0;
}
