#include "states/Office.h"
#include "game/Game.h"
#include "HelperFuncs.h"

// How many real-time seconds one in-game hour takes.
// (6 hours per night * 15s = 90 real seconds per night)
static const float HOUR_LENGTH_SECONDS = 15.0f;

void UpdateOffice(Game &game)
{
    float dt = GetFrameTime();

    // --- Input ---
    if (IsKeyPressed(KEY_A)) game.leftDoorClosed = !game.leftDoorClosed;
    if (IsKeyPressed(KEY_D)) game.rightDoorClosed = !game.rightDoorClosed;

    if (IsKeyPressed(KEY_SPACE))
    {
        game.cameraUp = true;
        game.gameState = CAMERA;
        return; // don't also drain power for this frame in two states
    }

    // --- Power drain ---
    // Closing a door costs extra power, just like in FNAF.
    float drain = game.powerDrain;
    if (game.leftDoorClosed)  drain += 0.3f;
    if (game.rightDoorClosed) drain += 0.3f;

    game.power -= drain * dt;

    if (game.power <= 0.0f)
    {
        game.power = 0.0f;
        game.gameState = GAMEOVER;
        return;
    }

    // --- Time progression ---
    game.hourTimer += dt;
    if (game.hourTimer >= HOUR_LENGTH_SECONDS)
    {
        game.hourTimer = 0.0f;
        game.hour++;

        if (game.hour >= 6)
        {
            // 6 AM - the player survived the night!
            game.night++;
            game.gameState = MENU;
        }
    }
}

void DrawOffice(const Game &game)
{
    DrawCenteredTitleX("OFFICE", 20, 10, WHITE);

    int displayHour = (game.hour == 0) ? 12 : game.hour;
    DrawText(TextFormat("%d AM", displayHour), 20, 40, 20, WHITE);
    DrawText(TextFormat("Night %d", game.night), game.width - 110, 40, 20, WHITE);

    DrawText(game.leftDoorClosed ? "Left Door: CLOSED" : "Left Door: open",
             20, 100, 18, game.leftDoorClosed ? RED : GREEN);
    DrawText(game.rightDoorClosed ? "Right Door: CLOSED" : "Right Door: open",
             game.width - 220, 100, 18, game.rightDoorClosed ? RED : GREEN);

    DrawText(TextFormat("Power: %d%%", (int)game.power), 20, game.height - 60, 20, YELLOW);
    DrawText("[A] Left Door   [D] Right Door   [SPACE] Cameras", 20, game.height - 30, 16, GRAY);
}
