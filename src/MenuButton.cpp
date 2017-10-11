#include "MenuButton.h"
#include "InputHandler.h"
#include<iostream>
using namespace std;
MenuButton::MenuButton(const LoaderParams* params,void (*callback)()): SDLGameObject(params),m_callback(callback)
{
    currentFrame = MOUSE_OUT;
}
void MenuButton::draw()
{
    SDLGameObject::draw();
}
void MenuButton::update()
{
    Vector2D* mousePos = TheInputHandler::Instance()->getMousePosition();
    if(mousePos->getX() < (position.getX() + width) && mousePos->getX() > position.getX()
       && mousePos->getY() < (position.getY()+height) && mousePos->getY() > position.getY())
    {
        currentFrame = MOUSE_OVER;
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
        {
            currentFrame = CLICKED;
            m_callback();//call our callback fxn
            bReleased = false;
        }
        else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT))
        {
            bReleased =true;
            currentFrame = MOUSE_OVER;
        }
    }
    else currentFrame = MOUSE_OUT;
}
void MenuButton::clean()
{

    cout<<"called menu button clean\n";
}
