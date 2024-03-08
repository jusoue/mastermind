#include "board.h"
#include "constants.h"
#include "time.h"

#include <algorithm>

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

    back_button.setText("Back");
    enter_button.setText("Enter");

    srand(time(nullptr));
    for (int i = 0; i < 4; i++)
    {
        colors_to_guess[i] = (PieceColor)(rand() % 6);
    }
}

void Board::draw() const
{
    for (int i = 0; i < rows.size(); i++)
    {
        rows[i].draw();
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

std::array<PieceHint, 4>* Board::getHints(int index)
{
    if (index >= row_hints.size())
        return nullptr;

    return &row_hints[index];
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
    if (!enter_button.isPressed())
    {
        return;
    }

    const std::vector<PieceColor>& guessed_colors = rows[turn].getGuessedColors();
    std::array<PieceHint, 4> hints;
    if (guessed_colors.size() != 4)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (guessed_colors[i] == colors_to_guess[i])
        {
            hints[i] = PieceHint::correct;
        }
        else
        {
            auto it = std::find(colors_to_guess.begin(), colors_to_guess.end(), guessed_colors[i]);
            hints[i] = (it == colors_to_guess.end()) ? PieceHint::wrong : PieceHint::misplaced;
        }
    }

    row_hints.push_back(hints);
    turn++;

    // if turn = nb_rows -> game finished
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
