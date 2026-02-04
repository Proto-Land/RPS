#include "titlescreen.hpp"
#include "game.hpp"
#include "menucontroller.hpp"
#include "filepath.hpp"
#include "control.hpp"

#include "engine.hpp"
#include "input_manager.hpp"
#include<raylib.h>

void TitleScreen::Init()
{
    xpos = 10;
    ypos = 30;
    fontSize = 100;
}

void TitleScreen::Update()
{
    if(Input::confirm())
    {
        Gctx.game.changeGameState(GameState::MENU);
        Cctx.Mcontrol.changeMenuState(MenuControl::STARTMENU);
    }

}

void TitleScreen::Draw()
{
    Font& globFont = engine.AM.getFont(Fonts::font98);
    DrawTextEx(globFont, "RPS", {(float)xpos, (float)ypos}, fontSize, 1, YELLOW);
}