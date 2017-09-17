#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H
#include<SDL2/SDL.h>


class EnemyObject
{
    public:
        EnemyObject();
        void init(int x=0,int y=0);
        void render(SDL_Renderer*);
        void update(int,int);
        int xpos;
        int ypos;
        SDL_Rect renderRect;
};
#endif // ENEMYOBJECT_H
