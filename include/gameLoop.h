/*__IFS_IGNORE__*/ //Used prevent the IFS system from scanning this file
/**
 * Dennis Kao (Mar 2016)
 * dkao@uoguelph.ca
 */

 #ifndef _DKAO_GAMELOOP__
 #define _DKAO_GAMELOOP__

/**
 * storeInventory
 * Assigns the type and integer stat of an item in the inventory to be "type" and "stat"
 *
 * IN: Inventory*, ItemType, int
 * RETURN: nothing
 * POST: None
 * errors: The pointer must point to a valid memory location, the function causes the program exits otherwise.
 */
void storeInventory(Inventory *inventory, ItemType type, int stat);

/**
 * createInventory
 * Malloc's the players inventory and allows for storage up to 5 items
 *
 * IN: Nothing
 * RETURN: Address of the malloc'ed memory
 * POST: None
 * errors: Ensure that there is sufficient memory available for the inventory to be created, the function causes the program exits otherwise.
 */
Inventory *createInventory();

/**
 * freeInventory
 * Frees memory previously allocated for the player's inventory
 *
 * IN: Inventory*
 * RETURN: Nothing
 * POST: None
 * errors: Inventory must be malloc'ed for beforehand or else the function will attempt to free something that is not there, the function causes the program exits otherwise.
 */
void freeInventory(Inventory *inventoryPtr);

/**
 * addHallway
 * Draws hallways from the door that is passed in to the middle hallway
 *
 * IN: DoorStruct
 * RETURN: Nothing
 * POST: None
 * errors: Ncurses must be initialized before this function is called
 */
void addHallway(DoorStruct doors);

/**
 * printMiddleHallways
 * Draws hallways in between the 2 rows of rooms
 *
 * IN: Nothing
 * RETURN: Nothing
 * POST: None
 * errors: Ncurses must be initialized before this function is called
 */
void printMiddleHallways();

/**
 * connectHallway
 * Draws hallways from the door the player steps on to the hallway in the middle and a randomly selected a door in next room
 *
 * IN: Room*, int, int, int, int, int, int
 * RETURN: Nothing
 * POST: None
 * errors: There must be at least one door in the next room or else the program call upon an invalid piece of memory and segfault.
 * The pointer must point to a valid piece of memory or the function causes the program to exit.
 */
void connectHallway(Room *room, int roomNumber, int doorNumber, int yPast, int xPast, int heroY, int heroX);

 /**
  * printRoom
  * Prints the rooms and their respective elements onto the screen.
  *
  * IN: Room*
  * RETURN: Nothing
  * POST: None
  * errors: Ncurses must be initialized before calling this function.
  *         The pointer must point to a valid piece of memory or the function causes the program to exit.
  */
 void printRoom (Room *room);

 /**
  * gameLoop
  * Initializes the ncurses game loop.
  * Modifies the position of each door, the hero and each enemy to reflect the vertical and horizontal shifts.
  * gameloop handles for player movement, enemy movement, combat and popup messages.
  * Exits when 'q' is entered and prints out the amount of gold collected and items collected.
  *
  * IN: Room*
  * RETURN: Nothing
  * POST: None
  * errors: None
  */
 void gameLoop (Room *room);

 #endif
 /* defined _DKAO_ROOMPARSE__ */
