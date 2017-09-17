#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include<SDL2/SDL.h>

class PlayerObject
{

    public:
        void init(int x=0,int y=0);

        void render(SDL_Renderer*);
        void update(int,int);
        int xpos;
        int ypos;
        SDL_Rect *renderRect;
};

#endif // PLAYEROBJECT_H
