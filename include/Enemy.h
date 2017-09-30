#ifndef ENEMY_H
#define ENEMY_H

#include "SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams* params);
    virtual void draw();
    virtual void clean();
    virtual void update();

    /*
    void load(int x,int y,int w,int h,std::string _textureID);
    void draw(SDL_Renderer* objectRenderer);
    void update();
    void clean();
    */
};

#endif // ENEMY_H
