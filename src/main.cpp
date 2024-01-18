#include "raylib.h"

int main(int argc, char** argv)
{
    InitWindow(800, 800, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(25, 25, 400, 600, BROWN);
            DrawRectangleLines(25, 25, 400, 600, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}