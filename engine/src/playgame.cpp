#include "playgame.hpp"
#include "display_manager.hpp"
#include "asset_manager.hpp"
#include "engine.hpp"

#include "game.hpp"
#include "state.hpp"

void Play::playgame()
{
    displayManager DM;
    //Game game;
    debug dbg;
    //AssetLoader AL;

    //SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(DM.getWWidth(), DM.getWHeight(), "ツバサ");
    SetTargetFPS(60);

    DM.initCanvas();
    
    Gctx.game.changeGameState(GameState::TITLE);

    while(!WindowShouldClose())
    {
        DM.scaleWindow();
        if(!Gctx.game.Update()) break;
        if(DEV_MODE) dbg.Update();

        BeginTextureMode(DM.getCanvas());
        ClearBackground(BLACK);
        Gctx.game.Draw();
        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);
        DM.drawCanvasOnScreen();
        if(DEV_MODE) dbg.Draw();
        EndDrawing();
    }
    printf("before unload\n");
    engine.AM.unloadAssets();
    DM.unloadCanvas();
    printf("after unload\n");
    CloseWindow();
    printf("after close\n");
}