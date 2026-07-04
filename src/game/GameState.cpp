#include "game/GameState.h"
#include "game/Game.h"
#include "states/Camera.h"
#include "states/Office.h"
#include "states/Menu.h"
#include "states/GameOver.h"

void UpdateGameState(Game &game)
{
    switch (game.gameState)
    {
        case OFFICE:
            UpdateOffice(game);
            break;

        case CAMERA:
            UpdateCamera(game);
            break;

        case MENU:
            UpdateMenu(game);
            break;

        case GAMEOVER:
            UpdateGameOver(game);
            break;
    }
}

void DrawGameState(Game &game)
{
    switch (game.gameState)
    {
        case OFFICE:
            DrawOffice(game);
            break;

        case CAMERA:
            DrawCamera(game);
            break;

        case MENU:
            DrawMenu(game);
            break;

        case GAMEOVER:
            DrawGameOver(game);
            break;
    }
}
