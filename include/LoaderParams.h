#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
#include<string>

class LoaderParams
{
public:
    LoaderParams(int x,int y,int w,int h,std::string _textureID);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getTextureID() const;
private:
    int posX;
    int posY;
    int width;
    int height;
    std::string textureID;
};

#endif // LOADERPARAMS_H
