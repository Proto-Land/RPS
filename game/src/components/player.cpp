#include "player.hpp"
#include "engine.hpp"
#include "filepath.hpp"

p player;

void Player::Init()
{
    PlayerMove = Moves::NONE;
    winstreak = 0;
    resultScreen = 0;

    b = {180, 260, 80, 80};
    spacing = 10;

    rockButton = {b.x, b.y, b.width, b.height};
    paperButton = {b.x + b.width + spacing, b.y, b.width, b.height};
    scissorButton = {b.x + 2*(b.width + spacing), b.y, b.width, b.height};
}

void Player::Update()
{

}

void Player::Draw()
{
    Font& globFont = engine.AM.getFont(Fonts::font98);
    DrawRectangleRec(rockButton, RED);
    DrawRectangleRec(paperButton, RED);
    DrawRectangleRec(scissorButton, RED);

    DrawTextEx(globFont, "R", {rockButton.x + 5, rockButton.y + 5}, 80, 1, YELLOW);
    DrawTextEx(globFont, "P", {paperButton.x + 5, paperButton.y + 5}, 80, 1, YELLOW);
    DrawTextEx(globFont, "S", {scissorButton.x + 5, scissorButton.y + 5}, 80, 1, YELLOW);
}

void Player::Win()
{
    winstreak++;
    PlayerMove = Moves::NONE;
}

void Player::Lose()
{
    winstreak = 0;
    PlayerMove = Moves::NONE;
}

void Player::Tie()
{
    PlayerMove = Moves::NONE;
    return;
}