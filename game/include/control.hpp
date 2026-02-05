#pragma once

#include "gamecontroller.hpp"
#include "menucontroller.hpp"

struct Control{
    GameController Gcontrol;
    MenuController Mcontrol;
};

extern Control Cctx;