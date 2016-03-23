Compilation

First navigate to the A3 folder using terminal. 

The program can then be compiled using the following line: 

“make”


Usage

This command will execute the program:

“make run”

where in the Makefile there is a path to a .txt file containing the information for each room.


Testing

A file containing information for 6 rooms was used in testing this program. It can found in /assets.


Known limitations

The terminal window must be large enough to accommodate for the rooms being drawn.

The .txt file containing room information must follow a specified format in order for proper file parsing.

There can only be 6 rooms.

Rooms must be no bigger than 18x23.

There must be only 1 hero per input file.

There can only be up to 10 items per room.

There can only be up to 4 doors per room.

There can be up to 20 enemies per room.

There must be at least 1 door to to each room in order for a hallway to connect to it.

In the case where an enemy walks into: a/an item, hero, wall, hallway, gold, potion, door, stairwell or another enemy, it is automatically moved back to its previous position. The enemy does not move this turn and continues to the next step in its patrol as if nothing has changed.
This design decision was made because it would be easier for the player to recognize an enemy’s patrol as opposed to a method which moves an enemy.


References

None
