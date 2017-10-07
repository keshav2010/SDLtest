#include<SDL2/SDL.h>
#include<Game.h>
using namespace std;
const int FPS=60;
const int DELAY_TIME =1000.0f / FPS;

int SDL_main(int argc, char* argv[])
{
    Uint32 frameStart,frameTime;
   if(TheGame::Instance()->init("Chapter1",100,100,640,480))//,100,100,640,480,false))
    {
        //cout<<"game init done\n";
    }
    else return 1;
    while( TheGame::Instance()->isRunning)
    {
            frameStart = SDL_GetTicks();

            TheGame::Instance()->handleEvent();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            frameTime = SDL_GetTicks()-frameStart;
            if(frameTime < DELAY_TIME) {
               //this is very idle time that is being wasted here
               SDL_Delay((int)(DELAY_TIME-frameTime));
            }
    }
    TheGame::Instance()->clean();
    return 0;
}
