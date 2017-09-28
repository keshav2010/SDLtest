#include "Game.h"
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_events.h>
#include<SDL2/SDL_keyboard.h>
using namespace std;
Game::Game()
{
    isRunning=false;
}
int Game::init(char*title)
{
    window = SDL_CreateWindow(title,100,50,1000,600,SDL_WINDOW_RESIZABLE);
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

    po=new Player();
    go=new GameObject();

    go->load(15,100,128,82,"animate");
    po->load(100,0,128,82,"animate");
    gameObjects.push_back(po);
    gameObjects.push_back(go);//enemy1);

    cout<<"Initialize Successful\n";
    isRunning=true;
    return 1;//init completed without errors
}
void Game::handleEvent()
{
    cout<<"HandleEvent Called\n";
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
}
void Game::render()
{
    cout<<"RENDERING\n";
    SDL_RenderClear(renderer);
    for(std::vector<GameObject*>::size_type i=0;i!=gameObjects.size();i++)
    {
        cout<<"gameobject "<<i<<"th draw call \n";
        gameObjects[i]->draw(renderer);
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
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
