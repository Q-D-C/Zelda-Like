#ifndef map_h
#define map_h

#include "common.h"

void loadTiles(void);
void drawMapTiles(void);
char *readFile(char *filename);
void loadMap(void);
void initMap(void);
void drawMap(void);

extern void blitAtlasImage(SDL_Texture *atlasImage, int x, int y, int center, SDL_RendererFlip flip);
// extern SDL_Texture *getAtlasImage(char *filename, int required);

extern Dungeon dungeon;

#endif // map_h