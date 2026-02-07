#include "player.hpp"
#include "engine.hpp"
#include "filepath.hpp"

void Player::Init()
{
    Moves::NONE;

    b = {180, 260, 80, 80};
    spacing{10};

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

    DrawTextEx(globFont, "R", {rockButton.x, rockButton.y}, 20, 1, YELLOW);
    DrawTextEx(globFont, "P", {paperButton.x, paperButton.y}, 20, 1, YELLOW);
    DRawTextEx(globFont, "S", {scissorButton.x, scissorButton.y}, 20, 1, YELLOW);
}