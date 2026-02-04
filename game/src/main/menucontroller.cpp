//engine
#include "input_manager.hpp"

//game
#include "menucontroller.hpp"

//MENU CONTROLLER
void MenuController::Init()
{
    //MC = MenuControl::STARTMENU;
    switch(state.MC)
    {
        case MenuControl::STARTMENU: startMenu.Init(); break;
        case MenuControl::NEWGAMEMENU: NGSMenu.Init(); break;
        case MenuControl::OPTIONMENU: break;
        case MenuControl::PAUSEMENU: break;
    }
}

void MenuController::Update()
{
    switch(state.MC)
    {
        case MenuControl::STARTMENU: startMenu.Update(); break;
        case MenuControl::NEWGAMEMENU: NGSMenu.Update(); break;
        case MenuControl::OPTIONMENU: break;
        case MenuControl::PAUSEMENU: break;
    }

}

void MenuController::Draw()
{
    switch(state.MC)
    {
        case MenuControl::STARTMENU: startMenu.Draw(); break;
        case MenuControl::NEWGAMEMENU: NGSMenu.Draw(); break;
        case MenuControl::OPTIONMENU: break;
        case MenuControl::PAUSEMENU: break;
    }
}

void MenuController::changeMenuState(MenuControl nextMenu)
{
    if(state.MC == nextMenu) return;

    state.MC = nextMenu;
    Init();
}
