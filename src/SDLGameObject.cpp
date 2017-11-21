#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Game.h"
SDLGameObject::SDLGameObject(const LoaderParams* params)
: GameObject(params),acceleration(0,0),velocity(0,0),position(params->getX(),params->getY())
{
    width=params->getWidth();
    height=params->getHeight();
    textureID=params->getTextureID();
    currentFrame=currentRow=1;
}
void SDLGameObject::draw(){
 //   TextureManager::Instance()->draw(textureID,(int)position.getX(),(int)position.getY(),width,height,TheGame::Instance()->getRenderer(),SDL_FLIP_NONE,0);
    TextureManager::Instance()->drawFrame(textureID,(int)position.getX(),(int)position.getY(),width,height,currentRow,currentFrame,TheGame::Instance()->getRenderer(),SDL_FLIP_NONE);
    if(velocity.getX() > 0)
    {
        TextureManager::Instance()->drawFrame(textureID,(Uint32)position.getX(),(Uint32)position.getY(),width,height,currentRow,currentFrame,TheGame::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);

    }
    else
    {
           TextureManager::Instance()->drawFrame(textureID,(Uint32)position.getX(),(Uint32)position.getY(),width,height,currentRow,currentFrame,TheGame::Instance()->getRenderer(),SDL_FLIP_NONE);

    }
}
void SDLGameObject::clean(){
}
void SDLGameObject::update(){
    velocity += acceleration;
    position += velocity;
}
