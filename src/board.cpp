#include "board.h"
#include "constants.h"

Board::Board(int nb_rows, Vector2 pos)
    : nb_rows{nb_rows}, position{pos}
{
    for (int i = 0; i < nb_rows; i++)
    {
        Row row(this, i);
        rows.push_back(row);
    }

    float radius = 30;
    float center_y = position.y + (nb_rows * ROW_HEIGHT) + 100;
    for (int i = 0; i < 6; i++)
    {
        float center_x = position.x + radius + (i * 90);
        ColorButton button(
            {center_x , center_y}, 
            radius, 
            PieceColor(i)
        );

        color_buttons.push_back(button);
    }

    float pos_y = position.y + (nb_rows * ROW_HEIGHT) + 150;
    float pos_x = position.x;

    back_button = RectangleButton({ pos_x, pos_y }, {ROW_WIDTH / 2 - 50, 50}, GRAY);
    enter_button = RectangleButton({ pos_x + ROW_WIDTH - ROW_WIDTH / 2 + 50, pos_y }, {ROW_WIDTH / 2 - 50, 50}, GRAY);
}

void Board::draw() const
{
    for (int i = 0; i < rows.size(); i++)
    {
        rows[i].drawRow();
    }

    drawButtons();
}

void Board::update()
{
    checkColorButtons();
    checkBackButton();
    checkEnterButton();
}

Vector2 Board::getPosition()
{
    return position;
}

void Board::checkColorButtons()
{
    for (const auto& button : color_buttons)
    {
        if (button.isPressed())
        {
            rows[turn].addColorToGuess(button.getColor());
        }
    }
}

void Board::checkBackButton()
{
    if (back_button.isPressed())
    {
        rows[turn].removeColorToGuess();
    }
}

void Board::checkEnterButton()
{
    if (enter_button.isPressed())
    {
        TraceLog(LOG_DEBUG, "enter");
    }
}

void Board::drawButtons() const
{
    for (const auto& button : color_buttons)
    {
        button.draw();
    }

    float pos_y = position.y + (nb_rows * ROW_HEIGHT) + 150;
    float pos_x = position.x;

    back_button.draw();
    enter_button.draw();
}
