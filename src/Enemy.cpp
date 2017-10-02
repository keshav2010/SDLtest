#include "Enemy.h"


Enemy::Enemy(const LoaderParams* params):SDLGameObject(params){};

void Enemy::draw(){SDLGameObject::draw();}
//void Player::draw(SDL_Renderer* renderer){GameObject::draw(renderer);}
void Enemy::update()
{
    position.setX( position.getX() + 1);
    position.setY( position.getY() + 1);
    //posX+=1;    posY+=1;
}
void Enemy::clean()
{
//    cout<<"ENEMY CLEAN____________\n";
}
