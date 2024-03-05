#include "rectangleButton.h"

RectangleButton::RectangleButton(Vector2 pos, Vector2 size, Color color)
: pos(pos), size(size), color(color)
{

}

void RectangleButton::draw() const
{
    DrawRectangleV(pos, size, color);
    DrawRectangleLines(pos.x, pos.y, size.x, size.y, BLACK);
}

bool RectangleButton::isPressed() const
{
    Vector2 mouse_pos = GetMousePosition();
    bool collision = CheckCollisionPointRec(mouse_pos, Rectangle{ pos.x, pos.y, size.x, size.y });
    bool pressed = IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
    return collision && pressed;
}