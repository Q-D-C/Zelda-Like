#ifndef combat_h
#define combat_h

#include "common.h"

void DoVechten();
void doSwaart();
void doBoem(int init);
void spawnBaddie(int x, int y);
void initCombat();
void doePijn();
void boem(int x, int y);
void spawnFakeFriend(int x, int y);
void killMaybe(int x, int y);
void damageMaybe(int x, int y);
void muurMaybe(int x, int y);


// Weapondata data;

extern Entity *spawnEntity(void);
extern Entity *getEntityAt(int x, int y);

extern void blit_angled(SDL_Texture *txtr, int x, int y, int angle);
extern void blit(SDL_Texture *texture, int x, int y, int center);

extern Entity *player;
extern Entity *swaart;
extern Entity *bombo;
extern Dungeon dungeon;

#endif // combat_h