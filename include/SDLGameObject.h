#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include "GameObject.h"
#include "Vector2D.h"
class SDLGameObject:public GameObject
{
    public:
        SDLGameObject(const LoaderParams* params);
        virtual void draw();
        virtual void update();
        virtual void clean();
    protected:
        Vector2D position;
        int width;
        int height;
        int currentRow;
        int currentFrame;
        std::string textureID;
};

#endif // SDLGAMEOBJECT_H
