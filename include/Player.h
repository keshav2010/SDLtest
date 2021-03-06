#ifndef PLAYER_H
#define PLAYER_H
#include "SDLGameObject.h"
class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* params);
    virtual void draw();
    virtual void clean();
    virtual void update();

    /*
    void load(int x,int y,int w,int h,std::string _textureID); //
    void draw(SDL_Renderer* objectRenderer);
    void update();
    void clean();
    */
};

#endif // PLAYER_H
