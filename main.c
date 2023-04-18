#include "main.h"

SDL_Window *window = NULL; // SDL dingen die nodig zijn om te renderen
SDL_Renderer *renderer = NULL;

static int fps;
static long nextFPS;

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	welkom();

	double word; // variabele waar de SDL ticks worden opgeslagen zodat FPS logic gedaan kan worden

	init_window(); // init.c, SDL setup shid

	memset(&app, 0, sizeof(App)); // memmory reserveren

	initDungeon(); // dungeon.c, Dungeon setup shid

	atexit(concierge); // init.c, zorgen dat alles aan het einde weer opgeruimd word

	nextFPS = SDL_GetTicks() + 1000;

	while (1) // GAME LOOP WHOOP WHOOP
	{
		word = SDL_GetTicks(); // ticks in var zetten

		SDL_SetRenderDrawColor(renderer, 16, 16, 32, 255); // achtergrond kleur
		SDL_RenderClear(renderer);						   // renderer klaar maken

		doInput(); // player.c, Input opvangen en verwerken

		doEntities(); // entities.c checken of er "dode" entities zijn en deze uit mem halen

		draw(); // dungeon.c, hier word de draw functie aangeroepen die over het tekenen van het spel gaat

		SDL_RenderPresent(renderer); // shid ook echt op het scherm zetten

		logisch(); // FPS en game logic shid

		// allow the CPU/GPU to breathe
		SDL_Delay(1);

		app.deltaTime = LOGIC_RATE * (SDL_GetTicks() - word);

		doFPS();
	}
	return 0;
}

static void logisch(void)
{
	double tmpDelta;

	/* don't exceed target logic rate */
	while (app.deltaTime > 1)
	{
		tmpDelta = app.deltaTime;

		app.deltaTime = 1;

		logic(); // dungeon.c, hier word player logic gedaan

		app.deltaTime = (tmpDelta - 1);
	}

	logic();
}

static void doFPS(void)
{
	fps++;

	if (SDL_GetTicks() >= nextFPS)
	{
		app.dev.fps = fps;

		fps = 0;

		nextFPS = SDL_GetTicks() + 1000;
	}
}
