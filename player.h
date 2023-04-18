#ifndef player_h
#define player_h

#include "common.h"

void movePlayer(int dx, int dy);
void initPlayer(void);
void knopIndrukken(SDL_KeyboardEvent *event);
void knopLoslaten(SDL_KeyboardEvent *event);
void doPlayer(void);
void initGem(int x, int y);


extern SDL_Texture *load_texture(char *filename);
extern Entity *spawnEntity(void);
extern Entity *getEntityAt(int x, int y);

extern App app;
extern Entity *player;
extern Entity *swaart;
extern Entity *bombo;

#endif // player_h