#include "row.h"
#include "constants.h"
#include "board.h"

Row::Row(Board* parent, int pos)
    : board{parent}, pos{pos}
{

}

void Row::drawRow()
{
    int pos_x = board->getPosition().x;
    int pos_y = board->getPosition().y + (ROW_HEIGHT * pos);
    DrawRectangle(pos_y, pos_x, ROW_WIDTH, ROW_HEIGHT, BROWN);
    DrawRectangleLines(pos_y, pos_x, ROW_WIDTH, ROW_HEIGHT, BLACK);
}