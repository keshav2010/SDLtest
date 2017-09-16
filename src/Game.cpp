#include "Game.h"
#include<iostream>
#include<SDL2/SDL.h>
using namespace std;
Game::Game()
{
    isRunning=false;
    red=green=blue=0;
}
int Game::init(char*title)
{
    window = SDL_CreateWindow(title,100,100,500,500,SDL_WINDOW_RESIZABLE);
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
    SDL_RenderClear(renderer);//clear
    SDL_SetRenderDrawColor(renderer,red,green,blue,4);
    SDL_RenderPresent(renderer); //presenting result onto the Display
}
void Game::update()
{
    //mod 1000 to make sure values remain in range of int
    red=(red+10)%256;
    green=(green+5)%256;
    blue=(blue+2)%256;
    cout<<"UPDATING\n";
}
