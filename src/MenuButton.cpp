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

    //check if mouse over image
    if(mousePos->getX() < (position.getX() + width) && mousePos->getX() > position.getX()
       && mousePos->getY() < (position.getY()+height) && mousePos->getY() > position.getY())
    {
        currentFrame = MOUSE_OVER;
        //check if mouse left pressed, then call the callback function
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && bReleased)
        {
            currentFrame = CLICKED;
            cout<<"calling callback method now \n";
            m_callback();//call our callback fxn
            bReleased = false;
        }
        else if(! TheInputHandler::Instance()->getMouseButtonState(LEFT))
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
