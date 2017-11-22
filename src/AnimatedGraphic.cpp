#include "AnimatedGraphic.h"
#include "SDLGameObject.h"
#include <iostream>
using namespace std;
AnimatedGraphic::AnimatedGraphic(const LoaderParams* params, int animSpeed): m_animSpeed(animSpeed),SDLGameObject(params)
{
    if(m_animSpeed == 0)
        m_animSpeed = 1;
    m_numFrames = 1;
}
void AnimatedGraphic::update()
{
    m_currentFrame = int(((SDL_GetTicks()/(1000 / m_animSpeed)) % m_numFrames));
}
void AnimatedGraphic::clean()
{
    cout<<"animatedgraphic clean\n";
}
void AnimatedGraphic::draw()
{
    SDLGameObject::draw();
}
