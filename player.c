#include "player.h"

static double moveDelay;
static int startedvraagteken;

void initPlayer(void)
{
	// hier word de player aangemaakt

	player = spawnEntity(); // vervolgens word er een speler aangemaakt op basis van de entity struct.

	player->x = 2;
	player->y = 2;
	player->texture[FACING_LEFT] = load_texture("gfx/player/left.png");
	player->texture[FACING_UP] = load_texture("gfx/player/up.png"); // daarna worden de coordinaten en texture opgeslagen
	player->texture[FACING_RIGHT] = load_texture("gfx/player/right.png");
	player->texture[FACING_DOWN] = load_texture("gfx/player/down.png");
	player->renderenvraagteken = 1;
	player->gem = 0;
	player->health = 2;

	movePlayer(-1, -1); // move player word nog aangeroepen zodat de camera naar de goede plek gaat

	moveDelay = 0;
}

void doInput(void)
{
	// hier word de input verwerkt
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
			exit(0);
			break;

		case SDL_KEYDOWN: // elke ingedrukte knop word doorgestuurt
			knopLoslaten(&event.key);
			break;

		case SDL_KEYUP: // en ook als hij word losgelaten
			knopIndrukken(&event.key);
			break;
		default:
			break;
		}
	}
}

void knopIndrukken(SDL_KeyboardEvent *event)
{
	// als de knop niet een repeat is of een knop die we niet willen gebruiken
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		// word de knop opgeslagen in de applicatie struct
		app.keyboard[event->keysym.scancode] = 0;
	}
}

void knopLoslaten(SDL_KeyboardEvent *event)
{
	// als de knop niet een repeat is of een knop die we niet willen gebruiken
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		// word de knop opgeslagen in de applicatie struct
		app.keyboard[event->keysym.scancode] = 1;
	}
}

void doPlayer(void)
{

	moveDelay = MAX(0, moveDelay - app.deltaTime);

	// als de beweeg cooldown afgelopen is word er in de applicatie struct gekeken naar welke knop is ingedrukt
	// vervolgens word de speler verplaast en de kijkrichting aangepast in de entity struct

	if (moveDelay == 0)
	{

		if (app.keyboard[SDL_SCANCODE_A])
		{
			movePlayer(-1, 0);
		}
		if (app.keyboard[SDL_SCANCODE_D])
		{
			movePlayer(1, 0);
		}
		if (app.keyboard[SDL_SCANCODE_W])
		{
			movePlayer(0, -1);
		}
		if (app.keyboard[SDL_SCANCODE_S])
		{
			movePlayer(0, 1);
		}
		if (app.keyboard[SDL_SCANCODE_J])
		{
			player->facing = FACING_LEFT;
		}
		if (app.keyboard[SDL_SCANCODE_L])
		{
			player->facing = FACING_RIGHT;
		}
		if (app.keyboard[SDL_SCANCODE_I])
		{
			player->facing = FACING_UP;
		}
		if (app.keyboard[SDL_SCANCODE_K])
		{
			player->facing = FACING_DOWN;
		}
	}
	// na de movement word er ook nog gecheckt of er gevecht word
	if (app.keyboard[SDL_SCANCODE_SPACE])
	{
		swaart->renderenvraagteken = 1;
	}
	if (app.keyboard[SDL_SCANCODE_F])
	{
		bombo->renderenvraagteken = 1;
	}
	if (app.keyboard[SDL_SCANCODE_ESCAPE])
	{
		exit(0);
	}
}

void initGem(int x, int y)
{
	// deze functie maakt de gem coin entity aan en zet hem op de meegegeven coordinaten
	// inspawnt. daarnaast krijgt hij een texture en een paar flags voor andere functies

	Entity *e;

	e = spawnEntity();
	e->x = x;
	e->y = y;
	e->texture[FACING_LEFT] = load_texture("gfx/gem.png");
	e->entitytype = GEM;
	e->alive = ALIVE_ALIVE;
	e->renderenvraagteken = 1;
}

void movePlayer(int dx, int dy)
{
	// move player struct is waar de meeste berekeningen gebeuren
	int x, y;
	Entity *e;

	// als eerste worden de nieuwe coordinaten (na het bewegen) vastgesteld
	x = player->x + dx;
	y = player->y + dy;

	// door middel van de MAX en MIN macro word er vast gesteld of hij niet buiten het berijk van de map is
	x = MAX(0, MIN(x, MAP_WIDTH - 1));
	y = MAX(0, MIN(y, MAP_HEIGHT - 1));

	// vervolgens word er gekeken in de map of de plek waar we heen willen grond is en niet muur/gat
	if (dungeon.map.data[x][y] == TILE_GROUND)
	{
		// daarna word er gekeken of er op de plek waar we heen gaan een entity is (entities.c)
		e = getEntityAt(x, y);
		// als er een entity is zal er een struct terug gegeven worden en anders NULL

		// daarna is er een started flag zodat deze functies niet de eerste frame worden opgeroepen
		// gebeurt dit wel, dan zal de game crashen omdat er nog niks in de wereld
		// bestaat dat gelezen kan worden door de functies
		if (startedvraagteken)
		{
			damageMaybe(x, y); // beschreven in combat.c

			gemMaybe(x, y); // en dan word er gekeken of er een gem is die opgepakt kan worden
		}
		// als er op die locatie niks is of een non solid iets word de player verplaatst
		if (e == NULL || e->solid == SOLID_NON_SOLID || e == player)
		{
			player->x = x;
			player->y = y;

			// en de camera word verrekent

			dungeon.camera.x = x;
			dungeon.camera.x -= (MAP_RENDER_WIDTH / 2);
			dungeon.camera.x = MIN(MAX(dungeon.camera.x, 0), MAP_WIDTH - MAP_RENDER_WIDTH);

			dungeon.camera.y = y;
			dungeon.camera.y -= (MAP_RENDER_HEIGHT / 2);
			dungeon.camera.y = MIN(MAX(dungeon.camera.y, 0), MAP_HEIGHT - MAP_RENDER_HEIGHT);

			moveDelay = MOVEDELAY;
		}
		startedvraagteken = 1;
	}
}

void gemMaybe(int x, int y)
{
	// en dan nog een functie die kijkt of er een gem is en deze "oppakt"
	Entity *e;

	e = getEntityAt(x, y);

	if (e != NULL && e->entitytype == GEM)
	{
		// gem aantal word verhoogt
		player->gem++;
		// de entity word "dood" gemaakt
		e->alive = ALIVE_DEAD;
	}
}
