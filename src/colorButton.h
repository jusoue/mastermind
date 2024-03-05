#pragma once
#include "button.h"
#include "constants.h"

class ColorButton : public IButton
{
public:
    ColorButton(Vector2 center, float radius, PieceColor piece_color);
    ~ColorButton() override = default;

    void draw() const override;
    bool isPressed() const override;
    PieceColor getColor() const;

private:
    Vector2 center = {0, 0};
    float radius = 0.0f;
    PieceColor piece_color;
};