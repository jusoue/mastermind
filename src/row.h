#pragma once
#include "raylib.h"

class Board;

class Row 
{
public:
    Row(Board* parent, int pos);
    void drawRow();

private:
    void drawHintTile(int pos_x, int pos_y, Color color);
    void drawTile(int pos_x, int pos_y, Color color);

    Board* board = nullptr;
    int pos = 0;
};