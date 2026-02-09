#pragma once

#include "player.hpp"
#include "rps.hpp"

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
class Level1{
    public:
    void Init();
    void Update();
    void Draw();

    private:
    RPS rps;
};

struct lvlCtrl{
    WorldMap WMap;
    Level1 lvl1;
};
extern lvlCtrl level;