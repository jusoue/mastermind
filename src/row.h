#pragma once
#include "raylib.h"

class Board;

class Row 
{
public:
    Row(Board* parent, int pos);
    void drawRow();

private:
    Board* board = nullptr;
    int pos = 0;
};