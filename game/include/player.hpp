#pragma once
#include<raylib.h>

class Player{
    public:
    enum Moves{
        ROCK,
        PAPER,
        SCISSOR,
        NONE
    };
    Moves PlayerMove;
    void Init();
    void Update();
    void Draw();
    void Win();
    void Lose();
    void Tie();

    int winstreak;
    bool resultScreen;

    private:
    int spacing;
    Rectangle b;
    Rectangle rockButton, paperButton, scissorButton;
};

struct p{
    Player pctrl;
};
extern p player;