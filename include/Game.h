#ifndef GAME_H
#define GAME_H
#include"GameObject.h"
#include"Player.h"
#include<TextureManager.h>
#include<SDL2/SDL.h>
#include<vector>
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
        std::vector<GameObject*> gameObjects;

        GameObject* po;
        GameObject* go;

        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif // GAME_H
