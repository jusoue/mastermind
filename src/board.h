#pragma once
#include <vector>
#include "raylib.h"

#include "row.h"

class Board
{
public:
    Board(int nb_rows, Vector2 pos);
    void drawBoard();
    Vector2 getPosition();

private:
    int nb_rows = 0;
    int nb_coloumns = 0;
    Vector2 position = Vector2{0, 0};
    std::vector<Row> rows;
};