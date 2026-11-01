/**
 * @file backpack.h
 * @author Aaron, Nathan, Gus
 * @brief Interface for the backpack inventory functions
 */

#ifndef BACKPACK_H
#define BACKPACK_H

#include "structs.h"

/**
 * @brief Adds items of one kind to the backpack.
 *
 * @param index Index of the item from 0 to NUM_ITEMS - 1
 * @param amount Number of items to add, must be positive
 * @return Always 1 which is treated as "keep looping". Whether the add actually
 * happens or not is indicated through the print message.
 */
int addItem(int index, int amount);

/**
 * @brief Removes items of one kind from the backpack.
 *
 * @param index Index of the item from 0 to NUM_ITEMS - 1
 * @param amount Number of items to remove, must be positive
 * @return Always 1 which is treated as "keep looping". Whether the removal
 * actually happens or not is indicated through the print message.
 */
int removeItem(int index, int amount);

/**
 * @brief Sets the count of every item in the backpack to 0
 *
 * @return Always 0
 */
int emptyBackpack(void);

/**
 * @brief Fills the backpack with a random amount of each item.
 *
 * @return Always 0
 */
int randomBackpackForTheDay(void);

/**
 * @brief Prints out a visual of the backpack and shows how much of each item is
 * in it.
 *
 * @return Always 0
 */
int viewInventory(void);

/**
 * @brief Prompts the user to add an item, remove an item, or quit.
 *
 * @return 1 if the program should prompt again (an add or remove was tried, the
 * user chose "Go Back", or the input was invalid).
 * @return 0 if the user chose to quit.
 */
int userBackpackInput(void);

#endif
