#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include<SDL2/SDL.h>
class Game
{

    SDL_Window *window;
    SDL_Renderer *renderer;
    public:

    int INIT();
    void handleEvent();
    void updateScreen();
    void getInputs();
    void clean();
};


#endif // GAME_H_INCLUDED
