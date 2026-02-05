#pragma once

//game controller
enum class GameState{
    TITLE,
    MENU,
    GAME,
    PAUSE,
    QUIT,
    NONE
};

//Menus
enum class MenuControl{
    NONE,
    STARTMENU,
    NEWGAMEMENU,
    OPTIONMENU,
    PAUSEMENU
};

enum class StartMenu{
    NEWGAME,
    CONTINUE,
    OPTIONS,
    QUIT,
    NONE
};

enum class NewGameMenu{
    YES,
    NO
};

enum class OptionMenu{
    //settings options or flags
};

enum class PauseMenu{
    CONTINUE,
    OPTIONS,
    QUIT
};

// game components
enum class PlayerState{
    IDLE,
    DEATH
};

struct State{
    GameState GS = GameState::NONE;
    MenuControl MC = MenuControl::NONE;
    StartMenu SM = StartMenu::NONE;
    NewGameMenu NGMenu;
    OptionMenu OpMenu;
    PauseMenu PMenu;
};
