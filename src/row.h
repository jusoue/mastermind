#pragma once
#include "raylib.h"
#include "constants.h"
#include <array>
#include <vector>

class Board;

class Row 
{
public:
    Row(Board* parent, int pos);
    void draw() const;
    void addColorToGuess(PieceColor color);
    void removeColorToGuess();
    std::vector<PieceColor> getGuessedColors();

private:
    void drawHintTile(int pos_x, int pos_y) const;
    void drawTile(int pos_x, int pos_y, PieceColor color) const;

    Board* board = nullptr;
    int pos = 0;
    std::vector<PieceColor> guessed_colors;
    int entered_colors = 0;
};