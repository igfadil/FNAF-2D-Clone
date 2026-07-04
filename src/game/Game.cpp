#include "game/Game.h"
#include "game/GameState.h"

Game::Game()
{
    gameState = MENU; // start on the title screen, not straight in the office

    width = 600;
    height = 900;

    power = 100.0f;
    powerDrain = 0.2f; // base power drain per second
    hour = 0;          // 0 == 12 AM (midnight), night ends at hour 6 (6 AM)
    hourTimer = 0.0f;
    night = 1;

    leftDoorClosed = false;
    rightDoorClosed = false;
    cameraUp = false;

    shouldQuit = false;
}

void Game::Update()
{
    UpdateGameState(*this);
}

void Game::Draw()
{
    DrawGameState(*this);
}
