#include "Enemy.h"


Enemy::Enemy(const LoaderParams* params):SDLGameObject(params){
 velocity.setY(2);
 velocity.setX(0.001);
};

void Enemy::draw(){
    SDLGameObject::draw();
}
//void Player::draw(SDL_Renderer* renderer){GameObject::draw(renderer);}
void Enemy::update()
{
    //currentFrame = int (((SDL_GetTicks()/100) % numFrames));
    if(position.getY() < 0)
        velocity.setY(2);
    else if(position.getY() > 400)
        velocity.setY(-2);
    SDLGameObject::update();
    //posX+=1;    posY+=1;
}
void Enemy::clean()
{
//    cout<<"ENEMY CLEAN____________\n";
}
