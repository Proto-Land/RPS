#include "ai.hpp"
#include<random>
#include<raylib.h>

a ai;

void AI::AiMove()
{
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(0,2);
    choice = dist(rng);

    Moves c = static_cast<Moves>(choice);

    switch(c)
    {
        case Moves::ROCK: aiChoice = Moves::ROCK; break;
        case Moves::PAPER: aiChoice = Moves::PAPER; break;
        case Moves::SCISSOR: aiChoice = Moves::SCISSOR; break;
    }
}

void AI::Draw()
{

    switch(aiChoice)
    {
        case Moves::ROCK:
                DrawRectangle(250, 100, 80, 80, RED);
                DrawText("R", 250, 100, 80, WHITE);
                break;
        
        case Moves::PAPER:
                DrawRectangle(250, 100, 80, 80, BLUE);
                DrawText("P", 250, 100, 80, WHITE);
                break;

        case Moves::SCISSOR:
                DrawRectangle(250, 100, 80, 80, YELLOW);
                DrawText("S", 250, 100, 80, WHITE);
                break;
    }
}