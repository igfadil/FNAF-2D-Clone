#pragma once

enum GAMESTATE
{
    OFFICE,
    CAMERA,
    MENU,
    GAMEOVER
};

// Forward declaration only - we don't need Game's full definition here,
// just the promise that a class called Game exists. This avoids a circular
// #include (Game.h includes this file for the GAMESTATE enum).
class Game;

void UpdateGameState(Game &game);
void DrawGameState(Game &game);
