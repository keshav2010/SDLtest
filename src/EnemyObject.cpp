#include "EnemyObject.h"

#include<iostream>
        EnemyObject::EnemyObject()
        {
           // cout<<"constructed\n";
            xpos=0;
            ypos=0;
            renderRect.x=0;
            renderRect.y=0;
            renderRect.w=10;
            renderRect.h=10;
        }
void EnemyObject::init(int x,int y)
{
    xpos=x;
    ypos=y;
    renderRect.x=xpos=x;
    renderRect.y=ypos=y;
    renderRect.w=10;
    renderRect.h=10;
}
void EnemyObject::update(int X,int Y)
{
    std::cout<<"---updating enemy object \n";
    renderRect.x=xpos=X;
    renderRect.y=ypos=Y;
    std::cout<<"enemy x : "<<xpos<<"\n enemy y : "<<ypos<<"\n";
}
void EnemyObject::render(SDL_Renderer *renderer)
{
    std::cout<<"----rendering enemy start \n";
    SDL_RenderFillRect(renderer,&renderRect);
    std::cout<<"----rendering enemy done \n";
}
