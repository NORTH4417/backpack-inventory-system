/**
 * @file main.c
 * @author Aaron, Nathan, Gus
 * @brief Entry point for the backpack inventory program. For compilation, in
 * the terminal do "make", and then do "./backpack" to run.
 * @version 0.1
 * @date 2026-11-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "backpack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// https://youtu.be/_wWfHRbzdX4?si=UhH2N2dN34yowL2S
// Used this video to get the formula for random numbers within a certain range
// and for how to use srand()

/**
 * @brief Runs the backpack program.
 *
 * Shows an empty backpack and then asks whether the user is in a rush. If so a
 * random backpack is generated and shown. Otherwise it shows a random messy
 * backpack is shown and the user can add or remove items until they quit.
 *
 * @return 0 on normal exit.
 */
int main(void) {
    srand(time(NULL));
    char userChoice;
    int loopConditional = 1; // initialize conditional variable
    char userInputEmptyingBackpack;
    char randomBackpack;
    printf("Hello! You can see your empty backpack below.\n");
    printf(
        "Follow the instructions to add or remove items and get ready for the "
        "day!\n\n"
    );

    viewInventory(); // shows user empty backpack before getting started
    printf("\n");

    printf(
        "Are you in a rush this morning?(throw random items in backpack and "
        "leave)[y/n]\n"
    );
    scanf(" %c", &userChoice);

    if (userChoice == 'y') {
        randomBackpackForTheDay();
        viewInventory();
    } else if (userChoice == 'n') {
        printf(
            "Your backpack is kind of messy and still has some items in it "
            "from yesterday\n"
        );
        randomBackpackForTheDay();
        viewInventory();
        while (1) {
            loopConditional = userBackpackInput();
            if (loopConditional == 1) {
                continue;
            } else {
                printf(
                    "Would you like to clear your backpack and start over?[y/n]"
                );
                scanf(" %c", &userInputEmptyingBackpack);

                if (userInputEmptyingBackpack == 'y') {
                    emptyBackpack();
                    viewInventory();
                    continue;
                } else if (userInputEmptyingBackpack == 'n') {
                    viewInventory();
                    break;
                } else {
                    printf("Enter a valid input please!");
                }
            }
        }
    }

    return 0;
}
