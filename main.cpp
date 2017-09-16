#include<SDL2/SDL.h>
#include<Game.h>
using namespace std;
int SDL_main(int argc, char* argv[])
{
    Game *game=new Game();
    game->init("LOL");
    while( game->isRunning )
    {
            game->handleEvent();
            game->update();
            game->render();
    }

    return 0;
}
