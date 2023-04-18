#include "entities.h"

static int turnedvraagteken;

void initEntities(void)
{
	// tail van linked list wijst naar de head
	dungeon.entityTail = &dungeon.entityHead;
}

Entity *spawnEntity(void)
{
	// elke entity die aangemaakt word gaat door deze functie heen
	Entity *e;

	// er word geheugen aangemaakt
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	dungeon.entityTail->next = e;
	dungeon.entityTail = e;

	// hij krijgt een facing voor het renderen
	e->facing = FACING_LEFT;

	// en word terug gestuurd
	return e;
}

void drawEntities(void)
{
	// in deze functie worden alle mogelijke entities naar het scherm verplaatst
	Entity *e;
	int x, y;

	for (e = dungeon.entityHead.next; e != NULL; e = e->next) // eerst een forloop om door de hele linked list te gaan
	{
		if (e->renderenvraagteken)
		{
			// daarna word er gekeken of de entity in het camera berijk is
			x = e->x - dungeon.camera.x;
			y = e->y - dungeon.camera.y;

			if (x >= 0 && y >= 0 && x < MAP_RENDER_WIDTH && y < MAP_RENDER_HEIGHT) // && e->entitytype != BOMB)
			{
				// midden van de tile word gezocht
				x = (x * TILE_SIZE) + (TILE_SIZE / 2);
				y = (y * TILE_SIZE) + (TILE_SIZE / 2);

				x += dungeon.renderOffset.x;
				y += dungeon.renderOffset.y;

				// texture word geblit
				if (e->facing == FACING_LEFT)
				{
					blit(e->texture[FACING_LEFT], x, y, 1);
				}
				if (e->facing == FACING_RIGHT)
				{
					blit(e->texture[FACING_RIGHT], x, y, 1);
				}
				if (e->facing == FACING_UP)
				{
					blit(e->texture[FACING_UP], x, y, 1);
				}
				if (e->facing == FACING_DOWN)
				{
					blit(e->texture[FACING_DOWN], x, y, 1);
				}
			}
		}
	}
}

void doEntities(void)
{
	// deze functie loopt de hele linked list af en verwerkt de entities die verwerkt moeten worden
	Entity *e, *prev;

	prev = &dungeon.entityHead;

	for (e = dungeon.entityHead.next; e != NULL; e = e->next)
	{
		// eerst het draaien van de baddies zodat ze niet allemaal de zelfde kant op kijken
		// daardoor zullen er blindspots in hun defence komen
		if (e->entitytype == BADDIE && turnedvraagteken == 0)
		{
			e->facing = rand() % 4;
		}

		// dan kijken of er "dode" entities zijn die uit de linked list gehaald moeten worden

		if (e->alive == ALIVE_DEAD)
		{
			if (e == dungeon.entityTail)
			{
				dungeon.entityTail = prev;
			}

			prev->next = e->next;
			free(e);
			e = prev;
		}

		prev = e;
	}
	turnedvraagteken = 1;
}

Entity *getEntityAt(int x, int y)
{
	// Dit is een functie waarmee word gekeken of er op een bepaalde locatie in het grid een entity is
	//  als dit het geval is word die entity terug gegeven, anders word er NULL terug gegeven.
	Entity *e;

	for (e = dungeon.entityHead.next; e != NULL; e = e->next)
	{
		if (e->x == x && e->y == y)
		{
			return e;
		}
	}

	return NULL;
}