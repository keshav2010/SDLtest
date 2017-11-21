#include<iostream>
#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
using namespace std;
const string PlayState::playID="PLAY";

string PlayState::getStateID() const{
    return playID;
}
void PlayState::update()
{
    cout<<"PlayState update\n";
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getGameStateMachine()->pushState(new PauseState());
    }
    for(int i=0;i<m_gameObjects.size();i++)
    {
        m_gameObjects[i]->update();
    }
}
void PlayState::render()
{
    cout<<"PlayState render\n";
    for(int i=0;i<m_gameObjects.size();i++)
    {
        m_gameObjects[i]->draw();
    }
}
bool PlayState::onEnter()
{
    if(!TheTextureManager::Instance()->load("res/helicopter.bmp","helicopter",TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load("res/helicopter.bmp","helicopter2",TheGame::Instance()->getRenderer()))
        return false;

    GameObject* player = new Player(new LoaderParams(50,50,224,115, "helicopter"));
    GameObject* enemy = new Enemy(new LoaderParams(100,100,224,115, "helicopter2"));
    m_gameObjects.push_back(player);
    m_gameObjects.push_back(enemy);
    cout<<"enter playstate "<<m_gameObjects.size()<<" count of objectVector \n";
    return true;
}
bool PlayState::onExit()
{
    for(int i=0;i< m_gameObjects.size();i++)
        m_gameObjects[i]->clean();
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("helicopter");
    cout<<"exit playstate\n";
    return true;
}
