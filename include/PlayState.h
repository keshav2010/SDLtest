#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "GameState.h"

class PlayState:public GameState
{
    public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const;
    private:
        static const std::string playID;

};

#endif // PLAYSTATE_H
