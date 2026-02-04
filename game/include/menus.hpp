#pragma once

class StartingMenu{
    public:
    void Init();
    void Update();
    void Draw();

    private:
    int xpos, ypos, ybase, spacing, selectionWidth;
    int selected;
    int optionCount;
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