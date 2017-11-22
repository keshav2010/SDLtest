#include "GameStateMachine.h"
#include<iostream>
using namespace std;
void GameStateMachine::pushState(GameState* gameState)
{
    stack_gameStates.push_back(gameState);
    stack_gameStates.back()->onEnter();
}
void GameStateMachine::popState()
{
    if(!stack_gameStates.empty())
    {
        if( stack_gameStates.back()->onExit() )
        {
            //delete stack_gameStates.back();
            stack_gameStates.pop_back();
        }
    }
}
void GameStateMachine::changeState(GameState* gameState)
{
    cout<<"CALL TO CHANGESTATE\n";
    if(!stack_gameStates.empty())
    {
        if(stack_gameStates.back()->getStateID() == gameState->getStateID() )
        {   cout<<stack_gameStates.back()->getStateID()<<" << \n";
            cout<<" SAME STATES\n";
            return;//same state
        }
        if(stack_gameStates.back()->onExit())
        {
            //delete stack_gameStates.back();
            stack_gameStates.pop_back();
        }
    }

    cout<<"PUSHING BACK\n";
    stack_gameStates.push_back(gameState);//adding new state
    stack_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
    if(!stack_gameStates.empty())
        stack_gameStates.back()->update();
}
void GameStateMachine::render()
{
    if(!stack_gameStates.empty())
        stack_gameStates.back()->render();
}
