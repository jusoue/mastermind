#include "rectangleButton.h"

RectangleButton::RectangleButton(Vector2 pos, Vector2 size, Color color)
{
    // TODO: Initialiser toutes les variables nécessaires



}

void RectangleButton::draw() const
{
    // TODO: Dessiner le rectangle du bouton et son coutour. 
    // Le bouton doit avoir la bonne couleur et le contour doit être noir
    
    

    float text_size = 20;
    Vector2 text_mesurments = MeasureTextEx(GetFontDefault(), label.c_str(), text_size, 0);
    Vector2 text_pos = {pos.x + (size.x - text_mesurments.x) / 2, pos.y + (size.y - text_mesurments.y) / 2};
    DrawText(label.c_str(), text_pos.x, text_pos.y, text_size, BLACK);
}

bool RectangleButton::isPressed() const
{
    Vector2 mouse_pos = GetMousePosition();
    bool collision = CheckCollisionPointRec(mouse_pos, Rectangle{ pos.x, pos.y, size.x, size.y });
    bool pressed = IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
    return collision && pressed;
}

void RectangleButton::setText(const std::string& text)
{
    label = text;
}