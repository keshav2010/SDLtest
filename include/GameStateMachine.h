#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H
#include<vector>
#include"GameState.h"
#include"PlayState.h"
#include"MenuState.h"
/*
    FSM : finite state machine
    > remove one state and adding another(pop-push)
    > adding 1 state on top of another (push)
    > remove state without adding another (clear top)(pop)
*/
class GameStateMachine
{
    public:
        void pushState(GameState* gameState);
        void changeState(GameState* gameState);
        void popState();

        void update();
        void render();
    private:
        std::vector<GameState*> stack_gameStates;
};

#endif // GAMESTATEMACHINE_H
