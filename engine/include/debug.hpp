#pragma once
#include<raylib.h>
#include<sys/resource.h>
#include<unordered_set>
#include "mouseinput.hpp"

#include "state.hpp"
#include "menus.hpp"

inline constexpr bool DEV_MODE = true;

class debug
{
private:
    bool enabled = false;
    int memory = 0;
    int colorsUsed = 0;

    int printMemUsage();
    int countColors(const RenderTexture2D& canvas);

    State state;
    Vector2 cm;
    StartingMenu start;
    float ngX, ngY, ngW, ngH;

public:
    void Update();
    void Draw();
};