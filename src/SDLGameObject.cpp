#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"
SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params){
    posX = params->getX();
    posY = params->getY();
    width=params->getWidth();
    height=params->getHeight();
    textureID=params->getTextureID();
    currentFrame=currentRow=1;
}
void SDLGameObject::draw(){
    TextureManager::Instance()->draw(textureID,posX,posY,width,height,TheGame::Instance()->getRenderer(),SDL_FLIP_NONE,0);
}
void SDLGameObject::clean(){
}
void SDLGameObject::update(){
}
