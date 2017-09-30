#include "LoaderParams.h"
using namespace std;
LoaderParams::LoaderParams(int x,int y,int w,int h,string _textureID):posX(x),posY(y),width(w),height(h),textureID(_textureID){}
int LoaderParams::getX() const{return posX;}
int LoaderParams::getY() const{return posY;}
int LoaderParams::getHeight() const{return height;}
int LoaderParams::getWidth() const{return width;}
string LoaderParams::getTextureID() const{return textureID;}
