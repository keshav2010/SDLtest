#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include<SDL2/SDL.h>

class PlayerObject
{

    public:
        PlayerObject()
        {
           // cout<<"constructed\n";
            xpos=0;
            ypos=0;
            renderRect.x=0;
            renderRect.y=0;
            renderRect.w=10;
            renderRect.h=10;
        }
        void init(int x=0,int y=0);

        void render(SDL_Renderer*);
        void update(int,int);
        int xpos;
        int ypos;
        SDL_Rect renderRect;
};

#endif // PLAYEROBJECT_H
