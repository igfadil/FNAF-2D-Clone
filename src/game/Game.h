#pragma once

#include "game/GameState.h"

class Game
{
public:
    Game();

    void Update();
    void Draw();

    // Current state machine
    GAMESTATE gameState;

    // Window size (optional but useful)
    int width;
    int height;

    // --- FNAF-style global game data ---
    // NOTE: power is a float, not an int. It drains by a fraction each frame
    // (powerDrain * deltaTime), and int -= float truncates to 0 every time,
    // which means the int version never actually decreases. Keep this a float
    // and only round it to an int when you DISPLAY it on screen.
    float power;
    float powerDrain;
    int night;
    int hour;
    float hourTimer; // seconds accumulated towards the next in-game hour

    bool leftDoorClosed;
    bool rightDoorClosed;

    bool cameraUp;

    bool shouldQuit; // set true from the menu's "Quit" option to end the program
};
