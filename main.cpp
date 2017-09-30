#include<SDL2/SDL.h>
#include<Game.h>
using namespace std;
int SDL_main(int argc, char* argv[])
{

    if(TheGame::Instance()->init("Chapter1",100,100,640,480))//,100,100,640,480,false))
    {
        //cout<<"game init done\n";
    }
    else return 1;
    while( TheGame::Instance()->isRunning)
    {
            TheGame::Instance()->handleEvent();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            SDL_Delay(10);
    }
    TheGame::Instance()->clean();
    return 0;
}
