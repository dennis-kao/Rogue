
#include <stdio.h>
#include <stdlib.h>
#include "roomParse.h"
#include "gameLoop.h"

/**
 * main
 * Accepts the path to an input file containing room information.
 *
 * IN: FILE*
 * RETURN: 0 if the program has run normally
 * POST: None
 * errors: Input file must follow and specified format for proper file parsing to occur.
 *         The input file must be readable to the program.
 *         There must be enough memory available to write to the structs.
 */
int main (int argc, char **argv) {

    FILE *levelFile;

    levelFile = fopen(argv[1], "r");

    if (levelFile == NULL) {
        printf("levelFile cannot be read!");
        exit(1);
    }

    Room *room = malloc(6 * sizeof(Room));

    if (room == NULL) {
        printf("Could not create room!\n");
        exit(1);
    }

    for (int i = 0; i < 6; i++) {
        room[i].items = malloc (sizeof(Item) * 15);
        room[i].doors = malloc (sizeof(DoorStruct) * 6);
        room[i].enemy = malloc (sizeof(Enemy) * 20);
        if (room[i].items == NULL) {
            printf("Could not create the struct items");
            exit(1);
        }
        if (room[i].doors == NULL) {
          printf("Could not create the struct doors");
          exit(1);
        }
        if (room[i].enemy == NULL) {
            printf("Could not create the struct enemy");
            exit(1);
        }
    }

    for (int i = 0; i < 6; i++) {
        storeElements(levelFile, &room[i]);
    }

    fclose(levelFile);

    gameLoop(room);

    for (int i = 0; i < 6; i++) {
        free(room[i].doors);
    }
    
    for (int i = 0; i < 6; i++) {
        free(room[i].items);
    }

    free(room);

    return 0;
}
