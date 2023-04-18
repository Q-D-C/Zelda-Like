#include "combat.h"

static double lontje;

void DoVechten()
{
    // DoVechten regelt eigenlijk alle combat van onze link.
    // deze functie word bij elke stap aangeroepen en de
    // locatie en orientatie van het zwaard word berekent.

    int x = 0;
    int y = 0;

    x = player->x - dungeon.camera.x;
    y = player->y - dungeon.camera.y;

    x = (x * TILE_SIZE) + (TILE_SIZE / 2);
    y = (y * TILE_SIZE) + (TILE_SIZE / 2);

    x += dungeon.renderOffset.x;
    y += dungeon.renderOffset.y;

    if (player->facing == FACING_UP)
    {
        swaart->x = x;
        swaart->y = y - TILE_SIZE;
    }
    if (player->facing == FACING_DOWN)
    {
        swaart->x = x;
        swaart->y = y + TILE_SIZE;
    }
    if (player->facing == FACING_RIGHT)
    {
        swaart->x = x + TILE_SIZE;
        swaart->y = y;
    }
    if (player->facing == FACING_LEFT)
    {
        swaart->x = x - TILE_SIZE;
        swaart->y = y;
    }
    swaart->facing = player->facing;

    // Op het moment dat er in doplayer() een bom word "aangevraagd"
    // Word er gekeken of er al een bom gerenderd is
    // Zo niet word er een nieuwe bom aangemaakt en het "lontje gereset"
    // Daarna word de locatie door gegeven aan boem()

    if (bombo->vraagteken == 0 && bombo->renderenvraagteken == 1)
    {

        bombo->vraagteken = 1;
        lontje = EXPLOSIETIJD;

        boem(player->x, player->y);
    }

    // als laatste worden de functies voor de bom en het zwaard aangeroepen

    boem(0, 0);
    doSwaart();
}

void boem(int x, int y)
{
    // omdat elke frame docombat() word opgeroepen draait deze functie ook elke frame
    // vandaar word er eerst een tick van het "lontje afgehaald"

    lontje = MAX(0, lontje - app.deltaTime);

    // daarna word er gekeken of de functie voor het eerst word aangeroepen voor een nieuwe bom
    //(dat door dat er 0,0 word door gegeven ipv coordinaten)
    // of dat hij alleen word aangeroepen om de berekeningen te doen.
    if (x != 0 && y != 0)
    {
        bombo->x = x;
        bombo->y = y;
    }
    // daarna word er door alle texture cycles heen gegaan om de explosie te simuleren
    if (bombo->renderenvraagteken)
    {
        if (lontje < 20)
        {
            if (lontje < 10)
            {
                if (lontje == 0)
                {
                    // aan het einde van het lontje worden de render flags van de bom op 0 gezet
                    bombo->vraagteken = 0;
                    bombo->renderenvraagteken = 0;
                    // daarna word er bij alle coordinaten om de bom heen gekeken of daar
                    // een entity is of een muur die "gebroken" moet worden
                    killMaybe(bombo->x - 1, bombo->y);
                    killMaybe(bombo->x + 1, bombo->y);
                    killMaybe(bombo->x, bombo->y - 1);
                    killMaybe(bombo->x, bombo->y + 1);
                    killMaybe(bombo->x, bombo->y + 1);
                    killMaybe(bombo->x, bombo->y);
                    muurMaybe(bombo->x - 1, bombo->y);
                    muurMaybe(bombo->x + 1, bombo->y);
                    muurMaybe(bombo->x, bombo->y - 1);
                    muurMaybe(bombo->x, bombo->y + 1);
                    muurMaybe(bombo->x, bombo->y + 1);
                    muurMaybe(bombo->x, bombo->y);
                }
                else
                {
                    bombo->texture[0] = load_texture("gfx/bomb/bomb2.png");
                }
            }
            else
            {
                bombo->texture[0] = load_texture("gfx/bomb/bomb1.png");
            }
        }
        else
        {
            bombo->texture[0] = load_texture("gfx/bomb/bomb.png");
        }
    }
}

// killMaybe() en muurMaybe() doen in de basis vrijwel het zelfde,
// er word een temp entity aangemaakt waarmee word gekeken of er op de aangevraagde locatie
// een killable entity zit. als die daar zit zal zijn alive flag op dood gezet worden

void killMaybe(int x, int y)
{
    Entity *e;
    e = getEntityAt(x, y);

    if (e != NULL)
    {
        if (e->entitytype == BADDIE)
        {
            e->alive = ALIVE_DEAD;
        }
    }
}

void muurMaybe(int x, int y)
{
    Entity *e;
    e = getEntityAt(x, y);

    if (e != NULL)
    {
        if (e->entitytype == FAKEWALL)
        {
            e->alive = ALIVE_DEAD;
        }
    }
}

void damageMaybe(int x, int y)
{

    // enige verschil tussen de bovenstaande functies en damageMaybe() is dat deze word
    // aangeroepen tijdens het lopen en als er een entity is zal deze 1 HP van de speler afhalen

    Entity *e;
    e = getEntityAt(x, y);

    if (e != NULL && e->entitytype == BADDIE)
    {
        doePijn();
    }
}

void spawnBaddie(int x, int y)
{
    // dit is een simpele functie die de baddie inlaad en de textures hier van.
    Entity *e;
    e = spawnEntity();
    e->x = x;
    e->y = y;
    e->texture[FACING_LEFT] = load_texture("gfx/Goblin/left.png");
    e->texture[FACING_RIGHT] = load_texture("gfx/Goblin/right.png");
    e->texture[FACING_DOWN] = load_texture("gfx/Goblin/down.png");
    e->texture[FACING_UP] = load_texture("gfx/Goblin/up.png");
    e->entitytype = BADDIE;
    e->renderenvraagteken = 1;
}

void spawnFakeFriend(int x, int y)
{

    // dit is een functie die de nep muur aanmaakt.

    Entity *e;

    e = spawnEntity();
    e->x = x;
    e->y = y;
    e->texture[FACING_LEFT] = load_texture("gfx/fakewall.png");
    e->entitytype = FAKEWALL;
    e->solid = SOLID_SOLID;
    e->renderenvraagteken = 1;
}

void initCombat()
{
    // dit is de functie die entities aanmaakt voor de bom en het zwaard
    swaart = spawnEntity();
    swaart->texture[0] = load_texture("gfx/sword.png");

    bombo = spawnEntity();

    bombo->vraagteken = 0;
    bombo->entitytype = BOMB;
}

void doSwaart()
{
    // doSwaart word elke frame opgeroepen waar eerst gekeken word of de render flag aanstaat
    if (swaart->renderenvraagteken)
    {
        // zo ja, word het zwaard gerenderd
        blit_angled(swaart->texture[0], swaart->x, swaart->y, swaart->facing);

        swaart->renderenvraagteken = 0;

        // en word er met de killMaybe() functie gekeken of er op de plek van het zwaard
        //  een entity is die "dood" gemaakt moet worden
        if (swaart->facing == FACING_UP)
        {
            killMaybe(player->x, player->y - 1);
        }
        if (swaart->facing == FACING_DOWN)
        {
            killMaybe(player->x, player->y + 1);
        }
        if (swaart->facing == FACING_RIGHT)
        {
            killMaybe(player->x + 1, player->y);
        }
        if (swaart->facing == FACING_LEFT)
        {
            killMaybe(player->x - 1, player->y);
        }
    }
}

void doePijn()
{
    //als laatste in deze header is er nog een functie die 1 HP van link's hitpoints afhaald
    player->health--;
}
