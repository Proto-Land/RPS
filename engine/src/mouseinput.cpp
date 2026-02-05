#include "mouseinput.hpp"

bool MInput::MouseRec(Rectangle Rec)
{
    mouse = GetMousePosition();
    return CheckCollisionPointRec(mouse, Rec);
}