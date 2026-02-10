#include "levels.hpp"

void Level1::Init()
{
    player.pctrl.Init();
}

void Level1::Update()
{
    player.pctrl.Update();
    if(player.pctrl.PlayerMove != Player::Moves::NONE)
    {
        ai.aictrl.AiMove();
        rps.calc(player.pctrl.PlayerMove);
    }
}

void Level1::Draw()
{
    player.pctrl.Draw();
    ai.aictrl.Draw();
    DrawText(TextFormat("wins = %d", player.pctrl.winstreak), 50, 350, 10, GREEN);
    DrawText(TextFormat("player choice = %d", (int)player.pctrl.PlayerMove), 50, 370, 10, GREEN);
    DrawText(TextFormat("ai choice = %d", (int)ai.aictrl.aiChoice), 50, 390, 10, GREEN);
}