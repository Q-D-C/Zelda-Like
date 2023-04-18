#ifndef dungeon_h
#define dungeon_h

#include "common.h"

void logic(void);
void draw(void);
void shidSpawnen();

extern void initGUI();
extern void drawGUI();
extern void doPlayer(void);
extern void drawEntities(void);
extern void drawMap(void);
extern void initEntities(void);
extern void initMap(void);
extern void initPlayer(void);
extern void initGem(int x, int y);
extern void DoVechten();
extern void spawnBaddie(int x, int y);
extern void spawnFakeFriend(int x, int y);
extern void initCombat();
extern void endGame();
extern void damageMaybe(int x, int y);
extern void gemMaybe(int x, int y);

extern App app;
extern Dungeon dungeon;

#endif // dungeon_h