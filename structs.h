#ifndef structs_h
#define structs_h

typedef struct _mouse_
{
	int x;
	int y;
	SDL_Texture *txtr_reticle;
} mouse;

typedef struct _gui_
{
	SDL_Texture *texture_banner;
	SDL_Texture *hearts[3];
	SDL_Texture *bombcounter;
	SDL_Texture *gemicon;
	SDL_Texture *gemcounter[9];
	SDL_Texture *swordthing;
} Gui;

typedef struct _map_
{
	int data[MAP_WIDTH][MAP_HEIGHT];
} Map;

typedef struct _entity_
{
	int x;
	int y;
	int facing;
	int alive;
	int solid;
	int entitytype;
	SDL_Texture *texture[4];
	int vraagteken;
	int renderenvraagteken;
	int gem;
	int health;
	struct _entity_ *next;
} Entity;

typedef struct _dungeon_
{
	SDL_Point camera;
	SDL_Point renderOffset;
	Entity entityHead, *entityTail;
	Map map;
} Dungeon;

typedef struct _applicatie_
{
	int keyboard[MAX_KEYBOARD_KEYS];
	double deltaTime;
	struct _dev_
	{
		int fps;
	} dev;
} App;

#endif
