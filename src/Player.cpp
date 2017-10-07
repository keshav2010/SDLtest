#include "InputHandler.h"
#include "Player.h"
#include<iostream>
using namespace std;

Player::Player(const LoaderParams* params):SDLGameObject(params){};

void Player::draw(){SDLGameObject::draw();}
//void Player::draw(SDL_Renderer* renderer){GameObject::draw(renderer);}
void Player::update()
{
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        velocity.setX(-1);
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        velocity.setX(1);
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        velocity.setY(-1);
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
        velocity.setY(1);
    SDLGameObject::update();
}
void Player::clean()
{
    cout<<"PLAYER CLEAN____________\n";
}
