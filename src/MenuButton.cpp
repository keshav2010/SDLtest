#include "MenuButton.h"
#include "InputHandler.h"
#include<iostream>
using namespace std;
MenuButton::MenuButton(const LoaderParams* params): SDLGameObject(params)
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
        }
    }
    else currentFrame = MOUSE_OUT;
}
void MenuButton::clean()
{

    cout<<"called menu button clean\n";
}
