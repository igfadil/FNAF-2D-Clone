#include <raylib.h>

#include "GameState.h"
#include "states/Office.h"
#include "states/Camera.h"
#include "states/Menu.h"
#include "states/GameOver.h"


const int WIDTH = 600;
const int HEIGHT = 900;


int main()
{
    InitWindow(WIDTH, HEIGHT, "FNAF Clone");
    SetExitKey(KEY_NULL);

    GAMESTATE gameState = OFFICE;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }
    CloseWindow();
}