#pragma once
#include "button.h"
#include <string>

class RectangleButton : public IButton
{
public:
    RectangleButton(Vector2 pos, Vector2 size, Color color);
    RectangleButton() = default;
    ~RectangleButton() override = default;

    void draw() const override;
    bool isPressed() const override;
    void setText(const std::string& text);

private:
    Vector2 pos = {0, 0};
    Vector2 size = {0, 0};
    Color color;
    std::string label = "";
};