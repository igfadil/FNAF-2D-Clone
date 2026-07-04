#include "states/Camera.h"
#include "game/Game.h"
#include "HelperFuncs.h"

static int currentCam = 1;
static const int NUM_CAMERAS = 3;

void UpdateCamera(Game &game)
{
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ESCAPE))
    {
        game.cameraUp = false;
        game.gameState = OFFICE;
        return;
    }

    if (IsKeyPressed(KEY_RIGHT)) currentCam = (currentCam % NUM_CAMERAS) + 1;
    if (IsKeyPressed(KEY_LEFT))  currentCam = ((currentCam - 2 + NUM_CAMERAS) % NUM_CAMERAS) + 1;

    // Watching the cameras costs a bit of extra power on top of the base drain.
    game.power -= (game.powerDrain * 0.5f) * GetFrameTime();
    if (game.power < 0.0f) game.power = 0.0f;
}

void DrawCamera(const Game &game)
{
    ClearBackground(DARKGRAY);

    DrawCenteredTitleX(TextFormat("CAM %d", currentCam), 24, 10, WHITE);
    DrawText("[ STATIC FEED ]", game.width / 2 - 70, game.height / 2, 20, GRAY);

    DrawText(TextFormat("Power: %d%%", (int)game.power), 20, game.height - 60, 20, YELLOW);
    DrawText("[<-][->] Change Camera   [SPACE] Close Cameras", 20, game.height - 30, 16, LIGHTGRAY);
}
