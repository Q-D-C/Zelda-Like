#include "init.h"

void init_window()
{

    // alles om de window te intitialiseren uit de vorige opdrachten (blorp)

    unsigned int window_flags = 0;
    unsigned int renderer_flags = SDL_RENDERER_ACCELERATED;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("Zelda wannabe",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, window_flags);
    if (window == NULL)
    {
        printf("Failed to create window -- Error: %s\n",
               SDL_GetError());
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, renderer_flags);
    if (renderer == NULL)
    {
        printf("Failed to create renderer -- Error: %s\n",
               SDL_GetError());
        exit(1);
    }
}

void concierge(void)
{
    //deze functie word altijd opgeroepen als de game afsluit (door atexit) en zal
    //zorgen dat alles netjes opgeruimd is 
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();
}

SDL_Texture *load_texture(char *filename)
{
    SDL_Texture *txtr;
    txtr = IMG_LoadTexture(renderer, filename);
    return txtr;
}
