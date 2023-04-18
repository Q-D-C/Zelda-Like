#ifndef entities_h
#define entities_h

#include "common.h"
void initEntities(void);
Entity *spawnEntity(void);
void drawEntities(void);
void doEntities(void);
Entity *getEntityAt(int x, int y);

extern void blit(SDL_Texture *texture, int x, int y, int center);
extern Dungeon dungeon;

#endif // entities_h