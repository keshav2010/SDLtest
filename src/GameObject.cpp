#include "GameObject.h"
#include<iostream>
#include"TextureManager.h"
#include<SDL2/SDL.h>
using namespace std;

void GameObject::load(int x,int y,int w,int h,string _textureID)
{   //init positions
    posX=x;
    posY=y;

    //width,height and resp. textureKey to MAP it to a texture obj
    width=w;
    height=h;
    textureID=_textureID;
    //for handling possible 2D spritesheet to display anim
    currentRow=1;
    currentFrame=1;
}
void GameObject::draw(SDL_Renderer* objectRenderer)
{
    //handle render
    //TheTextureManager::Instance()->drawFrame(textureID,posX,posY,width,height,currentRow,currentFrame,objectRenderer);
    cout<<"GAMEOBJECT draw\n";
    TheTextureManager::Instance()->draw(textureID,posX,posY,width,height,objectRenderer,SDL_FLIP_NONE);
}
void GameObject::update()
{
   //handle member variables
   posX++;
}
void GameObject::clean()
{
    //handle clean
    cout<<"clean game object\n";
}
