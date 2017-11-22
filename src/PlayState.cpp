#include<iostream>
#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
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
    if(checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1]) ) )
    {
        TheGame::Instance()->getGameStateMachine()->pushState(new GameOverState());
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


bool PlayState::checkCollision(SDLGameObject *p1, SDLGameObject *p2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //get side of rectA
    leftA = p1->position.getX();
    rightA = p1->position.getX() + p1->width;
    topA = p1->position.getY();
    bottomA = p1->position.getY() + p1->height;

    //GET SIDE OF RECT-B
    leftB = p2->position.getX();
    rightB = p2->position.getX() + p2->width;
    topB = p2->position.getY();
    bottomB = p2->position.getY() + p2->height;

    if(bottomA<=bottomB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
        return false;

    return true;
}
