#include "Game.h"
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_events.h>
#include<SDL2/SDL_keyboard.h>
#include "InputHandler.h"
using namespace std;
Game* Game::gameInstance=0;
Game::Game()
{
    isRunning=false;
}
Game* Game::Instance()
{
    if(gameInstance==0)
    {
        gameInstance=new Game();
        return gameInstance;
    }
    return gameInstance;
}

SDL_Renderer* Game::getRenderer()const {return renderer;}
int Game::init(char*title,int winX,int winY,int winW,int winH)
{
    window = SDL_CreateWindow(title,winX,winY,winW,winH,SDL_WINDOW_RESIZABLE);
    if(window==NULL)
    {
        cout<<"Failed to Initialize Window in Game object\n"<<SDL_GetError();
        return 0;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);//hardware accelerated
    if(renderer==NULL)
    {
        cout<<"Unable to Create Renderer for window in Game Object \n"<<SDL_GetError();
        return 0;
    }
    //textureManager.load("res/sprite.bmp","animate",renderer);
    if(!TheTextureManager::Instance()->load("res/sprite.bmp","animate",renderer) )
        return 0;

    gameObjects.push_back(new Player(new LoaderParams(100,50,54,54,"animate")));
    gameObjects.push_back(new Enemy(new LoaderParams(100,50,54,54,"animate")));
    cout<<"Initialize Successful\n";
    isRunning=true;
    return 1;//init completed without errors
}
void Game::handleEvent()
{
    cout<<"HandleEvent Called\n";

    TheInputHandler::Instance()->update();
    /*
    SDL_Event evt;

	if(SDL_PollEvent(&evt))
	{
		switch(evt.type)
		{
			case SDL_QUIT:
				isRunning=false;
				cout<<" QUIT EVENT \n";
				break;
            default:
				break;
		}
	}
	*/
}
void Game::render()
{
    cout<<"RENDERING\n";
    SDL_RenderClear(renderer);
    for(std::vector<GameObject*>::size_type i=0;i!=gameObjects.size();i++)
    {
        cout<<"gameobject "<<i<<"th draw call \n";
        gameObjects[i]->draw();
         cout<<"gameobject "<<i<<"th draw call COMPLETE\n";
    }
    SDL_RenderPresent(renderer); //presenting result onto the Display
    cout<<"RENDER DONE\n";
}
void Game::update()
{
    for(vector<GameObject*>::size_type i=0;i!=gameObjects.size();i++)
    {
        gameObjects[i]->update();
    }
    cout<<"UPDATING\n";
}

void Game::clean()
{
     for(vector<GameObject*>::size_type i=0;i!=gameObjects.size();i++)
    {
        gameObjects[i]->clean();
        delete gameObjects[i];
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
