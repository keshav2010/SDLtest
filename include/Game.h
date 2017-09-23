#ifndef GAME_H
#define GAME_H


#include<SDL2/SDL.h>
class Game
{
    public:
        bool isRunning;
        int init(char*);
        void handleEvent();
        void render();
        void update();
        void clean();
        Game();

    private:
        int red,green,blue;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Rect *background_color;
};

#endif // GAME_H
