#pragma once

enum GAMESTATE
{
    OFFICE,
    CAMERA,
    MENU,
    GAMEOVER
};

void UpdateGameState(GAMESTATE &gameState);
void DrawGameState(GAMESTATE gameState);