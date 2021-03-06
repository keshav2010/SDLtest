#include "MenuState.h"
#include"TextureManager.h"
#include"Game.h"
#include<iostream>
#include"MenuButton.h"
using namespace std;

const string MenuState::menuID="MENU";

string MenuState::getStateID() const
{
    return menuID;
}
void MenuState::update()
{
    for(int i=0; i<gameObjects.size(); i++){
        gameObjects[i]->update();
    }
}
void MenuState::render()
{
    for(int i=0; i<gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}
void MenuState::s_menuToPlay()
{
    cout<<"play button clicked\n";
    TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
    cout<<"exit from menu\n";
    TheGame::Instance()->clean();
    exit(0);
}
bool MenuState::onEnter()
{
    if(!TheTextureManager::Instance()->load("res/play_button.bmp","playbutton", TheGame::Instance()->getRenderer()))
        return false;
    if(!TheTextureManager::Instance()->load("res/exit_button.bmp","exitbutton", TheGame::Instance()->getRenderer()))
        return false;

    //MenuButton(LoaderParams* , void (*callback)() )
    GameObject* button1= new MenuButton(new LoaderParams(100,100,150,100,"playbutton"), s_menuToPlay);
    GameObject* button2 = new MenuButton(new LoaderParams(100,300,150,100,"exitbutton"), s_exitFromMenu);
    gameObjects.push_back(button1);
    gameObjects.push_back(button2);
    cout<<"entering menustate\n";
    return true;
}
bool MenuState::onExit()
{
    for(int i=0;i<gameObjects.size();i++)
    {
        gameObjects[i]->clean();
    }
    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

    cout<<"exit menustate\n";
    return true;
}
