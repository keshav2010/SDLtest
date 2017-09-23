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
#include<string>
class GameObject
{
    public:
        void load(int x,int y,int w,int h,std::string _textureID);
        void draw(SDL_Renderer* objectRenderer);
        void update();
        void clean();
    protected:
        std::string textureID; //fetches texture which is mapped to this key
        //SpriteSheet frame var
        int currentFrame;
        int currentRow;
        //-end
        int width;
        int height;
        int posX;//position in scene along X
        int posY;// position in scene along Y
};

#endif // GAMEOBJECT_H
