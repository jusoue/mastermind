#include "row.h"
#include "constants.h"
#include "board.h"

Row::Row(Board* parent, int pos)
    : board{parent}, pos{pos}
{

}

void Row::draw() const
{
    int pos_x = board->getPosition().x;
    int pos_y = board->getPosition().y + (ROW_HEIGHT * pos);

    // columns; 5 by default: 4 for the guesses, 1 for the hints
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            drawHintTile(pos_x + (i * COLUMN_WIDTH), pos_y);
        }
        else
        {
            drawTile(pos_x + (i * COLUMN_WIDTH), pos_y,
            (guessed_colors.size() > i) ? guessed_colors[i] : PieceColor::empty);
        }
    }
}

void Row::drawHintTile(int pos_x, int pos_y) const
{
    DrawRectangle(pos_x, pos_y, COLUMN_WIDTH, ROW_HEIGHT, DARKBROWN);
    DrawRectangleLines(pos_x, pos_y, COLUMN_WIDTH, ROW_HEIGHT, BLACK);

    // draw four circles for the four hints
    int center_x = pos_x + (COLUMN_WIDTH / 2);
    int center_y = pos_y + (ROW_HEIGHT / 2);
    float radius = (ROW_HEIGHT / 2 * 0.3f);
    int offset = (ROW_HEIGHT / 2 * 0.4f);

    if (auto hints = board->getHints(pos))
    {
        DrawCircle(center_x - offset, center_y - offset, radius, toColor((*hints)[0]));
        DrawCircle(center_x + offset, center_y - offset, radius, toColor((*hints)[1]));
        DrawCircle(center_x - offset, center_y + offset, radius, toColor((*hints)[2]));
        DrawCircle(center_x + offset, center_y + offset, radius, toColor((*hints)[3]));
    }
    else
    {
        DrawCircle(center_x - offset, center_y - offset, radius, BLACK);
        DrawCircle(center_x + offset, center_y - offset, radius, BLACK);
        DrawCircle(center_x - offset, center_y + offset, radius, BLACK);
        DrawCircle(center_x + offset, center_y + offset, radius, BLACK);
    }
}

void Row::drawTile(int pos_x, int pos_y, PieceColor color) const
{
    DrawRectangle(pos_x, pos_y, COLUMN_WIDTH, ROW_HEIGHT, BROWN);
    DrawRectangleLines(pos_x, pos_y, COLUMN_WIDTH, ROW_HEIGHT, BLACK);

    // draw one circle in the center of the tile
    int center_x = pos_x + (COLUMN_WIDTH / 2);
    int center_y = pos_y + (ROW_HEIGHT / 2);
    float radius = (ROW_HEIGHT / 2 * 0.6f);
    
    // TODO: Dessiner un cercle au bon endroit et de la bonne couleur.
    // Indice: il est possible de passer d'un objet PieceColor à un objet Color grâce à la fonction toColor()
    
}

void Row::addColorToGuess(PieceColor color)
{
    if (guessed_colors.size() < 4)
    {
        // TODO:: on ajoute la couleur aux couleurs devinées (guessed_colors)
        
    }
}

void Row::removeColorToGuess()
{
    if (!guessed_colors.empty())
    {
        // TODO:: on enlève la couleur des couleurs devinées (guessed_colors)
        
    }
}

std::vector<PieceColor> Row::getGuessedColors()
{
    return guessed_colors;
}