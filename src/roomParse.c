#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>
#include "roomParse.h"

void positionStore (char token[], Item *items) {

    char temp = '\0';

    if (items == NULL) printf ("Could not access items!");

    sscanf (token, "%1c%2d,%2d", &temp, &items->yPos, &items->xPos);
}

void storeElements (FILE *levelFile, Room *room) {

    char line[100];
    char *token;

    nullChecker (levelFile, room);

    room->numItems = 0;

    fgets(line, 99, levelFile);

    token = strtok (line, " ");

    sscanf (token, "%2dX%2d", &room->yPos, &room->xPos);
    room->yPos = room->yPos + 2;
    room->xPos = room->xPos + 2;

    for (int j = 0; j < 14; j++) {

        char temp;

        token = strtok (NULL, " ");
        if (token == NULL) break;

        /* Position of door hardcoded because door cases follow a different string format */
        if (token[0] == 'd') {

            room->items[j].type=door;

            if (token[1] == 'n') {
                room->numItems++;
                room->items[j].doorDirection = 'n';
                room->items[j].yPos = 0;

                sscanf (token, "d%1c%2d", &temp, &room->items[j].xPos);
            }

            else if (token[1] == 'e') {
                room->numItems++;
                room->items[j].doorDirection = 'e';
                room->items[j].xPos = room->xPos - 1;
                
                sscanf (token, "d%1c%2d", &temp, &room->items[j].yPos);
            }

            else if (token[1] == 's') {
                room->numItems++;
                room->items[j].doorDirection = 's';
                room->items[j].yPos = room->yPos - 1;

                sscanf (token, "d%1c%2d", &temp, &room->items[j].xPos);
            }

            else if (token[1] == 'w') {
                room->numItems++;
                room->items[j].doorDirection = 'w';
                room->items[j].xPos = 0;

                sscanf (token, "d%1c%2d", &temp, &room->items[j].yPos);
            }
        }

        else {

            switch (token[0]) {

                case 'h':
                    room->items[j].type = hero;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;

                case 'z':
                    room->items[j].type = downStair;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;

                case 'a':
                    room->items[j].type = upStair;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;

                case 'g':
                    room->items[j].type = smallGold;
                    positionStore (token, &room->items[j]);
                    room->items[j].itemValue = rand() % 51;
                    room->numItems++;
                    break;

                case 'G':
                    room->items[j].type = bigGold;
                    positionStore (token, &room->items[j]);
                    room->items[j].itemValue = rand() % 250 + 50;
                    room->numItems++;
                    break;

                case 'w':
                    room->items[j].type = commonWeapon;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;

                case 'W':
                    room->items[j].type = rareWeapon;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;

                case 'e':
                    room->items[j].type = equipment;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;

                case 'M':
                    room->items[j].type = strongMonster;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;
                    
                case 'm':
                    room->items[j].type = weakMonster;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;

                case 'p':
                    room->items[j].type = potion;
                    positionStore (token, &room->items[j]);
                    room->numItems++;
                    break;
            }
        }
    }
}

void nullChecker (FILE *levelFile, Room *room) {

    if (levelFile == NULL) {
        printf("File containing level information cannot be read\n");
        exit(1);
    }

    if (room == NULL) {
        printf("File containing level information cannot be read\n");
        exit(1);
    }
}

char identifyElement (ItemType type) {

  int random = 0;

  switch (type) {

      case hero:
          return '@';
          break;

      case door:
          return '+';
          break;

      case downStair:
          return '<';
          break;

      case upStair:
          return '>';
          break;

      case smallGold:
          return '*';
          break;

      case bigGold:
          return '8';
          break;

      case commonWeapon:
          return ')';
          break;

      case rareWeapon:
          return '(';
          break;

      case weakMonster:
          random = rand() % 3;
          if (random == 0) return 'A';
          else if (random == 1) return 'B';
          else if (random == 2) return 'S';
          else if (random == 3) return 'Z';
          break;

      case equipment:
          return ']';
          break;

      case strongMonster:
          return 'T';
          break;

      case potion:
          return '!';
          break;
  }

  /* This is just here to remove the warning caused by having no return statement at the end */
  return '.';
}