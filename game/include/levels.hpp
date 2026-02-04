#pragma once
#include<raylib.h>
#include<vector>

enum class Levels{
    NONE,
    MAP,
    LEVEL1,
    LEVEL2
};
inline Levels lvl = Levels::NONE;

class WorldMap{
    public:
    void Init();
    void Update();
    void Draw();

    private:
    int w,h;
};


//LEVELS
