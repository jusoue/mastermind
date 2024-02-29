#pragma once
#include "raylib.h"

class IButton
{
public:
    virtual ~IButton() = default;
    virtual void draw() const = 0;
    virtual bool isPressed() const = 0;
};