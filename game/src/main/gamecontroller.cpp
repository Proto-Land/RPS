#include "gamecontroller.hpp"
#include "levels.hpp"

void GameController::Init()
{
    switch(lvl)
    {
        case Levels::MAP: break;
        case Levels::LEVEL1: break;
        case Levels::LEVEL2: break;
    }
}

void GameController::Update()
{
    switch(lvl)
    {
        case Levels::MAP: break;
        case Levels::LEVEL1: break;
        case Levels::LEVEL2: break;
    }
}

void GameController::Draw()
{
    switch(lvl)
    {
        case Levels::MAP: break;
        case Levels::LEVEL1: break;
        case Levels::LEVEL2: break;
    }
}

void GameController::changeLevelState(Levels next)
{
    if(lvl == next) return;

    lvl = next;
    Init();
}
