#include "rps.hpp"

void RPS::pmoveRock(AI::Moves aimove)
{
    switch(aimove)
    {
        case AI::ROCK: player.pctrl.Tie(); break;
        case AI::PAPER: player.pctrl.Lose(); break;
        case AI::SCISSOR: player.pctrl.Win(); break;
    }
    
}

void RPS::pmovePaper(AI::Moves aimove)
{
    switch(aimove)
    {
        case AI::ROCK: player.pctrl.Win(); break;
        case AI::PAPER: player.pctrl.Tie(); break;
        case AI::SCISSOR: player.pctrl.Lose(); break;
    }
}

void RPS::pmoveScissor(AI::Moves aimove)
{
    switch(aimove)
    {
        case AI::ROCK: player.pctrl.Lose(); break;
        case AI::PAPER: player.pctrl.Win(); break;
        case AI::SCISSOR: player.pctrl.Tie(); break;
    }
}

void RPS::calc(Player::Moves pmove)
{
    switch(pmove)
    {
        case Player::ROCK: pmoveRock(ai.aictrl.aiChoice); break;
        case Player::PAPER: pmovePaper(ai.aictrl.aiChoice); break;
        case Player::SCISSOR: pmoveScissor(ai.aictrl.aiChoice); break;
    }
}