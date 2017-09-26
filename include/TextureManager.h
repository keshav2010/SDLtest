#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include<map>
#include<SDL2/SDL.h>
#include<string>

class TextureManager
{
    public:
        bool load(std::string fileName,std::string id,SDL_Renderer* renderer);
        void draw(std::string id,int x,int y,int width,int height,SDL_Renderer* renderer,SDL_RendererFlip flip = SDL_FLIP_NONE,int angle=0);
        void drawFrame(std::string id,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer* renderer,SDL_RendererFlip flip=SDL_FLIP_NONE,int angle=0);
        static TextureManager* Instance();
    private:
    static TextureManager* s_pInstance;
    std::map<std::string,SDL_Texture*>textureMap;
    TextureManager(){};
};
typedef TextureManager TheTextureManager;
#endif // TEXTUREMANAGER_H
