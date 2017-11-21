#include "PauseState.h"
#include "Game.h"
#include "MenuButton.h"
#include<iostream>
#include "InputHandler.h"
using namespace std;
const string PauseState::s_pauseID = "PAUSE";
string PauseState::getStateID() const{
    return s_pauseID;
}
void PauseState::s_pauseToMain()
{
    TheGame::Instance()->getGameStateMachine()->changeState(new MenuState() );
}
void PauseState::s_resumePlay()
{
    TheGame::Instance()->getGameStateMachine()->popState();
}
void PauseState::update()
{
    for(int i=0; i<gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void PauseState::render()
{
    for(int i=0; i<gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

bool PauseState::onEnter()
{
    if(!TheTextureManager::Instance()->load("res/resumebutton.bmp","resumebutton",TheGame::Instance()->getRenderer()))
        return false;
    if(!TheTextureManager::Instance()->load("res/menubutton.bmp", "menubutton", TheGame::Instance()->getRenderer()))
        return false;
    GameObject *button1 = new MenuButton(new LoaderParams(200,50,120,50, "menubutton"), s_pauseToMain);
    GameObject *button2 = new MenuButton(new LoaderParams(200,150,120,50, "resumebutton"), s_resumePlay);
    gameObjects.push_back(button1);
    gameObjects.push_back(button2);
    std::cout<<"entering pauseState\n";
    return true;
}
bool PauseState::onExit()
{
    for(int i=0; i<gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }
    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
    //reset the mouse button states to false
    TheInputHandler::Instance()->reset();
    cout<<"exiting puaseState\n";
    return true;
}
