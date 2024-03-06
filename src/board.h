#pragma once
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

private:
    void checkColorButtons();
    void checkBackButton();
    void checkEnterButton();
    void drawButtons() const;

    int nb_rows = 0;
    int nb_coloumns = 0;
    Vector2 position = Vector2{0, 0};
    std::vector<Row> rows;
    int turn = 0;

    std::vector<ColorButton> color_buttons;
    RectangleButton back_button;
    RectangleButton enter_button;
};