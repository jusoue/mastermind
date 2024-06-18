#include "board.h"
#include "constants.h"
#include "time.h"

#include <algorithm>

Board::Board(int nb_rows, Vector2 pos)
    : nb_rows{nb_rows}, position{pos}
{
    float pos_y = position.y + (nb_rows * ROW_HEIGHT) + 150;
    float pos_x = position.x;

    back_button = RectangleButton({ pos_x, pos_y }, {BUTTON_WIDTH, 50}, GRAY);
    enter_button = RectangleButton({ pos_x + ROW_WIDTH - ROW_WIDTH / 2 + 50, pos_y }, {BUTTON_WIDTH, 50}, GRAY);
    try_again_button = RectangleButton({BOARD_END + ((WINDOW_WIDTH - (BOARD_END) - (BUTTON_WIDTH)) / 2), 450}, {BUTTON_WIDTH, 50}, GRAY);

    // TODO: Nommez le texte sur les boutons du jeu



    // TODO: Initialiser le board
    
}

void Board::draw() const
{
    // TODO: Dessiner toutes les rangées du board

    // TODO: Dessiner tous les boutons

    // TODO: Dessiner les éléments de fin de jeu si je la partie est terminée
   
}

void Board::update()
{
    // TODO: Si le jeu n'est pas fini, vérifier l'état de tous les boutons. Sinon, vérifier l'était du bouton "Try Again"
   

   
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

void Board::initialize()
{
    // TODO: Créer le bon nombre de rangées (Row) puis les mettre dans l'objet rows




    float radius = 30;
    float center_y = position.y + (nb_rows * ROW_HEIGHT) + 100;
    for (int i = 0; i < 6; i++)
    {
        float center_x = position.x + radius + (i * 90);
        // TODO: Créer un bouton de la bonne couleur puis le mettre dans l'objet color_buttons
        


    }

    // On choisit la suite de 4 couleurs à deviner au hasard
    srand(time(nullptr));
    for (int i = 0; i < 4; i++)
    {
        colors_to_guess[i] = (PieceColor)(rand() % 6);
    }
}

void Board::clearBoard()
{
    is_game_over = false;
    is_victory = false;
    turn = 0;

    rows.clear();
    color_buttons.clear();
    row_hints.clear();
}

void Board::checkColorButtons()
{
    for (const auto& button : color_buttons)
    {
        // TODO: Si un des boutons de couleur est appuyé, on ajoute la couleur du bouton au guess du joueur
        // Indice: la variable "turn" indique à quelle tour (ou rangée du plateau...) on est



    }
}

void Board::checkBackButton()
{
    // TODO: Si le bouton pour enlever une couleur du guess est appuyé, on enlève la couleur du guess
    // Indice: la variable "turn" indique à quelle tour (ou rangée du plateau...) on est



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

    // TODO: Vérifier si le joueur a gagné


    row_hints.push_back(hints);
    turn++;

    // TODO: Vérifier si le joueur a perdu
    
}

void Board::checkTryAgainButton()
{
    // TODO: Si le bouton pour réessayer de jouer est appuyé, on réinitialise le tableau de jeu



}

void Board::checkGameOver()
{
    if (is_game_over)
        return;

    // TODO: si on a utilisé le nombre maximum de rangées, c'est game over!
    

}

void Board::checkVictory()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (colors_to_guess[i] == rows[turn].getGuessedColors()[i])
            count++;
    }

    // TODO: Si les 4 couleurs devinées sont bonnes, alors c'est game over et on a gagné!
    



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

void Board::drawGameOver() const
{
    const char* message = is_victory ? "You won!" : "You lost.";
    Vector2 text_size = MeasureTextEx(GetFontDefault(), message, 30, 0);
    DrawText(message, BOARD_END + ((WINDOW_WIDTH - (BOARD_END) - text_size.x) / 2), 400, 30, BLACK);

    try_again_button.draw();
}
