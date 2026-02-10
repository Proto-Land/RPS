#include "player.hpp"
#include "engine.hpp"
#include "filepath.hpp"
#include "mouseinput.hpp"

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
    if(!resultScreen)
    {
        if(mouseIP::Rclick())
        {
            if(mousepoint.MouseRec(rockButton)) player.pctrl.PlayerMove = Moves::ROCK;
            else if(mousepoint.MouseRec(paperButton)) player.pctrl.PlayerMove = Moves::PAPER;
            else if(mousepoint.MouseRec(scissorButton)) player.pctrl.PlayerMove = Moves::SCISSOR;
        }
    }
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

    if(mousepoint.MouseRec(rockButton)) DrawRectangleLines(rockButton.x, rockButton.y, rockButton.width, rockButton.height, YELLOW);
    else if(mousepoint.MouseRec(paperButton)) DrawRectangleLines(paperButton.x, paperButton.y, paperButton.width, paperButton.height, YELLOW);
    else if(mousepoint.MouseRec(scissorButton)) DrawRectangleLines(scissorButton.x, scissorButton.y, scissorButton.width, scissorButton.height, YELLOW);
}

void Player::Win()
{
    resultScreen = true;
    winstreak++;
    PlayerMove = Moves::NONE;
    resultScreen = false;
}

void Player::Lose()
{
    resultScreen = true;
    winstreak = 0;
    PlayerMove = Moves::NONE;
    resultScreen = false;
}

void Player::Tie()
{
    resultScreen = true;
    PlayerMove = Moves::NONE;
    resultScreen = false;
    return;
}