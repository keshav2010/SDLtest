#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SDL2/SDL.h>
#include<vector>
#include"Vector2D.h"
//inputhandler class will handle input from keyboard and mouse only
enum mouse_buttons
{
    LEFT=0,
    MIDDLE=1,
    RIGHT=2
};
class InputHandler
{
public:
    static InputHandler* Instance();
    void update();
    void clean();
    Vector2D* getMousePosition();
    bool getMouseButtonState(int buttonNumber);
    bool isKeyDown(SDL_Scancode key);
private:
    InputHandler();
    ~InputHandler();
    static InputHandler* instance;
    //state arrays
    std::vector<bool> mouseButtonStates;
    const Uint8 *keystates; //holds the StateArray returned by : SDL_GetKeyboardState(int* numkey);
    //end of state arrays
    Vector2D* mousePosition;
};
typedef InputHandler TheInputHandler;
#endif // INPUTHANDLER_H
