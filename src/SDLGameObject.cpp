#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Game.h"
SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params),position(params->getX(),params->getY())
{
    width=params->getWidth();
    height=params->getHeight();
    textureID=params->getTextureID();
    currentFrame=currentRow=1;
}
void SDLGameObject::draw(){
    TextureManager::Instance()->draw(textureID,(int)position.getX(),(int)position.getY(),width,height,TheGame::Instance()->getRenderer(),SDL_FLIP_NONE,0);
}
void SDLGameObject::clean(){
}
void SDLGameObject::update(){
}
