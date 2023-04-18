#ifndef main_h
#define main_h

#include "common.h"

static void logisch(void);
static void doFPS(void);

extern void concierge(void);
extern void doInput(void);
extern void initDungeon(void);
extern void initGameSystem(void);
extern void doEntities(void);
extern void draw(void);
extern void logic(void);
extern void welkom();

App app;
Dungeon dungeon;
Entity *player;
Entity *swaart;
Entity *bombo;
Gui gui;

#endif // main_h