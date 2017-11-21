#include "TextureManager.h"
#include<map>
using namespace std;
/*
Why SDL_CreateTextureFromSurface requires a renderer ?
> [ source : https://stackoverflow.com/questions/34429342/sdl2-why-does-sdl-createtexturefromsurface-need-a-renderer]
>
You need SDL_Renderer to get information about the applicable constraints:
maximum supported size
pixel format


goto the mentioned link to explore reason
 */
 TextureManager* TextureManager::s_pInstance=0;//static instance
 TextureManager* TextureManager::Instance()
 {
     if(s_pInstance==0)
     {
         s_pInstance=new TextureManager();
         return s_pInstance;
     }
     return s_pInstance;
 }
 void TextureManager::clearFromTextureMap(string id)
 {
     textureMap.erase(id);
 }
bool TextureManager::load(string fileName,string id,SDL_Renderer* renderer)
{

    SDL_Surface* tempSurface = SDL_LoadBMP(fileName.c_str());
    if(tempSurface==0)
        return false;
    SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    if(texture!=0)
    {
        textureMap[id]=texture;
        return true;
    }
    return false;
}
void TextureManager::draw(string id,int x,int y,int width,int height, SDL_Renderer* renderer,SDL_RendererFlip flip,int angle)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x=0;
    srcRect.y=0;
    srcRect.w=destRect.w=width;
    srcRect.h=destRect.h=height;
    destRect.x=x;
    destRect.y=y;
    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, angle,0, flip);
}
/*
    Intuition for the src AND dest Rectangles

    by changing x,y,w,h of sourceRect we can clip the texture image that is being imported
    by changing the x,y,w,h of destRect we can alter the dimensions of the image and nothing will be clipped but only stretched
*/
void TextureManager::drawFrame(string id,int x,int y,int width,int height,int currentRow,int currentFrame,SDL_Renderer* renderer,SDL_RendererFlip flip,int angle)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x=width*currentFrame;
    srcRect.y=height*(currentRow-1);
    srcRect.w=destRect.w=width;
    srcRect.h=destRect.h=height;
    destRect.x=x;
    destRect.y=y;
    SDL_RenderCopyEx(renderer,textureMap[id],&srcRect,&destRect,angle,0,flip);
}
