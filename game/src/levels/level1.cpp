#include "levels.hpp"

void Level1::Init()
{
    player.pctrl.Init();
}

void Level1::Update()
{
    player.pctrl.Update();
    rps.calc(player.pctrl.PlayerMove);
    
}

void Level1::Draw()
{
    player.pctrl.Draw();
    ai.aictrl.Draw();
    DrawText(TextFormat("wins = %d", player.pctrl.winstreak), 100, 300, 30, GREEN);
}