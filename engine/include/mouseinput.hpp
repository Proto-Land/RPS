#pragma once
#include<raylib.h>

namespace mouseIP{
    inline bool Rclick() { return IsMouseButtonPressed(MOUSE_BUTTON_LEFT); }
    inline bool MouseRec(Rectangle Rec) { return CheckCollisionPointRec(GetMousePosition(), Rec); }
};