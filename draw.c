#include "draw.h"

//blit functies komen uit de vorige opdrachten

void blit(SDL_Texture *txtr, int x, int y, int center)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    if (center)
    {
        dest.x -= dest.w / 2;
        dest.y -= dest.h / 2;
    }
    SDL_RenderCopy(renderer, txtr, NULL, &dest);
}

void blit_angled(SDL_Texture *txtr, int x, int y, int angle)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
    dest.x -= (dest.w / 2);
    dest.y -= dest.h / 2;

    //enige verandering die ik heb toegevoegd is deze:
    //omdat ik in mijn spel geen diagonalen gebruik heb ik deze
    //vast gezet op de 4 windstreken
    if (angle == FACING_UP)
    {
        SDL_RenderCopyEx(renderer, txtr, NULL, &dest, 0, NULL, SDL_FLIP_NONE);
    }
    if (angle == FACING_DOWN)
    {
        SDL_RenderCopyEx(renderer, txtr, NULL, &dest, 180, NULL, SDL_FLIP_NONE);
    }
    if (angle == FACING_LEFT)
    {
        SDL_RenderCopyEx(renderer, txtr, NULL, &dest, 270, NULL, SDL_FLIP_NONE);
    }
    if (angle == FACING_RIGHT)
    {
        SDL_RenderCopyEx(renderer, txtr, NULL, &dest, 90, NULL, SDL_FLIP_NONE);
    }
}
