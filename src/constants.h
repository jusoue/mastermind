#pragma once
#include "raylib.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define ROW_HEIGHT 100
#define ROW_WIDTH 500
#define COLUMN_WIDTH 100

enum class PieceColor {yellow, red, purple, green, blue, orange, empty};

constexpr Color toColor(PieceColor piece_color)
{
    switch(piece_color)
    {
    case PieceColor::yellow: return Color{ 255, 225, 0, 255 };
    case PieceColor::red: return RED;
    case PieceColor::purple: return PURPLE;
    case PieceColor::green: return GREEN;
    case PieceColor::blue: return BLUE;
    case PieceColor::orange: return ORANGE;
    default: return DARKBROWN;
    };
}