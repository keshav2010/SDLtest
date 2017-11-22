#ifndef ANIMATEDGRAPHIC_H
#define ANIMATEDGRAPHIC_H
#include "LoaderParams.h"
#include "SDLGameObject.h"
class SDLGameObject;
class AnimatedGraphic : public SDLGameObject
{
    public:
        AnimatedGraphic(const LoaderParams* params, int animSpeed);
        virtual void update();
        virtual void draw();
        virtual void clean();

        bool bReleased;
    private:
        enum button_state
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };
        int m_animSpeed;
        int m_currentFrame,m_numFrames;
};

#endif // ANIMATEDGRAPHIC_H
