/*__IFS_IGNORE__*/ //Used prevent the IFS system from scanning this file
/**
 * Dennis Kao (Feb 2016)
 * dkao@uoguelph.ca
 */

 #ifndef _DKAO_ROOMPARSE__
 #define _DKAO_ROOMPARSE__

typedef enum ItemType {
    
    hero,
    door,
    downStair,
    upStair,
    smallGold,
    bigGold,
    commonWeapon,
    rareWeapon,
    weakMonster,
    equipment,
    strongMonster,
    potion
}ItemType;

typedef enum EnemyType {
    
    troll,
    aquator,
    bat,
    snake,
    zombie
}EnemyType;

typedef struct Enemy {
    
    EnemyType type;
    int health;
    int attack;
    int speed;
    int xPos;
    int yPos;
    int dead;
}Enemy;

typedef struct DoorStruct {
    
    char doorDirection;
    int xPos;
    int yPos;
    int connectedYet;
    int roomNumber;
}DoorStruct;

typedef struct Inventory {
    
    ItemType type;
    int stat;
}Inventory;

typedef struct Item {

    ItemType type;
    char doorDirection;
    int itemValue;
    int xPos;
    int yPos;
}Item;

typedef struct Room {
    
    int yPos;
    int xPos;
    int numItems;
    int doorCount;
    int enemyCount;
    Item *items;
    DoorStruct *doors;
    Enemy *enemy;
}Room;

/**
 * positionStore
 * Accepts a string and an item as input, then stores the coordinates in the token in the struct item.
 *
 * IN: char[], Item *
 * RETURN: Nothing
 * POST: None
 * errors: string must follow the specified format in order for the right coordinates to be stored.
 */
void positionStore (char token[], Item *items);

/**
 * storeElements
 * Accepts a file and room as input. Reads the file line by line and stores the information in the
 * appropriate structs.
 *
 * IN: FILE *, Room *
 * RETURN: Nothing
 * POST: None
 * errors: Input file must follow the specied format for proper parsing to occur.
 */
void storeElements (FILE *levelFile, Room *room);

/**
 * nullChecker
 * Accepts a file and room as input.
 * Verified that the file is accessible and memory has been allocated for the room.
 *
 * IN: FILE *, Room *
 * RETURN: Nothing
 * POST: None
 * errors: Function needs to be able to read the specified input file or else the program will exit.
 */
void nullChecker (FILE *levelFile, Room *room);

/**
 * identifyElement
 * Accepts an item type and returns the associated symbol on the screen.
 *
 * IN: ItemType
 * RETURN: Char
 * POST: None
 * errors: The item type must be one of the predefined elements in the enum ItemType
 */
char identifyElement (ItemType type);

#endif
/* defined _DKAO_ROOMPARSE__ */
