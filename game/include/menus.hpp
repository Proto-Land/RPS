#pragma once
#include<raylib.h>
#include "state.hpp"

class StartingMenu{
    public:
    void Init();
    void Update();
    void Draw();

    Rectangle newGameButton, continueButton, optionsButton, quitButton;
    
    State state;

    private:
    int xpos, ypos, ybase, spacing, selectionWidth;
};

class NewGameSelectMenu{
    public:
    void Init();
    void Update();
    void Draw();

    Rectangle yesButton, noButton;

    private:
    bool boolselected;
    float ypos;
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