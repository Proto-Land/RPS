#pragma once
#include<raylib.h>
#include "display_manager.hpp"
#include "asset_manager.hpp"
#include "debug.hpp"

#include "titlescreen.hpp"
#include "state.hpp"
#include "menucontroller.hpp"
#include "gamecontroller.hpp"

class Game{
    public:
    Game();
    ~Game();
    bool Update();
    void Draw();
    void Init();
    void changeGameState(GameState next);

    State state;
    displayManager DM;
    MenuController Mcontrol;
    GameController GControl;

    private:
    TitleScreen TS;
};

struct GameContext{
    Game game;
};
extern GameContext Gctx;