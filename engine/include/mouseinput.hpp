#pragma once
#include<raylib.h>

namespace mouseIP{
    inline bool Rclick() { return IsMouseButtonPressed(0); }
}
class MInput{
    public:
    bool MouseRec(Rectangle Rec);
    Vector2 mouse;
};