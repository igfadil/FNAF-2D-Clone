#include "states/Menu.h"
#include "game/Game.h"
#include "HelperFuncs.h"

static int selected = 0; // 0 = Start, 1 = Quit
static const int NUM_OPTIONS = 2;

void UpdateMenu(Game &game)
{
    if (IsKeyPressed(KEY_DOWN)) selected = (selected + 1) % NUM_OPTIONS;
    if (IsKeyPressed(KEY_UP))   selected = (selected - 1 + NUM_OPTIONS) % NUM_OPTIONS;

    if (IsKeyPressed(KEY_ENTER))
    {
        if (selected == 0)
        {
            game.gameState = OFFICE;
        }
        else
        {
            game.shouldQuit = true;
        }
    }
}

void DrawMenu(const Game &game)
{
    DrawCenteredTitleX("FNAF CLONE", 40, 120, WHITE);
    DrawCenteredTitleX(TextFormat("Night %d", game.night), 24, 200, LIGHTGRAY);

    DrawCenteredTitleX(selected == 0 ? "> START <" : "START", 22, 280, selected == 0 ? YELLOW : GRAY);
    DrawCenteredTitleX(selected == 1 ? "> QUIT <"  : "QUIT",  22, 320, selected == 1 ? YELLOW : GRAY);

    DrawCenteredTitleX("[UP/DOWN] Select   [ENTER] Confirm", 16, game.height - 40, GRAY);
}
