#pragma once

#include "state.hpp"
#include "menus.hpp"

class MenuController{
    public: 
    void Init();
    void Update();
    void Draw();
    void changeMenuState(MenuControl nextMenu);

    State state;

    private:
    StartingMenu startMenu;
    NewGameSelectMenu NGSMenu;
};