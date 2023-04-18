#ifndef draw_h
#define draw_h

#include "common.h"

void blit_angled(SDL_Texture *txtr, int x, int y, int angle);
void blit(SDL_Texture *texture, int x, int y, int center);

#endif // draw_h