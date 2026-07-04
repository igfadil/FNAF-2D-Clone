#include "states/GameOver.h"
#include "game/Game.h"
#include "HelperFuncs.h"

void UpdateGameOver(Game &game)
{
    if (IsKeyPressed(KEY_R))
    {
        RestartGame(game);
    }
}

void RestartGame(Game &game)
{
    game.power = 100.0f;
    game.hour = 0;
    game.hourTimer = 0.0f;
    game.night = 1;
    game.leftDoorClosed = false;
    game.rightDoorClosed = false;
    game.cameraUp = false;
    game.gameState = MENU;
}

void DrawGameOver(const Game &game)
{
    int displayHour = (game.hour == 0) ? 12 : game.hour;

    DrawCenteredTitleX("YOU DIED", 50, 150, RED);
    DrawCenteredTitleX(TextFormat("You made it to %d AM on Night %d", displayHour, game.night), 20, 230, LIGHTGRAY);
    DrawCenteredTitleX("Press R to restart", 20, 280, GRAY);
}
