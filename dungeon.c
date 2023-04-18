#include "dungeon.h"

void initDungeon(void)
{
	// deze functie roept alle andere nodige functies op, ik zal alleen de locatie beschrijven niet de werking
	// de werking staat beschreven bij de desbetrefende functie

	initMap(); // map.c

	initGUI(); // gui.c

	initEntities(); // entities.c

	initPlayer(); // player.c

	initCombat(); // combat.c

	shidSpawnen(); // een functie om het spawnen van entities op een plek te houden.

	// als laatste word hier nog de offset toegevoegd aan de dungeon struct zodat er een mooie border om het spel zit

	dungeon.renderOffset.x = (SCREEN_WIDTH - (MAP_RENDER_WIDTH * TILE_SIZE)) / 2;
	dungeon.renderOffset.y = ((SCREEN_HEIGHT - (MAP_RENDER_HEIGHT * TILE_SIZE)) / 2) + TILE_SIZE;
}

void shidSpawnen()
{
	// uit player.c
	initGem(12, 13);
	initGem(5, 37);
	initGem(20, 25);
	initGem(27, 33);
	initGem(74, 35);
	initGem(63, 25);
	initGem(39, 22);
	initGem(21, 2);
	// uit combat.c
	spawnBaddie(1, 17);
	spawnBaddie(6, 32);
	spawnBaddie(9, 30);
	spawnBaddie(32, 34);
	spawnBaddie(22, 21);
	spawnBaddie(39, 10);
	spawnBaddie(41, 9);
	spawnBaddie(43, 10);
	spawnBaddie(48, 9);
	spawnBaddie(52, 10);
	spawnBaddie(58, 9);
	spawnBaddie(64, 10);
	spawnBaddie(70, 9);
	spawnBaddie(74, 10);
	spawnBaddie(77, 7);
	spawnBaddie(74, 2);
	spawnBaddie(73, 1);
	spawnBaddie(73, 3);
	spawnBaddie(66, 2);
	spawnBaddie(65, 1);
	spawnBaddie(65, 3);
	spawnBaddie(61, 2);
	spawnBaddie(60, 1);
	spawnBaddie(60, 3);
	spawnBaddie(54, 2);
	spawnBaddie(53, 1);
	spawnBaddie(53, 3);
	spawnBaddie(45, 2);
	spawnBaddie(44, 1);
	spawnBaddie(44, 3);
	spawnBaddie(31, 2);
	spawnBaddie(30, 1);
	spawnBaddie(30, 3);
	spawnFakeFriend(57, 36);
	spawnFakeFriend(17, 4);
}

void logic(void) // functie voor alle logic in het spel aangeroepen in de game loop
{
	doPlayer(); // player.c

	endGame(); // gui.c
}

void draw(void) // functie voor al het tekenen in het spel aangeroepen in de game loop
{
	drawMap(); // map.c

	DoVechten(); // combat.c

	drawEntities(); // entities.c

	drawGUI(); // gui.c
}
