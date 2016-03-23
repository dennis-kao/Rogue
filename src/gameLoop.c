#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "roomParse.h"

void storeInventory(Inventory *inventory, ItemType type, int stat) {
    
    if (inventory == NULL) {
        
        printf("Inventory could not be accessed!\n");
        exit(1);
    }
    
    inventory->type = type;
    inventory->stat = stat;
}

Inventory *createInventory() {
    
    Inventory *inventoryPtr;
    
    inventoryPtr = malloc (sizeof(Inventory) * 5);
    
    if (inventoryPtr == NULL) {
        
        printf("Inventory could not be created!\n");
        exit(1);
    }
    
    return(inventoryPtr);
}

void freeInventory(Inventory *inventoryPtr) {
    
    if (inventoryPtr == NULL) {
        
        printf("Inventory could not be created!\n");
        exit(1);
    }
    
    free(inventoryPtr);
}

void addHallway(DoorStruct doors) {
        
    if (doors.roomNumber == 0 || doors.roomNumber == 1 || doors.roomNumber == 2) {
        
        if (doors.doorDirection == 'n') {
        
            mvaddch(doors.yPos - 1, doors.xPos, '#');
            mvaddch(doors.yPos - 2, doors.xPos, '#');

            if (doors.roomNumber == 0) {
                
                for (int i = 0; i < 34 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos - 2, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < 27 - doors.yPos + 2; i++) {
                    
                    mvaddch(doors.yPos - 2 + i, 33, '#');
                }
            }

            else if (doors.roomNumber == 1) {
                
                for (int i = 0; i < 64 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos - 2, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < 27 - doors.yPos + 2; i++) {
                    
                    mvaddch(doors.yPos - 2 + i, 63, '#');
                }
            }

            else if (doors.roomNumber == 2) {
                
                for (int i = 0; i < 94 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos - 2, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < 28 - doors.yPos + 2; i++) {
                    
                    mvaddch(doors.yPos - 2 + i, 93, '#');
                }
            }
        }
        
        else if (doors.doorDirection == 's') {
            
            for (int i = 1; i < 28 - doors.yPos; i++) {
                
                mvaddch(doors.yPos + i, doors.xPos, '#');
            }
        }
        
        else if (doors.doorDirection == 'e') {
            
            if (doors.roomNumber == 0) {
                
                for (int i = 1; i < 34 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < 27 - doors.yPos; i++) {
                    
                    mvaddch(doors.yPos + i, 33, '#');
                }
            }
            
            else if (doors.roomNumber == 1) {
                
                for (int i = 1; i < 64 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < 27 - doors.yPos; i++) {
                    
                    mvaddch(doors.yPos + i, 63, '#');
                }
            }
            
            else if (doors.roomNumber == 2) {
                
                for (int i = 1; i < 94 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < 28 - doors.yPos; i++) {
                    
                    mvaddch(doors.yPos + i, 93, '#');
                }
            }
        }
        
        else if (doors.doorDirection == 'w') {
            
            mvaddch(doors.yPos, doors.xPos - 1, '#');
            mvaddch(doors.yPos, doors.xPos - 2, '#');
            
            if (doors.roomNumber == 0) {
                
                for (int i = 0; i < 27 - doors.yPos; i++) {
                    
                    mvaddch(doors.yPos + i, 3, '#');
                }
            }
            
            else if (doors.roomNumber == 1) {
                
                for (int i = 0; i < 27 - doors.yPos; i++) {
                    
                    mvaddch(doors.yPos + i, 33, '#');
                }
            }
            
            else if (doors.roomNumber == 2) {
                
                for (int i = 0; i < 27 - doors.yPos; i++) {
                    
                    mvaddch(doors.yPos + i, 63, '#');
                }
            }
        }
    }
    
    else if (doors.roomNumber == 3 || doors.roomNumber == 4 || doors.roomNumber == 5) {
        
        if (doors.doorDirection == 'n') {
            
            mvaddch(doors.yPos - 1, doors.xPos, '#');
            mvaddch(doors.yPos - 2, doors.xPos, '#');
        }
        
        else if (doors.doorDirection == 'w') {
            
            mvaddch(doors.yPos, doors.xPos - 1, '#');
            mvaddch(doors.yPos, doors.xPos - 2, '#');
            
            if (doors.roomNumber == 3) {
                
                for (int i = 0; i < doors.yPos - 27; i++) {
                    
                    mvaddch(doors.yPos - i, 3, '#');
                }
            }
            
            else if (doors.roomNumber == 4) {
                
                for (int i = 0; i < doors.yPos - 27; i++) {
                    
                    mvaddch(doors.yPos - i, 33, '#');
                }
            }
            
            else if (doors.roomNumber == 5) {
                
                for (int i = 0; i < doors.yPos - 27; i++) {
                    
                    mvaddch(doors.yPos - i, 63, '#');
                }
            }
        }
        
        else if (doors.doorDirection == 'e') {
            
            if (doors.roomNumber == 3) {
                
                for (int i = 1; i < 33 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < doors.yPos - 27; i++) {
                    
                    mvaddch(doors.yPos - i, 33, '#');
                }
            }
            
            else if (doors.roomNumber == 4) {
                
                for (int i = 1; i < 64 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < doors.yPos - 27; i++) {
                    
                    mvaddch(doors.yPos - i, 63, '#');
                }
            }
            
            else if (doors.roomNumber == 5) {
                
                for (int i = 1; i < 94 - doors.xPos; i++) {
                    
                    mvaddch(doors.yPos, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < doors.yPos + 2 - 28; i++) {
                    
                    mvaddch(doors.yPos - i, 93, '#');
                }
            }
        }
        
        else if (doors.doorDirection == 's') {
            
            for (int i = 1; i < 51 - doors.yPos; i++) {
                
                mvaddch(doors.yPos + i, doors.xPos, '#');
            }
            
            if (doors.roomNumber == 3) {
                
                for (int i = 0; i < 33 - doors.xPos; i++) {
                    
                    mvaddch(50, doors.xPos + i, '#');
                }
                
                for (int i = 0; i < 50 + 2 - 28; i++) {
                    
                    mvaddch(50 - i, 33, '#');
                }
            }
            
            else if (doors.roomNumber == 4) {
                
                for (int i = 0; i < 64 - doors.xPos; i++) {
                    
                    mvaddch(50, doors.xPos + i, '#');
                }
                
                
                for (int i = 0; i < 50 + 2 - 28; i++) {
                    
                    mvaddch(50 - i, 63, '#');
                }
            }
            
            else if (doors.roomNumber == 5) {
                
                for (int i = 0; i < 94 - doors.xPos; i++) {
                    
                    mvaddch(50, doors.xPos + i, '#');
                }
                
                
                for (int i = 0; i < 50 + 2 - 28; i++) {
                    
                    mvaddch(50 - i, 93, '#');
                }
            }
        }
    }
}

void printMiddleHallways () {
    
    for (int i = 3; i < 93; i++) {
        
        mvaddch(27, i, '#');
    }
}

void connectHallway(Room *room, int roomNumber, int doorNumber, int yPast, int xPast, int heroY, int heroX) {
    
    if (room == NULL) {
        
        printf("Could not access room information");
        exit(1);
    }
    
//    room[roomNumber].doors[doorNumber].connectedYet = 1;
    
    if (roomNumber == 0)
    {
        int randomDoor = rand() % room[1].doorCount;
        addHallway (room[roomNumber].doors[doorNumber]);
        addHallway (room[1].doors[randomDoor]);
//        room[1].doors[randomDoor].connectedYet = 1;
    }
    else if (roomNumber == 1)
    {
        int randomDoor = rand() % room[2].doorCount;
        addHallway (room[roomNumber].doors[doorNumber]);
        addHallway (room[2].doors[randomDoor]);
//        room[2].doors[randomDoor].connectedYet = 1;
    }
    else if (roomNumber == 2)
    {
        int randomDoor = rand() % room[3].doorCount;
        addHallway (room[roomNumber].doors[doorNumber]);
        addHallway (room[3].doors[randomDoor]);
//        room[3].doors[randomDoor].connectedYet = 1;
    }
    else if (roomNumber == 3)
    {
        int randomDoor = rand() % room[4].doorCount;
        addHallway (room[roomNumber].doors[doorNumber]);
        addHallway (room[4].doors[randomDoor]);
//        room[4].doors[randomDoor].connectedYet = 1;
    }
    else if (roomNumber == 4)
    {
        int randomDoor = rand() % room[5].doorCount;
        addHallway (room[roomNumber].doors[doorNumber]);
        addHallway (room[5].doors[randomDoor]);
//        room[5].doors[randomDoor].connectedYet = 1;
    }
    else if (roomNumber == 5)
    {
        int randomDoor = rand() % room[0].doorCount;
        addHallway (room[roomNumber].doors[doorNumber]);
        addHallway (room[0].doors[randomDoor]);
//        room[0].doors[randomDoor].connectedYet = 1;
    }
}

void printRoom (Room *room) {
    
    if (room == NULL) {
        
        printf("Could not access room information");
        exit(1);
    }
    
    int yShift = 0;
    
    /* Creates rooms 0 - 2 on the first row */
    for (int z = 0; z < 3; z++)
    {
        if (z == 0) {
            for (int i = 6; i < room[z].xPos + 6; i++)
            {
                for (int j = 6; j < room[z].yPos + 6; j++) {
                    mvaddch(j, i, '.');
                }
            }
            
            for (int j = 6; j < room[z].yPos + 6; j++)
            {
                mvaddch(j, 6, '|');
                mvaddch(j, room[z].xPos - 1 + 6,'|');
            }
            
            for (int i = 6; i < room[z].xPos + 6; i++)
            {
                mvaddch(6, i, '-');
                mvaddch(room[z].yPos - 1 + 6, i, '-');
            }
        }
        else {
            
            yShift = yShift + 30;
            
            for (int i = 6; i < room[z].xPos + 6; i++)
            {
                for (int j = 6; j < room[z].yPos + 6; j++) {
                    mvaddch(j, i + yShift, '.');
                }
            }
            
            for (int j = 6; j < room[z].yPos + 6; j++)
            {
                mvaddch(j, yShift + 6, '|');
                mvaddch(j, room[z].xPos - 1 + yShift + 6,'|');
            }
            
            for (int i = 6; i < room[z].xPos + 6; i++)
            {
                mvaddch(6, i + yShift, '-');
                mvaddch(room[z].yPos - 1 + 6, i + yShift, '-');
            }
        }
    }
    
    yShift = 0; /* Resets y back to zero for the next row */
    
    /* Runs through rooms 0 to 2 and adds items */
    for (int z = 0; z < 3; z++) {
        
        for (int i = 0; i < room[z].numItems; i++) {
            
            char element;
            
            element = identifyElement(room[z].items[i].type);
            
            if (z == 0) mvaddch(room[z].items[i].yPos + 6, room[z].items[i].xPos + 6, element);
            else if (z == 1) mvaddch(room[z].items[i].yPos + 6, room[z].items[i].xPos + 36, element);
            else if (z == 2) mvaddch(room[z].items[i].yPos + 6, room[z].items[i].xPos + 66, element);
        }
    }
    
    /* Creates rooms 3 to 5 on the second row */
    for (int z = 3; z < 6; z++)
    {
        if (z == 3) {
            for (int i = 6; i < room[z].xPos + 6; i++)
            {
                for (int j = 6; j < room[z].yPos + 6; j++) {
                    mvaddch(j + 23, i, '.');
                }
            }
            
            for (int j = 6; j < room[z].yPos + 6; j++)
            {
                mvaddch(j+ 23, 6, '|');
                mvaddch(j+ 23, room[z].xPos - 1 + 6,'|');
            }
            
            for (int i = 6; i < room[z].xPos + 6; i++)
            {
                mvaddch(29, i, '-');
                mvaddch(room[z].yPos - 1 + 29, i, '-');
            }
        }
        else
        {
            yShift = yShift + 30;
            
            for (int i = 6; i < room[z].xPos + 6; i++)
            {
                for (int j = 6; j < room[z].yPos + 6; j++) {
                    mvaddch(j + 23, i + yShift, '.');
                }
            }
            
            for (int j = 0; j < room[z].yPos; j++)
            {
                mvaddch(j+ 29, yShift + 6, '|');
                mvaddch(j+ 29, room[z].xPos -1 + yShift + 6,'|');
            }
            
            for (int i = 0; i < room[z].xPos; i++)
            {
                mvaddch(29, i + yShift + 6, '-');
                mvaddch(room[z].yPos - 1 + 29, i + yShift + 6, '-');
            }
        }
    }
    
    /* Adds items to rooms 3 to 6 */
    for (int z = 3; z < 6; z++) {
        
        for (int i = 0; i < room[z].numItems; i++) {
            
            char element;
            
            element = identifyElement(room[z].items[i].type);
            
            if (z == 3) mvaddch(room[z].items[i].yPos + 29, room[z].items[i].xPos + 6, element);
            else if (z == 4) mvaddch(room[z].items[i].yPos + 29, room[z].items[i].xPos + 36, element);
            else if (z == 5) mvaddch(room[z].items[i].yPos + 29, room[z].items[i].xPos + 66, element);
        }
    }
}

void gameLoop (Room *room) {
    
    if (room == NULL) printf("Could not open levelFile");
    
    char input;
    int goldCount = 0;
    int heroX = 0;
    int heroY = 0;
    int potion = 1;
    int inventoryCount = 0;
    int health = 50;
    int attack = 5;
    int cycle = 0; /* The integer cycle is used to determine the enemy movement */
//    int defense = 0;
    Inventory *inventoryPtr;
    
    inventoryPtr = createInventory();
    if (inventoryPtr == NULL) {
        
        printf("Inventory could not be created!\n");
        exit(1);
    }
    
    initscr();
    noecho();
    curs_set(FALSE);
    
    printRoom(room);
    printMiddleHallways();
    
    /* vertically and horizontally shifts position of all doors to reflect the room they are in */
    /* Also sets "connectedYet" for each door to be false */
    for (int z = 0; z < 6; z ++)
    {
        int a = 0;
        room[z].doorCount = 0;
        for (int i = 0; i < 14; i++)
        {
            if (room[z].items[i].type == door)
            {
                
                if (z == 0){
                    room[z].items[i].xPos = room[z].items[i].xPos + 6;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].doors[a].xPos = room[z].items[i].xPos;
                    room[z].doors[a].yPos = room[z].items[i].yPos;
                    room[z].doors[a].doorDirection = room[z].items[i].doorDirection;
                    room[z].doors[a].connectedYet = 0;
                    room[z].doors[a].roomNumber = 0;
                    room[z].doorCount++;
                    a++;
                }
                else if (z == 1) {
                    room[z].items[i].xPos = room[z].items[i].xPos + 36;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].doors[a].xPos = room[z].items[i].xPos;
                    room[z].doors[a].yPos = room[z].items[i].yPos;
                    room[z].doors[a].doorDirection = room[z].items[i].doorDirection;
                    room[z].doors[a].connectedYet = 0;
                    room[z].doors[a].roomNumber = 1;
                    room[z].doorCount++;
                    a++;
                }
                else if (z == 2) {
                    room[z].items[i].xPos = room[z].items[i].xPos + 66;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].doors[a].xPos = room[z].items[i].xPos;
                    room[z].doors[a].yPos = room[z].items[i].yPos;
                    room[z].doors[a].doorDirection = room[z].items[i].doorDirection;
                    room[z].doors[a].connectedYet = 0;
                    room[z].doors[a].roomNumber = 2;
                    room[z].doorCount++;
                    a++;
                }
                else if (z == 3)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 6;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].doors[a].xPos = room[z].items[i].xPos;
                    room[z].doors[a].yPos = room[z].items[i].yPos;
                    room[z].doors[a].doorDirection = room[z].items[i].doorDirection;
                    room[z].doors[a].connectedYet = 0;
                    room[z].doors[a].roomNumber = 3;
                    room[z].doorCount++;
                    a++;
                }
                else if (z == 4)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 36;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].doors[a].yPos = room[z].items[i].yPos;
                    room[z].doors[a].xPos = room[z].items[i].xPos;
                    room[z].doors[a].doorDirection = room[z].items[i].doorDirection;
                    room[z].doors[a].connectedYet = 0;
                    room[z].doors[a].roomNumber = 4;
                    room[z].doorCount++;
                    a++;
                }
                else if (z == 5)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 66;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].doors[a].yPos = room[z].items[i].yPos;
                    room[z].doors[a].xPos = room[z].items[i].xPos;
                    room[z].doors[a].doorDirection = room[z].items[i].doorDirection;
                    room[z].doors[a].connectedYet = 0;
                    room[z].doors[a].roomNumber = 5;
                    room[z].doorCount++;
                    a++;
                }
            }
            else;
        }
    }
    
    /* Vertically and horizontally shifts the position of enemies to reflect the rooms they are in  */
    /* Randomizes weak enemies and assigns their pre-defined stats */
    /* Assigns stats to the troll (strongEnemy) */
    /* Sets all enemies to be alive */
    for (int z = 0; z < 6; z++)
    {
        int a = 0;
        room[z].enemyCount = 0;
        for (int i = 0; i < 14; i++)
        {
            if (room[z].items[i].type == weakMonster)
            {
                int random = rand() % 4;
                
                room[z].enemy[a].dead = 0;
                
                if (random == 0) {
                    
                    room[z].enemy[a].type = aquator;
                    room[z].enemy[a].health = 5;
                    room[z].enemy[a].attack = 1;
                    room[z].enemy[a].speed = 2;
                }
                
                else if (random == 1) {
                    
                    room[z].enemy[a].type = bat;
                    room[z].enemy[a].health = 2;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 4;
                }
                
                else if (random == 2) {
                    room[z].enemy[a].type = snake;
                    room[z].enemy[a].health = 5;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 4;
                }
                
                else if (random == 3) {
                    room[z].enemy[a].type = zombie;
                    room[z].enemy[a].health = 15;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 2;
                }
                
                if (z == 0) {
                    room[z].items[i].xPos = room[z].items[i].xPos + 6;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 1) {
                    room[z].items[i].xPos = room[z].items[i].xPos + 36;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 2) {
                    room[z].items[i].xPos = room[z].items[i].xPos + 66;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 3)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 6;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 4)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 36;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 5)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 66;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemyCount++;
                    a++;
                }
            }
            else if (room[z].items[i].type == strongMonster)
            {
                room[z].enemy[a].dead = 0;
                
                if (z == 0){
                    room[z].items[i].xPos = room[z].items[i].xPos + 6;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].type = troll;
                    room[z].enemy[a].health = 50;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 3;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 1) {
                    room[z].items[i].xPos = room[z].items[i].xPos + 36;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].type = troll;
                    room[z].enemy[a].health = 50;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 3;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 2) {
                    room[z].items[i].xPos = room[z].items[i].xPos + 66;
                    room[z].items[i].yPos = room[z].items[i].yPos + 6;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].type = troll;
                    room[z].enemy[a].health = 50;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 3;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 3)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 6;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].type = troll;
                    room[z].enemy[a].health = 50;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 3;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 4)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 36;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].type = troll;
                    room[z].enemy[a].health = 50;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 3;
                    room[z].enemyCount++;
                    a++;
                }
                else if (z == 5)
                {
                    room[z].items[i].xPos = room[z].items[i].xPos + 66;
                    room[z].items[i].yPos = room[z].items[i].yPos + 29;
                    room[z].enemy[a].yPos = room[z].items[i].yPos;
                    room[z].enemy[a].xPos = room[z].items[i].xPos;
                    room[z].enemy[a].type = troll;
                    room[z].enemy[a].health = 50;
                    room[z].enemy[a].attack = 5;
                    room[z].enemy[a].speed = 3;
                    room[z].enemyCount++;
                    a++;
                }
            }
        }
    }
    
    /* Prints enemies onto the screen */
    for (int z = 0; z < 6; z++)
    {
        for (int i = 0; i < room[z].enemyCount; i++)
        {
            if (room[z].enemy[i].type == troll) mvprintw (room[z].enemy[i].yPos, room[z].enemy[i].xPos, "T");
            else if (room[z].enemy[i].type == aquator) mvprintw (room[z].enemy[i].yPos, room[z].enemy[i].xPos, "A");
            else if (room[z].enemy[i].type == bat) mvprintw (room[z].enemy[i].yPos, room[z].enemy[i].xPos, "B");
            else if (room[z].enemy[i].type == snake) mvprintw (room[z].enemy[i].yPos, room[z].enemy[i].xPos, "S");
            else if (room[z].enemy[i].type == zombie) mvprintw (room[z].enemy[i].yPos, room[z].enemy[i].xPos, "Z");
        }
    }
    
    /* Obtains the coordinates of the hero and updates it to reflect the vertical and horizontal shifts */
    for (int z = 0; z < 6; z++)
    {
        for (int i = 0; i < room[z].numItems; i++)
        {
            if (room[z].items[i].type == hero)
            {
                heroX = room[z].items[i].xPos;
                heroY = room[z].items[i].yPos;
                
                if (z == 0)
                {
                    heroX = heroX + 6;
                    heroY = heroY + 6;
                }
                
                else if (z == 1)
                {
                    heroX = heroX + 36;
                    heroY = heroY + 6;
                }
                
                else if (z == 2)
                {
                    heroX = heroX + 66;
                    heroY = heroY + 6;
                }
                
                else if (z == 3)
                {
                    heroY = heroY + 29;
                    heroX = heroX + 6;
                }
                
                else if (z == 4)
                {
                    heroX = heroX + 36;
                    heroY = heroY + 29;
                }
                
                else if (z == 5)
                {
                    heroX = heroX + 66;
                    heroY = heroY + 29;
                }
                
                break;
            }
            else;
        }
    }
    
    mvprintw(heroY, heroX, "@");
    
    mvprintw(53, 0, "Health:  50, Potions:   1, Attack:   5, Inv:  0/5");
    
    do {
        
        int xPast = heroX;
        int yPast = heroY;
        
        input = getch();
        
        move(0,0);
        clrtoeol();
        move(1,0);
        clrtoeol();
        move(heroY, heroX);
        
        if (input == 'w') heroY--;
        else if (input == 's') heroY++;
        else if (input == 'a') heroX--;
        else if (input == 'd') heroX++;
        else if (input == 'p') {
            
            if (potion > 0) {
                
                health = 50;
                potion--;
                mvprintw(0,0, "Hero recovered full health!");
            }
            else mvprintw(0,0, "Out of potions!");
        }
        
        if (mvinch(heroY, heroX) == '-' || mvinch(heroY, heroX) == '|' || mvinch(heroY, heroX) == ' ')
        {
            heroX = xPast;
            heroY = yPast;
            mvprintw(yPast, xPast, ".");
        }
        
        else if (mvinch(heroY, heroX) == '*')
        {
            goldCount = goldCount + rand() % 51;
            mvprintw(yPast, xPast, ".");
        }
        
        else if (mvinch(heroY, heroX) == '8')
        {
            goldCount = goldCount + rand() % 290 + 50;
            mvprintw(yPast, xPast, ".");
        }
        
        else if (mvinch(heroY, heroX) == '>' || mvinch(heroY, heroX) == '<') break;
        
        else if (mvinch(heroY, heroX) == '+') {
            
            mvprintw(0,0, "Hero opened a door.");
            
            int roomNumber;
            int doorNumber;
            
            for (int z = 0; z < 6; z++)
            {
                for (int i = 0; i <room[z].numItems; i++)
                {
                    if (heroY == room[z].doors[i].yPos && heroX == room[z].doors[i].xPos) {
                        
                        roomNumber = z;
                        doorNumber = i;
                    }
                }
            }
            
            /* connectedYet ensures that only 1 hallway is drawn per door being stepped on */
            if (room[roomNumber].doors[doorNumber].connectedYet == 0) {
                
                connectHallway(room, roomNumber, doorNumber, yPast, xPast, heroY, heroX);
            }
            else;
            
            if (mvinch(yPast - 1, xPast) == '#' || mvinch(yPast + 1, xPast) == '#' || mvinch(yPast, xPast - 1) == '#' || mvinch(yPast, xPast + 1) == '#' || mvinch(yPast - 1, xPast - 1) == '#' || mvinch(yPast + 1, xPast + 1) == '#' || mvinch(yPast - 1, xPast + 1) == '#' || mvinch(yPast + 1, xPast - 1) == '#') mvprintw(yPast, xPast, "#");
            else mvprintw(yPast, xPast, ".");
        }
        
        else if (mvinch(heroY, heroX) == '#') mvprintw(yPast, xPast, "#");
        
        else if ( mvinch(heroY, heroX) == '(') {
            
            if (inventoryCount != 5) {
                
                int randStat = rand() % 15 + 10;
                
//                attack = attack + randStat;
                
                storeInventory(&inventoryPtr[inventoryCount], rareWeapon, randStat);
                inventoryCount++;
                mvprintw(0,0, "Hero picked up ( item!");
            }
            else mvprintw(0,0, "Hero stepped on ), and broke it.");
            
            mvprintw(yPast, xPast, ".");
        }
        
        else if ( mvinch(heroY, heroX) == ')') {
            
            if (inventoryCount != 5) {
                
                int randStat = rand() % 9 + 1;
                
//                attack = attack + randStat;
                
                storeInventory(&inventoryPtr[inventoryCount], commonWeapon, randStat);
                inventoryCount++;
                mvprintw(0,0, "Hero picked up ( item!");
            }
            else mvprintw(0,0, "Hero stepped on ), and broke it.");
            
            mvprintw(yPast, xPast, ".");
        }
        
        else if ( mvinch(heroY, heroX) == ']') {
            
            if (inventoryCount != 5) {
                
                int randStat = rand() % 21;
                
//                defense = defense + randStat;
                
                storeInventory(&inventoryPtr[inventoryCount], equipment, randStat);
                inventoryCount++;
                mvprintw(0,0, "Hero picked up ] item!");
            }
            else mvprintw(0,0, "Hero stepped on ], and broke it.");
            
            mvprintw(yPast, xPast, ".");
        }
        
        else if ( mvinch(heroY, heroX) == '!') {
            
            potion++;
            mvprintw(yPast, xPast, ".");
        }
        
        else if (mvinch(heroY, heroX) == 'B' || mvinch(heroY, heroX) == 'Z' || mvinch(heroY, heroX) == 'A' || mvinch(heroY, heroX) == 'S' || mvinch(heroY, heroX) == 'T') {
            
            /* Identifies the enemy that is being encountered for the code below */
            int enemyNumber;
            int roomNumber;
            
            for (int z = 0; z < 6; z++)
            {
                for (int i = 0; i < room[z].enemyCount; i++)
                {
                    if (heroY == room[z].enemy[i].yPos && heroX == room[z].enemy[i].xPos)
                    {
                        roomNumber = z;
                        enemyNumber = i;
                    }
                }
            }
            
            /* playerAttack() event */
            if (rand() % 10 + 1 > room[roomNumber].enemy[enemyNumber].speed) {
                
                int damage = attack;
                
                if (damage > room[roomNumber].enemy[enemyNumber].health) {
                    
                    damage = room[roomNumber].enemy[enemyNumber].health;
                    room[roomNumber].enemy[enemyNumber].health = 0;
                }
                else room[roomNumber].enemy[enemyNumber].health = room[roomNumber].enemy[enemyNumber].health - attack;
                
                mvprintw(0,0, "Hero caused %d damage", damage);
            }
            
            /* enemyAttack() event */
            else {
                
                int damage;
                
                if (mvinch(heroY, heroX) == 'A') {
                    
                    damage = room[roomNumber].enemy[enemyNumber].attack;
                    attack = attack - room[roomNumber].enemy[enemyNumber].attack;
                }
                
                else {
                    
                    damage = room[roomNumber].enemy[enemyNumber].attack;
                    
                    if (damage > health) damage = health;
                    
                    health = health - room[roomNumber].enemy[enemyNumber].attack;
                }
                
                mvprintw(0,0, "Hero lost %d health or attack", damage);
            }
            
            if (health <= 0) break;
            else if (room[roomNumber].enemy[enemyNumber].health <= 0) {
                
                char enemyChar = '\0';
                
                if (room[roomNumber].enemy[enemyNumber].type == aquator) enemyChar = 'A';
                else if (room[roomNumber].enemy[enemyNumber].type == bat) enemyChar = 'B';
                else if (room[roomNumber].enemy[enemyNumber].type == snake) enemyChar = 'S';
                else if (room[roomNumber].enemy[enemyNumber].type == zombie) enemyChar = 'Z';
                else if (room[roomNumber].enemy[enemyNumber].type == troll) enemyChar = 'T';
                
                room[roomNumber].enemy[enemyNumber].dead = 1;
                
                mvprintw(yPast, xPast, ".");
                mvprintw(1,0, "Hero killed %c!", enemyChar);
            }
            else {
                
                heroY = yPast;
                heroX = xPast;
            }
            
        }
        
        else mvprintw(yPast, xPast, ".");
        
        /* Reprints doors in their positions */
        for (int z = 0; z < 6; z++)
        {
            for (int i = 0; i < room[z].doorCount; i++)
            {
                if (yPast == room[z].doors[i].yPos && xPast == room[z].doors[i].xPos)
                {
                    mvprintw(yPast, xPast, "+");
                }
            }
        }
        
        /* This piece of code goes before enemy movement because the hero needs to be present on the map for collision detection in the next code block */
        mvprintw(heroY, heroX, "@");
        
        /* Enemy movement code, cycles through each enemy and changes the xPos or yPos */
        for (int z = 0; z < 6; z++)
        {
            for (int i = 0; i < room[z].enemyCount; i++)
            {
                
                int pastX = room[z].enemy[i].xPos;
                int pastY = room[z].enemy[i].yPos;
                
                if (room[z].enemy[i].type == bat && room[z].enemy[i].dead == 0) {
                    
                    int randNumber = rand() % 4;
                    
                    if (randNumber == 0) room[z].enemy[i].yPos--;
                    else if (randNumber == 1) room[z].enemy[i].yPos++;
                    else if (randNumber == 2) room[z].enemy[i].xPos--;
                    else if (randNumber == 3) room[z].enemy[i].xPos++;
                    
                    if (mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '#' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '-' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '|' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '8' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '*' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '@' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '(' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ')' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ']' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '!' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '+' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ' ' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '>' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '<' || mvinch(heroY, heroX) == 'B' || mvinch(heroY, heroX) == 'Z' || mvinch(heroY, heroX) == 'A' || mvinch(heroY, heroX) == 'S' || mvinch(heroY, heroX) == 'T')
                    {
                        
                        room[z].enemy[i].xPos = pastX;
                        room[z].enemy[i].yPos = pastY;
                    }
                    
                    mvprintw(pastY, pastX, ".");
                    mvprintw(room[z].enemy[i].yPos, room[z].enemy[i].xPos, "B");
                }
                
                else if (room[z].enemy[i].type == snake && room[z].enemy[i].dead == 0) {
                    
                    if (cycle == 0) room[z].enemy[i].xPos++;
                    else if (cycle == 1) room[z].enemy[i].xPos++;
                    else if (cycle == 2) room[z].enemy[i].xPos--;
                    else if (cycle == 3) room[z].enemy[i].xPos--;
                    
                    if (mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '#' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '-' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '|' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '8' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '*' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '@' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '(' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ')' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ']' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '!' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '+' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ' ' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '>' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '<' || mvinch(heroY, heroX) == 'B' || mvinch(heroY, heroX) == 'Z' || mvinch(heroY, heroX) == 'A' || mvinch(heroY, heroX) == 'S' || mvinch(heroY, heroX) == 'T')
                    {
                        
                        room[z].enemy[i].xPos = pastX;
                        room[z].enemy[i].yPos = pastY;
                    }
                    
                    mvprintw(pastY, pastX, ".");
                    mvprintw(room[z].enemy[i].yPos, room[z].enemy[i].xPos, "S");
                }
                
                else if (room[z].enemy[i].type == zombie && room[z].enemy[i].dead == 0) {
                    
                    if (cycle == 0 || cycle == 2) room[z].enemy[i].yPos--;
                    else if (cycle == 1 || cycle == 3) room[z].enemy[i].yPos++;
                    
                    if (mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '#' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '-' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '|' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '8' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '*' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '@' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '(' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ')' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ']' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '!' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '+' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ' ' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '>' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '<' || mvinch(heroY, heroX) == 'B' || mvinch(heroY, heroX) == 'Z' || mvinch(heroY, heroX) == 'A' || mvinch(heroY, heroX) == 'S' || mvinch(heroY, heroX) == 'T')
                    {
                        
                        room[z].enemy[i].xPos = pastX;
                        room[z].enemy[i].yPos = pastY;
                    }
                    
                    mvprintw(pastY, pastX, ".");
                    mvprintw(room[z].enemy[i].yPos, room[z].enemy[i].xPos, "Z");
                }
                
                else if (room[z].enemy[i].type == troll && room[z].enemy[i].dead == 0) {
                    
                    if (cycle == 0) room[z].enemy[i].yPos--;
                    else if (cycle == 1) room[z].enemy[i].xPos++;
                    else if (cycle == 2) room[z].enemy[i].yPos++;
                    else if (cycle == 3) room[z].enemy[i].xPos--;
                    
                    if (mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '#' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '-' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '|' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '8' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '*' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '@' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '(' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ')' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ']' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '!' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '+' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == ' ' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '>' || mvinch(room[z].enemy[i].yPos, room[z].enemy[i].xPos) == '<' || mvinch(heroY, heroX) == 'B' || mvinch(heroY, heroX) == 'Z' || mvinch(heroY, heroX) == 'A' || mvinch(heroY, heroX) == 'S' || mvinch(heroY, heroX) == 'T')
                    {
                        
                        room[z].enemy[i].xPos = pastX;
                        room[z].enemy[i].yPos = pastY;
                    }
                    
                    mvprintw(pastY, pastX, ".");
                    mvprintw(room[z].enemy[i].yPos, room[z].enemy[i].xPos, "T");
                }
                
                else if (room[z].enemy[i].type == aquator);
                else;
            }
        }
        
        /* This piece of code will reset cycle back to 0, which creates the cyclic nature of enemy movement */
        cycle++;
        if (cycle == 4) cycle = 0;
        else;
        
        mvprintw(53, 0, "Health: %3d, Potions: %3d, Attack: %3d, Inv:%3d/5", health, potion, attack, inventoryCount);
        refresh();
        
    } while (input != 'q');
    
    endwin();
    
    printf("\nThe amount of gold collected was: %d.\n", goldCount);
    
    printf("\nYour inventory consists of:\n");
    
    printf("\n");
    
    if (inventoryCount == 0) printf("  - Empty!\n");
    else {
        
        for (int i = 0; i < inventoryCount; i++) {
            
            if (inventoryPtr[i].type == commonWeapon) printf("  - CommonWeapon, Attack: %d\n", inventoryPtr[i].stat);
            else if (inventoryPtr[i].type == rareWeapon) printf("  - RareWeapon, Attack: %d\n", inventoryPtr[i].stat);
            else if (inventoryPtr[i].type == equipment) printf("  - Equipment, Defense: %d\n", inventoryPtr[i].stat);
        }
    }
    
    printf("\n");
    
    freeInventory(inventoryPtr);
}
