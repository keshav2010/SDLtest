#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "GameState.h"
#include "Game.h"
class GameObject;
class GameOverState : public GameState
{
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();
        virtual std::string getStateID() const;
    private:
        static void s_gameOverToMain();
        static void s_restartPlay();
        static const std::string s_gameOverID;
        std::vector<GameObject*> gameObjects;
};
#endif // GAMEOVERSTATE_H
