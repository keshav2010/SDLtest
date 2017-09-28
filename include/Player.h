#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
class Player : public GameObject
{
public:
    void load(int x,int y,int w,int h,std::string _textureID);
    void draw(SDL_Renderer* objectRenderer);
    void update();
    void clean();
};

#endif // PLAYER_H
