#pragma once
#include <array>
#include <vector>
#include "raylib.h"

#include "row.h"
#include "colorButton.h"
#include "rectangleButton.h"

class Board
{
public:
    Board(int nb_rows, Vector2 pos);
    void draw() const;
    void update();
    Vector2 getPosition();
    std::array<PieceHint, 4>* getHints(int index);

private:
    void checkColorButtons();
    void checkBackButton();
    void checkEnterButton();
    void checkGameOver();
    void checkVictory();
    void drawButtons() const;

    int nb_rows = 0;
    Vector2 position = Vector2{0, 0};
    std::vector<Row> rows;
    int turn = 0;
    bool is_game_over = false;
    bool is_victory = false;

    std::vector<ColorButton> color_buttons;
    RectangleButton back_button;
    RectangleButton enter_button;

    std::array<PieceColor, 4> colors_to_guess;
    std::vector<std::array<PieceHint, 4>> row_hints;
};