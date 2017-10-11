#ifndef MENUSTATE_H
#define MENUSTATE_H
#include<vector>
#include"GameObject.h"
#include "GameState.h"
class MenuState : public GameState
{
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();
        virtual std::string getStateID() const;
        std::vector<GameObject*> gameObjects;

    private:
        static const std::string menuID;

        //call back fxns for menu items
        static void s_menuToPlay();
        static void s_exitFromMenu();
};

#endif // MENUSTATE_H
