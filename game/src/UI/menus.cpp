//engine
#include "input_manager.hpp"
#include "mouseinput.hpp"
#include "engine.hpp"
#include<raylib.h>

//game
#include "menus.hpp"
#include "state.hpp"
#include "menucontroller.hpp"
#include "game.hpp"
#include "levels.hpp"
#include "gamecontroller.hpp"
#include "filepath.hpp"
#include "control.hpp"

//-------------------------------------------------------------------------------
//  START MENU
void StartingMenu::Init()
{
    xpos = 50;

    //ypos = ybase + selected * spacing
    newGameButton = {(float)(xpos - 5), 140, 190, 50};
    continueButton = {(float)(xpos - 5), 200, 220, 50};
    optionsButton = {(float)(xpos - 5), 260, 190, 50};
    quitButton = {(float)(xpos - 5), 320, 110, 50};
    printf("init ng: x:%.2f y:%.2f w:%.2f h:%.2f\n", newGameButton.x, newGameButton.y, newGameButton.width, newGameButton.height);
}

void StartingMenu::Update()
{
    if(mouseIP::Rclick())
    {
        if(mousepoint.MouseRec(newGameButton)) state.SM = StartMenu::NEWGAME;
        else if(mousepoint.MouseRec(continueButton)) state.SM = StartMenu::CONTINUE;
        else if(mousepoint.MouseRec(optionsButton)) state.SM = StartMenu::OPTIONS;
        else if(mousepoint.MouseRec(quitButton)) state.SM = StartMenu::QUIT;
    }

    switch(state.SM)
    {
        case StartMenu::NEWGAME: Cctx.Mcontrol.changeMenuState(MenuControl::NEWGAMEMENU); break;
        case StartMenu::CONTINUE: break;
        case StartMenu::OPTIONS: break;
        case StartMenu::QUIT: Gctx.game.changeGameState(GameState::QUIT); break;
    }
}


void StartingMenu::Draw()
{
    Font& globFont = engine.AM.getFont(Fonts::font98);

    if(mousepoint.MouseRec(newGameButton)) DrawRectangleLinesEx(newGameButton, 2, BLUE);
    else if(mousepoint.MouseRec(continueButton)) DrawRectangleLinesEx(continueButton, 2, BLUE);
    else if(mousepoint.MouseRec(optionsButton)) DrawRectangleLinesEx(optionsButton, 2, BLUE);
    else if(mousepoint.MouseRec(quitButton)) DrawRectangleLinesEx(quitButton, 2, BLUE);

    //Rectangle SelRec = {(float)(xpos - 5), (float)ypos, (float)selectionWidth, 50};
    //DrawRectangleLinesEx(SelRec, 2, BLUE);

    DrawTextEx(globFont, "NEWGAME", {(float)xpos, 140}, 50, 1, YELLOW);
    DrawTextEx(globFont, "CONTINUE", {(float)xpos, 200}, 50, 1, YELLOW);
    DrawTextEx(globFont, "OPTIONS", {(float)xpos, 260}, 50, 1, YELLOW);
    DrawTextEx(globFont, "QUIT", {(float)xpos, 320}, 50, 1, YELLOW);

    DrawRectangleLinesEx(newGameButton, 1, RED);
    DrawRectangleLinesEx(continueButton, 1, RED);
    DrawRectangleLinesEx(optionsButton, 1, RED);
    DrawRectangleLinesEx(quitButton, 1, RED);
}

//-------------------------------------------------------------------------------
//  NEW GAME MENU
void NewGameSelectMenu::Init()
{
    boolselected = 0;
    ypos = 300;

    yesButton = {250, ypos, 80, 40};
    noButton = {400, ypos, 60, 40};
}

void NewGameSelectMenu::Update()
{
    if(mouseIP::Rclick())
    {
        if(mousepoint.MouseRec(yesButton))
        {
            Gctx.game.changeGameState(GameState::GAME);
            Cctx.Gcontrol.changeLevelState(Levels::MAP);
        }
        else if(mousepoint.MouseRec(noButton)) Cctx.Mcontrol.changeMenuState(MenuControl::STARTMENU);
    }
    
}

void NewGameSelectMenu::Draw()
{

    Font& globFont = engine.AM.getFont(Fonts::font98);
    DrawRectangle(40,40,560,400, DARKGRAY);
    DrawRectangleLines(40,40,560,400, DARKBLUE);

    if(mousepoint.MouseRec(yesButton))
    {
        DrawRectangleRec(yesButton, DARKBLUE);
        boolselected = 0;
    }
    else if(mousepoint.MouseRec(noButton))
    {
        DrawRectangleRec(noButton, DARKBLUE);
        boolselected = 1;
    }
    DrawTextEx(globFont, "Start New Game?", {100,40}, 60, 1, WHITE);
    DrawTextEx(globFont, "YES", {yesButton.x,yesButton.y}, 40, 1, (Color)((boolselected ==0) ? WHITE : BLACK));
    DrawTextEx(globFont, "NO", {noButton.x ,noButton.y}, 40, 1, (Color)((boolselected ==1) ? WHITE : BLACK));

}

//-------------------------------------------------------------------------------
//  CONTINUE MENU
void ContinueMenu::Init()
{

}

void ContinueMenu::Update()
{

}

void ContinueMenu::Draw()
{

}

//-------------------------------------------------------------------------------
//  PAUSE MENU
void PausingMenu::Init()
{

}

void PausingMenu::Update()
{

}

void PausingMenu::Draw()
{

}

//-------------------------------------------------------------------------------
// OPTIONS MENU
void OptionsMenu::Init()
{

}

void OptionsMenu::Update()
{

}

void OptionsMenu::Draw()
{

}