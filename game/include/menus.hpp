#pragma once
#include<raylib.h>
#include "state.hpp"

class StartingMenu{
    public:
    void Init();
    void Update();
    void Draw();

    State state;

    private:
    int xpos, ypos, ybase, spacing, selectionWidth;
    int selected;
    int optionCount;

    Rectangle newGameButton, continueButton, optionsButton, quitButton;
};

class NewGameSelectMenu{
    public:
    void Init();
    void Update();
    void Draw();

    private:
    bool boolselected;
    int xpos, ypos, selectionWidth;
};

class ContinueMenu{
    public:
    void Init();
    void Update();
    void Draw();

    private:
};

class OptionsMenu{
    public:
    void Init();
    void Update();
    void Draw();

    private:
};

class PausingMenu{
    public:
    void Init();
    void Update();
    void Draw();

    private:
};