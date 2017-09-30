#ifndef GAME_H
#define GAME_H
#include"GameObject.h"
#include"Player.h"
#include<TextureManager.h>
#include"Enemy.h"
#include<SDL2/SDL.h>
#include<vector>
class Game
{
    public:
        bool isRunning;
        int init(char*title,int winX,int winY,int winW,int winH);
        void handleEvent();
        void render();
        void update();
        void clean();
        static Game* Instance();
        SDL_Renderer* getRenderer() const;

    private:
        Game();
        static Game* gameInstance;
        std::vector<GameObject*> gameObjects;

        SDL_Renderer *renderer;
        SDL_Window *window;

};
typedef Game TheGame;
#endif // GAME_H
