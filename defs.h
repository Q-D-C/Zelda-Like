#ifndef defs_h
#define defs_h

#define PI 						3.14159265358979323846

#define MIN(a, b) 				(((a) < (b)) ? (a) : (b))
#define MAX(a, b) 				(((a) > (b)) ? (a) : (b))

#define PLAYER_MAX_SPEED 		1	
#define MOVEDELAY 				10
#define EXPLOSIETIJD 			60

#define SCREEN_WIDTH 			1280
#define SCREEN_HEIGHT 			720

#define FPS 					60.0
#define LOGIC_RATE 				(FPS / 1000)

#define MAX_FILENAME_LENGTH 	256

#define MAX_KEYBOARD_KEYS 		350

#define MAX_SND_CHANNELS 		16

#define TILE_SIZE 				64
#define MAX_TILES 				64

#define MAP_WIDTH 				80
#define MAP_HEIGHT 				40

#define MAP_RENDER_WIDTH 		19
#define MAP_RENDER_HEIGHT 		9

#define TILE_HOLE 				0
#define TILE_GROUND 			1
#define TILE_WALL 				2

#define TILE_SIZE_IN_PIXELS 	256

#define VIEWPORT_WIDTH_IN_TILES (SCREEN_WIDTH / TILE_SIZE_IN_PIXELS)
#define VIEWPORT_HEIGHT_IN_TILES (SCREEN_HEIGHT / TILE_SIZE_IN_PIXELS)

typedef enum _keystate_
{
	UP = 0,
	DOWN = 1
} keystate;

enum richting
{
	FACING_LEFT,
	FACING_UP,
	FACING_RIGHT,
	FACING_DOWN
};

enum aliveness
{
	ALIVE_ALIVE,
	ALIVE_DEAD
};

enum solidness
{
	SOLID_NON_SOLID,
	SOLID_SOLID
};

enum entitytype
{
	GEM,
	BADDIE,
	FAKEWALL,
	BOMB
};

extern SDL_Window *window;
extern SDL_Renderer *renderer;

#endif