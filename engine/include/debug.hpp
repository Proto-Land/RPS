#pragma once
#include<raylib.h>
#include<sys/resource.h>
#include<unordered_set>

inline constexpr bool DEV_MODE = true;

class debug
{
private:
    bool enabled = false;
    int memory = 0;
    int colorsUsed = 0;

    int printMemUsage();
    int countColors(const RenderTexture2D& canvas);

public:
    void Update();
    void Draw();
};