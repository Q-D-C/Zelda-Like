#include "map.h"

static SDL_Texture *tiles[MAX_TILES];

void initMap(void) // functie die gebruikt word in init dungeon
{
	// int x, y;

	loadTiles();

	loadMap();
}

void loadMap(void) // functie om de string met getallen om te zetten in data die de computer begrijpt
{
	// De dungeon is opgedeelt in een groot grid vastgesteld met MAP_WIDTH en MAP_HEIGHT in defs.h
	// in de map struct (opgeslagen in de dungeon struct) heeft elk blokje in deze grid
	// een locatie in een 2D array. Deze functie gaat elk getal (uit map.data) af en zet deze in
	// de data array. Op deze manier staat in de struct op geslagen of dat vakje in het grid
	// een gat(0), een tile(1) of een muur(2) is.
	int x, y;
	char *data, *p;

	data = readFile("map.data"); // leest het .data bestand en zet hem in de data pointer

	p = data; // extra var voor readability

	for (y = 0; y < MAP_HEIGHT; y++)
	{
		for (x = 0; x < MAP_WIDTH; x++) // dubbele for-loop om elke coordinaat in de dungeon af te gaan
		{
			dungeon.map.data[x][y] = atoi(p);

			do
			{
				p++;
			} while (*p != ' ');
		}
	}

	free(data); // als het klaar is kan de data verwijderd worden uit het geheugen.
}

void drawMap(void)
{
	drawMapTiles();
}

void loadTiles(void)
{
	tiles[TILE_WALL] = load_texture("gfx/wall.png");	// muur txtr word geladen
	tiles[TILE_GROUND] = load_texture("gfx/floor.png"); // grond txtr word geladen
}

void drawMapTiles(void)
{
	// in load map word op elk coordinaat in het grid een type ingeladen
	// in deze functie word die data omgezet naar iets dat ook echt gerenderd word
	int x, y, mx, my, n;

	for (y = 0; y < MAP_RENDER_HEIGHT; y++)
	{
		for (x = 0; x < MAP_RENDER_WIDTH; x++) // eerst word in de dubbele for loop de hele dungeon af gegaan
		{
			// daarna word dit vergeleken met de camera of de tiles ook echt in beeld zijn
			mx = dungeon.camera.x + x;
			my = dungeon.camera.y + y;

			n = dungeon.map.data[mx][my]; // vervolgens word de data (uit loadmap) in een variabele gezet

			if (n > TILE_HOLE) // als er op die coordinaat geen gat (0) is dan word er een txtr geladen
			{
				blit(tiles[n], (x * TILE_SIZE) + dungeon.renderOffset.x, (y * TILE_SIZE) + dungeon.renderOffset.y, 0);
			}
		}
	}
}

char *readFile(char *filename)
{
	// Dit is een functie die het .data bestand omzet naar een datatype die in de char pointer gezet kan worden.

	char *buffer;
	long unsigned length;
	FILE *file;

	file = fopen(filename, "rb");

	if (file == NULL)
	{
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "No such file '%s'", filename);
		exit(1);
	}

	fseek(file, 0, SEEK_END);
	length = (long unsigned)ftell(file);
	fseek(file, 0, SEEK_SET);

	buffer = malloc(length);
	memset(buffer, 0, length);
	fread(buffer, 1, length, file);

	fclose(file);

	return buffer;
}