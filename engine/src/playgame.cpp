#include "playgame.hpp"
#include "display_manager.hpp"

#include "game.hpp"
#include "assetloader.hpp"
#include "state.hpp"

void Play::playgame()
{
    //displayManager DM;
    //Game game;
    debug dbg;
    //AssetLoader AL;

    //SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(DM.getWWidth(), DM.getWHeight(), "ツバサ");
    SetTargetFPS(60);

    DM.initCanvas();
    AL.InitFont();
    AL.InitTexture();
    
    game.changeGameState(GameState::TITLE);

    while(!WindowShouldClose())
    {
        DM.scaleWindow();
        if(!game.Update()) break;
        if(DEV_MODE) dbg.Update();

        BeginTextureMode(DM.getCanvas());
        ClearBackground(BLACK);
        game.Draw();
        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);
        DM.drawCanvasOnScreen();
        if(DEV_MODE) dbg.Draw();
        EndDrawing();
    }
    AM.unloadAssets();
    CloseWindow();
}