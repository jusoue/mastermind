#include "colorButton.h"

ColorButton::ColorButton(Vector2 center, float radius, PieceColor piece_color)
{
    // TODO: Initialiser toutes les variables nécessaires



}

void ColorButton::draw() const
{
    // TODO: Dessiner le cercle et le contour du cercle au bon endroit. Indice: la fonction toColor() permet de passer
    //       d'un objet PieceColor à un objet Color. Le contour du cercle doit être noir
    
    
}

bool ColorButton::isPressed() const
{
    Vector2 mouse_pos = GetMousePosition();
    bool collision = CheckCollisionPointCircle(mouse_pos, center, radius);
    bool pressed = IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
    return collision && pressed;
}

PieceColor ColorButton::getColor() const
{
    return piece_color;
}