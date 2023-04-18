OBJS	= main.o init.o player.o draw.o dungeon.o map.o entities.o gui.o combat.o
SOURCE	= main.c init.c player.c draw.c dungeon.c map.c entities.c gui.c combat.c
HEADER	= main.h init.h player.h common.h defs.h structs.h draw.h dungeon.h map.h entities.h gui.h combat.h
OUT	= zelda
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Wconversion -Wpedantic
LFLAGS	 = `sdl2-config --cflags --libs` -lSDL2_image -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c99

combat.o: combat.c
	$(CC) $(FLAGS) combat.c -std=c99

entities.o: entities.c
	$(CC) $(FLAGS) entities.c -std=c99

gui.o: gui.c
	$(CC) $(FLAGS) gui.c -std=c99

map.o: map.c
	$(CC) $(FLAGS) map.c -std=c99
	
dungeon.o: dungeon.c
	$(CC) $(FLAGS) dungeon.c -std=c99

init.o: init.c
	$(CC) $(FLAGS) init.c -std=c99

player.o: player.c
	$(CC) $(FLAGS) player.c -std=c99

draw.o: draw.c
	$(CC) $(FLAGS) draw.c -std=c99


clean:
	rm -f $(OBJS) $(OUT)