//engine
#include<raylib.h>
#include "input_manager.hpp"
#include "engine.hpp"

//game
#include "levels.hpp"
#include "filepath.hpp"
#include "gamecontroller.hpp"
#include "control.hpp"

void WorldMap::Init()
{
    w = 640;
    h = 400;
}

void WorldMap::Update()
{
    if(Input::confirm())
    {
        Cctx.Gcontrol.changeLevelState(Levels::LEVEL1);
    }
}

void WorldMap::Draw()
{
    Font& globFont = engine.AM.getFont(Fonts::font98);
    DrawRectangle(0,0, w, h, GREEN);   
    DrawTextEx(globFont, "Press SPACE to enter lvl1", {100, 600}, 30, 1, YELLOW); 
}