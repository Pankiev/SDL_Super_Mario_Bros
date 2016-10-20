#pragma once
#include <SDL.h>

#define NO_ACTION 0

class Controller;

class HardwareController
{
public:

    HardwareController(Controller& mainController);

    void handle();

private:

    bool checkForAction();
    int  getEventType();
    int  getMousePosX();
    int  getMousePosY();
    bool isMouseInRect(SDL_Rect);
    int  getEventButton();
    int  getEventKey();
    void keyboardConstantAction();
    void keyboardDisposableAction();
    void mouseAction();

    Controller& mainController_;
    const Uint8* keyState_;
    SDL_Event event_;
    bool action_;
};
