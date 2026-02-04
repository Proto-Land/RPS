#pragma once
#include "state.hpp"
#include "levels.hpp"

class GameController{
    public:
    void Init();
    void Update();
    void Draw();
    void changeLevelState(Levels next);

    private:
};