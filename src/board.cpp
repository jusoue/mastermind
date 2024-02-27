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
}

void Board::drawBoard()
{
    for (int i = 0; i < rows.size(); i++)
    {
        rows[i].drawRow();
    }

    drawColorChoices();
}

Vector2 Board::getPosition()
{
    return position;
}

void Board::drawColorChoices()
{
    int choices_x = position.x;
    int choices_y = position.y + (nb_rows * ROW_HEIGHT) + 100;
    int radius = 30;
    for (int i = 0; i < 6; i++)
    {
        DrawCircle(choices_x + radius + (i * 90), choices_y, radius, toColor(PieceColor(i)));
        DrawCircleLines(choices_x + radius + (i * 90), choices_y, radius, BLACK);
    }

    DrawRectangle(choices_x + ((radius * 2) + 30) * 6, choices_y - 30, 100, 25, GRAY);
    DrawRectangle(choices_x + ((radius * 2) + 30) * 6, choices_y + 5, 100, 25, GRAY);
}
