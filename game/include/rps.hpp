#pragma once

#include "player.hpp"
#include "ai.hpp"

class RPS{
    public:
    void calc(Player::Moves pmove);

    void pmoveRock(AI::Moves aimove);
    void pmovePaper(AI::Moves aimove);
    void pmoveScissor(AI::Moves aimove);
};