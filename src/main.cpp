#include <raylib.h>


const int WIDTH = 600;
const int HEIGHT = 900;

//Gamestates
enum class Gamestate {
    OFFICE,
    CAMERA,
    MENU,
    GAMEOVER
};

//Helper functions
void CreateCenteredTitleX(const char* text, int fontSize, int posY, Color color) {
    int textLength = MeasureText(text, fontSize);
    DrawText(text, WIDTH - textLength / 2, posY, fontSize, color);
}

int main() {
    InitWindow(WIDTH, HEIGHT, "FNAF Clone");
    SetExitKey(KEY_NULL);

    Gamestate::OFFICE;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }
    CloseWindow();
}