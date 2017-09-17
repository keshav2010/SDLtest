#include "Game.h"
#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_events.h>
#include<SDL2/SDL_keyboard.h>
#include "PlayerObject.h"

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

    player.init(0,0);

    //enemy->init(100,100);
    obj2.init(100,100);cout<<"yo\n";
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
            case SDL_KEYDOWN:
            {
                SDL_Keycode keypressed=evt.key.keysym.sym;
                if(keypressed==SDLK_ESCAPE){
                    cout<<"escape pressed\n";
                    isRunning=false;
                }
                else if(keypressed==SDLK_a)
                {
                    player.xpos-=2;//=player->xpos-1;
                }
                else if(keypressed==SDLK_d)
                {
                        player.xpos+=2;//=player->xpos+1;
                }
                else if(keypressed==SDLK_w)
                {
                    player.ypos-=2;
                }
                else if(keypressed==SDLK_s)
                {
                    player.ypos+=2;
                }
                break;
            }
            case SDL_KEYUP:
            {
                cout<<"key release detected\n";
                break;
            }
            default:
				break;
		}
	}
}
void Game::render()
{   cout<<"RENDERING\n";

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,0,250,200,4);
    player.render(renderer);

    SDL_SetRenderDrawColor(renderer,255,0,0,4);
    obj2.render(renderer);

    SDL_SetRenderDrawColor(renderer,0,0,0,4);
    SDL_RenderPresent(renderer); //presenting result onto the Display
    cout<<"RENDER DONE\n";
}
void Game::update()
{
    //mod 1000 to make sure values remain in range of int
    player.update(player.xpos,player.ypos);
    obj2.update(++obj2.xpos,++obj2.ypos);
    cout<<"UPDATING\n";
}

void Game::clean()
{
//    player=nullptr;
   // obj2=nullptr;
   // enemy=nullptr;
}
