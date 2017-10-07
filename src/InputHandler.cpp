#include "InputHandler.h"
#include<iostream>
#include "Game.h"
using namespace std;
InputHandler* InputHandler::instance = 0;//static init
InputHandler::InputHandler(){
    cout<<"input handler constructor called\n";
    mouseButtonStates.push_back(false);
    mouseButtonStates.push_back(false);
    mouseButtonStates.push_back(false);
}
InputHandler* InputHandler::Instance()
{
    if(instance==0){
        instance=new InputHandler();
    }
    return instance;
}
Vector2D* InputHandler::getMousePosition()
{
    return mousePosition;
}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(keystates!=0)
    {
        if(keystates[key]==1)
            return true;
        else return false;
    }
    return false;
}
void InputHandler::update()
{

    SDL_Event event;
    keystates=SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            TheGame::Instance()->clean();
        }

        if(event.type == SDL_MOUSEMOTION)
        {
            mousePosition->setX(event.motion.x);
            mousePosition->setY(event.motion.y);
        }
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
                mouseButtonStates[LEFT]=true;
            if(event.button.button == SDL_BUTTON_MIDDLE)
                mouseButtonStates[MIDDLE]=true;
            if(event.button.button == SDL_BUTTON_RIGHT)
                mouseButtonStates[RIGHT]=true;
        }
        if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
                mouseButtonStates[LEFT]=false;
            if(event.button.button == SDL_BUTTON_MIDDLE)
                mouseButtonStates[MIDDLE]=false;
            if(event.button.button == SDL_BUTTON_RIGHT)
                mouseButtonStates[RIGHT]=false;
        }
    }
}
bool InputHandler::getMouseButtonState(int buttonNumber)
{
    return mouseButtonStates[buttonNumber];
}
