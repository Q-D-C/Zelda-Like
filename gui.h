#ifndef gui_h
#define gui_h

#include "common.h"

void initGUI();
void drawGUI();
void endGame();
void welkom();

extern SDL_Texture *load_texture(char *filename);
extern void blit(SDL_Texture *texture, int x, int y, int center);
extern void concierge(void);

extern Gui gui;
extern Entity *player;
extern Dungeon dungeon;

#endif // gui_h