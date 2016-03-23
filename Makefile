CC = gcc
CFLAGS = -std=c99 -Iinclude -Wall
EXE = rogue
OBJ = main.o gameLoop.o roomParse.o

all: rogue

main.o: src/main.c
		$(CC) -c $< $(CFLAGS)

roomParse.o: src/roomParse.c
		$(CC) -c $< $(CFLAGS)

gameLoop.o: src/gameLoop.c
		$(CC) -c $< $(CFLAGS)

rogue: $(OBJ)
		$(CC) $(OBJ) -lncurses -o $(EXE)

run:
	./$(EXE) assets/roomInfo.txt

clean:
	rm -rf *.o
	rm -rf $(EXE)
