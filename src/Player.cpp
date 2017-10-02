#include "Player.h"
#include<iostream>
using namespace std;

Player::Player(const LoaderParams* params):SDLGameObject(params){};

void Player::draw(){SDLGameObject::draw();}
//void Player::draw(SDL_Renderer* renderer){GameObject::draw(renderer);}
void Player::update()
{
    position.setX( position.getX() + 1);
}
void Player::clean()
{
    cout<<"PLAYER CLEAN____________\n";
}
