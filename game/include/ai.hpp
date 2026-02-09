#pragma once

class AI{
    public:
    enum Moves{
        ROCK,
        PAPER,
        SCISSOR,
        NONE
    };
    Moves aiChoice = Moves::NONE;

    void AiMove();
    void Draw();
    private:
    int choice;
};

struct a{
    AI aictrl;
};
extern a ai;