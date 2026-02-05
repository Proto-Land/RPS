#pragma once

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
};