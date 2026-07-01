#include "GameState.h"

#include "game/GameState.h"
#include "states/Camera.h"
#include "states/Office.h"
#include "states/Menu.h"
#include "states/GameOver.h"

void UpdateGameState(GAMESTATE &gameState)
{
    switch (gameState)
    {
        case OFFICE:
            UpdateOffice(gameState);
            break;

        case CAMERA:
            UpdateCamera(gameState);
            break;

        case MENU:
            UpdateMenu(gameState);
            break;

        case GAMEOVER:
            UpdateGameOver(gameState);
            break;
    }
}

void DrawGameState(GAMESTATE gameState)
{
    switch (gameState)
    {
        case OFFICE:
            DrawOffice();
            break;

        case CAMERA:
            DrawCamera();
            break;

        case MENU:
            DrawMenu();
            break;

        case GAMEOVER:
            DrawGameOver();
            break;
    }
}