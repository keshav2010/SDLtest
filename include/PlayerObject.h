#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include<SDL2/SDL.h>
#include<GameObject.h>
class PlayerObject : public GameObject
{
    public:
        void load(int x,int y,int width,int height,std::string textureID);
        void draw(SDL_Renderer* pRenderer);
        void update();
        void clean();
};

#endif // PLAYEROBJECT_H
