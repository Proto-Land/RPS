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

    void Init();
    void Update();
    void Draw();

    private:
    int spacing;
    Rectangle b;
    Rectangle rockButton, paperButton, scissorButton;
};