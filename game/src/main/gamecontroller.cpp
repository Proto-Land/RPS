#include "gamecontroller.hpp"
#include "levels.hpp"

void GameController::Init()
{
    switch(lvl)
    {
        case Levels::MAP: level.WMap.Init(); break;
        case Levels::LEVEL1: level.lvl1.Init(); break;
        case Levels::LEVEL2: break;
    }
}

void GameController::Update()
{
    switch(lvl)
    {
        case Levels::MAP: level.WMap.Update(); break;
        case Levels::LEVEL1: level.lvl1.Update(); break;
        case Levels::LEVEL2: break;
    }
}

void GameController::Draw()
{
    switch(lvl)
    {
        case Levels::MAP: level.WMap.Draw(); break;
        case Levels::LEVEL1: level.lvl1.Draw(); break;
        case Levels::LEVEL2: break;
    }
}

void GameController::changeLevelState(Levels next)
{
    if(lvl == next) return;

    lvl = next;
    Init();
}
