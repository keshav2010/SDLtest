#include "GameOverState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "LoaderParams.h"
using namespace std;
const string GameOverState::s_gameOverID = "GAMEOVER";
string GameOverState::getStateID() const
{
    return s_gameOverID;
}
void GameOverState::s_gameOverToMain()
{
    TheGame::Instance()->getGameStateMachine()->changeState(new MenuState());
}
void GameOverState::s_restartPlay()
{
    TheGame::Instance()->getGameStateMachine()->changeState(new PlayState());
}
void GameOverState::update()
{
    for(int i=0; i<gameObjects.size(); i++)
        gameObjects[i]->update();

}
void GameOverState::render()
{
    for(int i=0; i<gameObjects.size(); i++)
        gameObjects[i]->draw();

}
bool GameOverState::onEnter()
{
    //load textures
    if(!TheTextureManager::Instance()->load("res/gameover.bmp", "gameovertext", TheGame::Instance()->getRenderer()))
        return false;

    if(!TheTextureManager::Instance()->load("res/main.bmp", "mainbutton", TheGame::Instance()->getRenderer()))
        return false;

    //init game objects, and assign loaded texture to them
    GameObject *gameOverText = new AnimatedGraphic(new LoaderParams(200,100,190,30,"gameovertext"), 1);
    GameObject *button1 = new MenuButton(new LoaderParams(200,200,200,80, "mainbutton"), s_gameOverToMain);
    GameObject *button2 = new MenuButton(new LoaderParams(200,300,200,80,"restartbutton"), s_restartPlay);

    //include game objects in the state objects list so as to manipulate them , render them
    gameObjects.push_back(gameOverText);
    gameObjects.push_back(button1);
    gameObjects.push_back(button2);

    return true;
}

bool GameOverState::onExit()
{
    for(int i=0; i<gameObjects.size(); i++)
        gameObjects[i]->clean();

    gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
    return true;
}
