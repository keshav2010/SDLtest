#include "Player.h"
#include<iostream>
using namespace std;

void Player::load(int x,int y,int w,int h,string _textureID)
{
    GameObject::load(x,y,w,h,_textureID);
}
void Player::draw(SDL_Renderer* renderer)
{
    cout<<"PLAYER DRAW\n";
    GameObject::draw(renderer);
    cout<<"PLAYER DRAW COMPLETE\n";
}
void Player::update()
{
    cout<<"Player UPDATE\n";
    posY +=1;
}
void Player::clean()
{
    cout<<"PLAYER CLEAN____________\n";
}
