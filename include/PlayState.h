#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "GameState.h"
#include<vector>
#include "GameObject.h"
#include "SDLGameObject.h"
class PlayState:public GameState
{
    public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    bool checkCollision(SDLGameObject *p1, SDLGameObject *p2);

    virtual std::string getStateID() const;
    private:
        static const std::string playID;

        std::vector<GameObject*> m_gameObjects;
};

#endif // PLAYSTATE_H
