#include "HelperFuncs.h"

void DrawCenteredTitleX(const char* text, int fontSize, int posY, Color color)
{
    int screenWidth = GetScreenWidth();
    int textLength = MeasureText(text, fontSize);
    DrawText(text, (screenWidth - textLength) / 2, posY, fontSize, color);
}