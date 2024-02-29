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
}

void Board::drawBoard()
{
    for (int i = 0; i < rows.size(); i++)
    {
        rows[i].drawRow();
    }

    drawColorButtons();
    checkColorButtons();
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
            SetTraceLogLevel(LOG_DEBUG);
            TraceLog(LOG_DEBUG, "test");
        }
    }
}

void Board::drawColorButtons()
{
    for (const auto& button : color_buttons)
    {
        button.draw();
    }

    // DrawRectangle(choices_x + ((radius * 2) + 30) * 6, choices_y - 30, 100, 25, GRAY);
    // DrawRectangle(choices_x + ((radius * 2) + 30) * 6, choices_y + 5, 100, 25, GRAY);
}
