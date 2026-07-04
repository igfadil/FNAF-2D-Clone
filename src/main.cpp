#include <raylib.h>

#include "game/GameState.h"
#include "game/Game.h"
#include "states/Office.h"
#include "states/Camera.h"
#include "states/Menu.h"
#include "states/GameOver.h"

int main()
{
    Game game;
    InitWindow(game.width, game.height, "FNAF Clone");
    SetExitKey(KEY_NULL);


    while(!WindowShouldClose() && !game.shouldQuit) {
        BeginDrawing();
        ClearBackground(BLACK);

        game.Update();
        game.Draw();

        EndDrawing();
    }
    CloseWindow();
}