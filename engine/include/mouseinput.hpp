#pragma once
#include<raylib.h>

namespace mouseIP{
    inline bool Rclick() { return IsMouseButtonPressed(MOUSE_BUTTON_LEFT); }
};

class Mpoint{
    public:
    bool MouseRec(Rectangle Rec);
    Vector2 CMouse;
    float scale = 1;
};
inline Mpoint mousepoint;