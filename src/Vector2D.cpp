#include "Vector2D.h"

Vector2D::Vector2D(float x,float y)
{
    posX=x;
    posY=y;
}
void Vector2D::setX(float x){posX=x;}
void Vector2D::setY(float y){posY=y;}

float Vector2D::getX(){return posX;}
float Vector2D::getY(){return posY;}

//common operations
float Vector2D::length(){
    return sqrt(posX*posX + posY*posY);
}
Vector2D Vector2D::operator+(const Vector2D& v2) const{
    return Vector2D(posX+v2.posX,posY+v2.posY);
}
Vector2D& operator+=(Vector2D& v1,const Vector2D& v2) //friend function
{
    v1.posX += v2.posX;
    v1.posY += v2.posY;
    return v1;
}
Vector2D& operator-=(Vector2D& v1,const Vector2D& v2)//friend fxn
{
    v1.posX -= v2.posX;
    v1.posY -= v2.posY;
    return v1;
}
Vector2D Vector2D::operator-(const Vector2D& v2) const
{
    return Vector2D(posX-v2.posX,posY-v2.posY);
}
Vector2D Vector2D::operator/(float scalar)
{
    return Vector2D(posX/scalar,posY/scalar);
}
Vector2D& Vector2D::operator/=(float scalar)
{
    posX/=scalar;
    posY/=scalar;
    return (*this);
}
Vector2D& Vector2D::operator*=(float scalar)
{
    posX*=scalar;
    posY*=scalar;
    return (*this);
}
void Vector2D::normalize(){
    float l=length();
    if(l>0)
        (*this) *= 1/l;//call to overloaded *=
}
