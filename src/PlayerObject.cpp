#include "PlayerObject.h"
#include<iostream>
void PlayerObject::init(int x,int y)
{

    xpos=x;
    ypos=y;
    renderRect->x=xpos=x;
    renderRect->y=ypos=y;
    renderRect->w=10;
    renderRect->h=10;
}
void PlayerObject::update(int X,int Y)
{
    std::cout<<"---updating playerobject \n";
    renderRect->x=xpos=X;
    renderRect->y=ypos=Y;
}
void PlayerObject::render(SDL_Renderer *renderer)
{
    std::cout<<"----rendering player start \n";
    SDL_RenderFillRect(renderer,renderRect);
    std::cout<<"----rendering player done \n";
}

