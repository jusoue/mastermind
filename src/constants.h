#pragma once
#include "raylib.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int ROW_HEIGHT = 100;
const int ROW_WIDTH = 500;
const int COLUMN_WIDTH = 100;
const int BUTTON_WIDTH = ROW_WIDTH / 2 - 50;
const int BOARD_END = 25 + ROW_WIDTH;

enum class PieceColor {yellow, red, purple, green, blue, orange, empty};
enum class PieceHint {correct, wrong, misplaced};

constexpr Color toColor(PieceColor piece_color)
{
    switch(piece_color)
    {
    case PieceColor::yellow: return Color{ 255, 225, 0, 255 }; // YELLOW is too bright
    case PieceColor::red: return RED;
    case PieceColor::purple: return PURPLE;
    case PieceColor::green: return GREEN;
    case PieceColor::blue: return BLUE;
    case PieceColor::orange: return ORANGE;
    default: return DARKBROWN;
    };
}

constexpr Color toColor(PieceHint piece_hint)
{
    switch(piece_hint)
    {
    case PieceHint::correct: return DARKGREEN;
    case PieceHint::wrong: return RED;
    case PieceHint::misplaced: return Color{ 255, 225, 0, 255 };
    default: return BLACK;
    }
}