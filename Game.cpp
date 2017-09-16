#include "Game.h"

int Game::INIT()
{
    this->window = SDL_CreateWindow("Title",100,100,300,300,SDL_WINDOWPOS_CENTERED);
    this->renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(this->window == NULL || this->renderer == NULL)
        return 0;
    return 1;
}
