#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
/*
    Base class of every Object in our game,including Player, NPC, etc

    every object in game :
    *every object has its cordinates (posX,posY) in scene
    *every object has method update() to update internal variables

    *every object has load method for initialization and to obtain its texture by
    receiving a textureKey (_ in name for distinguishing parameter from member
                            variable since else both have same name, we can use
                            this-pointer but its best to play safe)
    *every object has method that takes ptr to Screen Renderer (Window)
    *Clean method for clearing used memory
*/
#include<SDL2/SDL.h>
#include "LoaderParams.h"
#include<string>
class GameObject
{
    public:
        //virtual void load(int x,int y,int w,int h,std::string _textureID);
        virtual void draw()=0;//virtual void draw(SDL_Renderer* objectRenderer);
        virtual void update()=0;//virtual void update();
        virtual void clean()=0;//virtual void clean();
    protected:
        GameObject(const LoaderParams* params){}


};

#endif // GAMEOBJECT_H
