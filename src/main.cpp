#include "raylib.h"
#include "constants.h"
#include "board.h"

int main(int argc, char** argv)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mastermind");

    Board board(5, Vector2{25, 25});
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            board.drawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}