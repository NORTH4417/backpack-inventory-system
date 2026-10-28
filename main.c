#include "structs.h"
#include <stdio.h>

// Items to be included in the backpack
// NUM_ITEMS and array structure comes from structs.h
// order of items does matter, it's the order that the user enters them in
Item item[NUM_ITEMS] = {
    {"Pencils", 10, 0},
    {"Pens", 10, 0},
    {"Notebooks", 3, 0},
    {"Calculator", 1, 0},
    {"Erasers", 5, 0},
};

// Adds amount of the item at index to the backpack.
// Returns 1 on success and 0 if it goes over the max or is invalid. This is for
// boolean purposes.
int addItem(int index, int amount) {
    if (index < 0 || index >= NUM_ITEMS) {
        printf("Invalid item selection.\n");
        return 1;
    }
    // this basically checks if the index is within the bounds that are given in
    // NUM_ITEMS

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return 1;
    }
    // when adding an item, this makes sure the number of items you are adding
    // are positive

    if (item[index].count + amount > item[index].maxCap) {
        printf(
            "Cannot add %d to %s(s), only room for %d more.\n",
            amount,
            item[index].name,
            item[index].maxCap - item[index].count
        );
        return 1;
    }
    // if you are trying to put too much of a certain item in the backpack the
    // program prints out a statement that tells how much of that item you can
    // add to the backpack

    item[index].count += amount;
    // adds the amount of items you want to put into your backpack

    printf(
        "Added %d to %s(s). Now have %d/%d.\n",
        amount,
        item[index].name,
        item[index].count,
        item[index].maxCap
    );
    return 1;
    // gotta figure out what to do with this 1, gonna use it as a pseudo boolean
    // value
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

    if (item[index].count - amount < 0) {
        printf(
            "Cannot remove %d %s(s), only have %d.\n",
            amount,
            item[index].name,
            item[index].count
        );
        return 1;
    }

    item[index].count -= amount;
    printf(
        "Removed %d %s(s). Now have %d/%d.\n",
        amount,
        item[index].name,
        item[index].count,
        item[index].maxCap
    );
    return 1;
}

// function to view backpack and its contents
int viewInventory(void) {
    printf("                     _____________\n");
    printf("                   .'  _________  '.\n");
    printf("                  /  .'         '.  \\\n");
    printf("                 |  |             |  |\n");
    printf("                 |  |             |  |\n");
    printf("              ___|__|_____________|__|___\n");
    printf("             /                           \\\n");
    printf("            /    _____________________    \\\n");
    printf("           |    |  ___________________|    |\n");
    printf("           |    | | Notebooks:  %d/3   |    |\n", item[2].count);
    printf("           |    | | Calculator: %d/1   |    |\n", item[3].count);
    printf("        .--|    | | Erasers:    %d/5   |    |--.\n", item[4].count);
    printf("        |  |    | |      _______      |    |  |\n");
    printf("        |  |    | |     |       |     |    |  |\n");
    printf("        |  |    | |     |   o   |     |    |  |\n");
    printf("        |  |    | |     |_______|     |    |  |\n");
    printf("        |  |    | |                   |    |  |\n");
    printf("        |  |    | |___________________|    |  |\n");
    printf("        |  |    |_______________________   |  |\n");
    printf("        |  |   /                        \\  |  |\n");
    printf("        |  |  |   ====================   | |  |\n");
    printf("        |  |  |  | Pencils:    %d/10   |  | |  |\n", item[0].count);
    printf("        |  |  |  | Pens:       %d/10   |  | |  |\n", item[1].count);
    printf("        |  |  |  |____________________|  | |  |\n");
    printf("        '--|   \\________________________/  |--'\n");
    printf("           |                               |\n");
    printf("           |_______________________________|\n");
    printf("            \\_____________________________/\n");
    printf("\n\n");

    return 0;
}

int userBackpackInput(void) {
    int userIndex;
    int userAmount;
    char userChoice = ' '; // initialize as a character to account for invalid
                           // user inputs (ex: 'a' instead of '1')
    int returnedNumber;
    int loopDestroyer = 1;

    // asks the user to add or remove an item from their backpack or if they
    // want to do neither
    printf("Enter 1 to add an item, 2 to remove an item, or 3 to quit:\n");
    scanf(" %c", &userChoice);

    // here we process the user's choice and run the program accordingly

    if (userChoice == '1' || userChoice == '2') {
        // asks the user for an index and amount as this is required for the
        // arguments in both add and remove

        printf("Which item? (Enter number on left and hit enter):\n");
        printf("[0]: Pencils\n");
        printf("[1]: Pens\n");
        printf("[2]: Notebooks\n");
        printf("[3]: Calculator\n");
        printf("[4]: Erasers\n");
        scanf(" %d", &userIndex);
        printf("How many?\n");
        scanf("%d", &userAmount);

        // here we add to the backpack
        if (userChoice == '1') {
            returnedNumber = addItem(userIndex, userAmount);
            // here we get the number that is returned from the function while
            // also running the function

            return returnedNumber;
        } else /* if the user doesn't enter 'a' it will automatically assume
                  that the input is r which works off our prior conditional  */
        {
            returnedNumber = removeItem(userIndex, userAmount);
            return returnedNumber;
        }

        // default return value is given but if everything goes according to
        // plan this will never be used
        return 0;
    } else if (userChoice == '3') /* here the user is effectively going to break
                                   out of the loop that we are going to build
                                   later and stop the program */
    {
        printf("This is your backpack for the school day!!\n");

        return 0;
    } else {
        // validates user input, if they enter anything other than 1, 2, or 3
        // returns 1 to main and starts over
        printf("Invalid input, please try again.\n");
        return 1;
    }

    return 0; // if user enters 3, returns 0 and breaks out of while loop in
              // main
}

int main(void) {

    int loopConditional = 1; // initialize conditional variable

    printf("Hello! You can see your empty backpack below.\n");
    printf(
        "Follow the instructions to add or remove items and get ready for the "
        "day!\n\n"
    );

    viewInventory(); // shows user empty backpack before getting started
    printf("\n");

    while (loopConditional == 1) {
        loopConditional =
            userBackpackInput(); // while userBackpack input function returns 1,
                                 // loop will continue
        viewInventory();
    }

    return 0;
}
