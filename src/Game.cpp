#include "Game.h"
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_events.h>
#include<SDL2/SDL_keyboard.h>

using namespace std;
Game::Game()
{
    x=0;
    y=0;
    isRunning=false;
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
    textureManager.load("res/sprite.bmp","animate",renderer);
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
    textureManager.draw("animate",x+100,y+100,64,64,renderer,SDL_FLIP_NONE,angle);
    textureManager.draw("animate",x+100,y+190,angle%100,angle%100,renderer,SDL_FLIP_NONE,-1*angle);
    SDL_SetRenderDrawColor(renderer,20,0,20,4);
    SDL_RenderPresent(renderer); //presenting result onto the Display
    cout<<"RENDER DONE\n";
}
void Game::update()
{
    x=(x+1)%2;
    y=(y+1)%2;
    angle=(angle+1)%361;
    cout<<"UPDATING\n";
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
