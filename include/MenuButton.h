#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include "SDLGameObject.h"

class MenuButton:public SDLGameObject
{
    public:
        MenuButton(const LoaderParams* params,void (*callback)() );
        virtual void draw();
        virtual void update();
        virtual void clean();
        void (*m_callback)(); //fxn pointer

        //to handle clicking
        bool bReleased; //MouseButton-Released
    private:
        enum button_state
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };
};

#endif // MENUBUTTON_H
