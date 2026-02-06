#include "debug.hpp"
#include "asset_manager.hpp"
#include "engine.hpp"
#include "mouseinput.hpp"

#include "menus.hpp"

int debug::printMemUsage()
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss/1024;
}

int debug::countColors(const RenderTexture2D& canvas)
{
    Image img = LoadImageFromTexture(canvas.texture);

    std::unordered_set<unsigned int> uniqueColors;

    for(int y = 0; y < img.height; y+=4)
    for(int x = 0; x < img.width; x+=4)
    {
        Color c = GetImageColor(img, x, y);

        unsigned int key = (c.r << 24) | (c.g << 16) | (c.b << 8) | c.a;
        uniqueColors.insert(key);
    }
    UnloadImage(img);

    return (int)uniqueColors.size();
}

void debug::Update()
{
    if(!DEV_MODE) return;

    memory = printMemUsage();
    /*
    static int frameCount = 0;
    frameCount++;
    if(frameCount % 120 == 0)
    {
        colorsUsed = countColors(DM.getCanvas());
    }
    */
    cm = mousepoint.CMouse;
    ngX = start.newGameButton.x;
    ngY = start.newGameButton.y;
    ngW = start.newGameButton.width;
    ngH = start.newGameButton.height;

    if(IsKeyPressed(KEY_TAB)) enabled = !enabled;
}

void debug::Draw()
{
    if(!DEV_MODE || !enabled) return;

    int FS = 20;
    int xpos = 10;


    DrawText(TextFormat("FPS: %d", GetFPS()), xpos,10, FS, WHITE);
    DrawText(TextFormat("Gamepad: %s", GetGamepadName(0)), xpos,30, FS, WHITE);
    DrawText(TextFormat("memory: %d mb", memory), xpos, 50, FS, WHITE);
    DrawText(TextFormat("frame time: %.2f ms", GetFrameTime() * 1000.0f), xpos,70, FS, WHITE);
    DrawText(TextFormat("%d", (int)GetTime()), xpos, 90, FS, WHITE);
    DrawText(TextFormat("Colors = %d", colorsUsed), xpos, 110, FS, WHITE);
    DrawText(TextFormat("state = %d",(int)(state.GS)), xpos, 130, FS, WHITE);

    //menu button UI debug
    
    DrawText(TextFormat("CMouse: x:%.2f y:%.2f", cm.x, cm.y), xpos, 150, FS, WHITE);
    DrawText(TextFormat("newgame button: x:%.2f y:%.2f w:%.2f h%.2f",ngX, ngY, ngW, ngH), xpos, 170, FS, WHITE);

}