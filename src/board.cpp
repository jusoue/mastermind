#include "board.h"

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
}

Vector2 Board::getPosition()
{
    return position;
}
