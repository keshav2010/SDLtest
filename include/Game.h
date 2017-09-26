#ifndef GAME_H
#define GAME_H

#include<TextureManager.h>
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
        int x,y;
        int angle=0;
        int currentFrame;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Rect *background_color;
};

#endif // GAME_H
