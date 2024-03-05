#pragma once
#include "raylib.h"

class Board;

class Row 
{
public:
    Row(Board* parent, int pos);
    void drawRow() const;

private:
    void drawHintTile(int pos_x, int pos_y, Color color) const;
    void drawTile(int pos_x, int pos_y, Color color) const;

    Board* board = nullptr;
    int pos = 0;
};