#pragma once

#include "asset_manager.hpp"
#include "display_manager.hpp"

struct Engine{
    assetManager AM;
    displayManager DM;
};

extern Engine engine;