#include "gui.h"

void initGUI()
{
    // om te beginnen worden alle textures opgeroepen voor de overlay

    gui.texture_banner = load_texture("gfx/banner/banner.png");
    gui.hearts[0] = load_texture("gfx/banner/1heartbanner.png");
    gui.hearts[1] = load_texture("gfx/banner/2heartbanner.png");
    gui.hearts[2] = load_texture("gfx/banner/3heartbanner.png");
    gui.bombcounter = load_texture("gfx/banner/bombbanner.png");
    gui.gemicon = load_texture("gfx/banner/gembanner.png");
    gui.swordthing = load_texture("gfx/banner/swordbanner.png");
    gui.gemcounter[0] = load_texture("gfx/banner/gembanner.png");
    gui.gemcounter[1] = load_texture("gfx/gemcounter/1.png");
    gui.gemcounter[2] = load_texture("gfx/gemcounter/2.png");
    gui.gemcounter[3] = load_texture("gfx/gemcounter/3.png");
    gui.gemcounter[4] = load_texture("gfx/gemcounter/4.png");
    gui.gemcounter[5] = load_texture("gfx/gemcounter/5.png");
    gui.gemcounter[6] = load_texture("gfx/gemcounter/6.png");
    gui.gemcounter[7] = load_texture("gfx/gemcounter/7.png");
    gui.gemcounter[8] = load_texture("gfx/gemcounter/8.png");
}

void drawGUI()
{
    // deze functies zal elke gameloop worden opgeroepen
    // en verwerkt met hoeveel gems en levens link heeft.

    blit(gui.texture_banner, 0, 0, 0);
    blit(gui.gemicon, 0, 0, 0);
    blit(gui.gemcounter[player->gem], 0, 0, 0);
    blit(gui.hearts[player->health], 0, 0, 0);
    blit(gui.bombcounter, 23, 0, 0);
    blit(gui.swordthing, 0, 0, 0);
}

void welkom()
{
    // de functie die word aangeroepen aan het begin van het spel om de speler welkom te heten
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "WELKOM AVONDTUURDER", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "IN DE DUNGEON", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "tm", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "IK BEN DE DUNGEON MASTER", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "aka NINO aka persoon die dit schreeft in de code", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "lijn 46 om specifiek te zijn :)", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "JOU DOEL (SHOULD YOU CHOOSE TO ACCEPT*)", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "*je hebt niet echt een keuze lol", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "IN DEZE DUNGEON ZIJN 8 EDELSTENEN VERBORGEN", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "VIND DEZE STENEN EN IK ZAL JE VRIJLATEN", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "MAAR PAS OP", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "ER ZIJN BADDIES IN DE DUNGEONtm", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "GEBRUIK JE SWAART (SPATIE) OM DEZE TE VERSLAAN", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "MISSCHIEN ZIJN ER OOK PLEKKEN VOOR JE BOMMEN(F) HINT HINT ", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "LOOP ROND (WASD) EN KIJK GOED ROND (IJKL) EN VERSLA DE DUNGEONtm", window);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELKOM", "SUCCES!!", window);
}

void endGame()
{
    // in elke gameloop word er ook nog gekeken of de game beindigd moet worden door te
    //  kijken of de speler dood is of alle gems gevonden zijn.
    if (player->health < 0)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GAME OVER", "helaas ben jij dood gegaan aan DE DUNGEON(TM)", window);
        exit(0);
    }
    if (player->gem > 7)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD"    , "jij hebt DE DUNGEON(TM) overwonnen! Held!", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt2", "Dank voor het spelen van mijn zelda wannabe", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt3", "Atlass heb ik al mijn gems terug en kan mijn world domination plan door gaan", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt4", "for legal reasons thats a joke", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt5", "kdoei", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt6", "okay dan niet", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt7", "ik wil graag dit moment nemen om wat te vertellen over the one and only", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt8", "the man the myth the legend", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt9", "SHAKESPEAR", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt10", "To be, or not to be: that is the question: Whether ’tis nobler in the mind to suffer", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt11", "What's in a name? That which we call a rose, By any other word would smell as sweet.", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt12", "All that glitters is not gold.", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt13", "tot zo ver de shakespear quotes", window);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "GEFELICITEERD pt14", "nu echt doei!!", window);
        exit(0);
    }
}