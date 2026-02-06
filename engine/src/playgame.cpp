#include "playgame.hpp"
#include "asset_manager.hpp"
#include "engine.hpp"
#include "mouseinput.hpp"

#include "game.hpp"
#include "state.hpp"

void Play::playgame()
{
    //Game game;
    debug dbg;
    //AssetLoader AL;

    //SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(engine.DM.getWWidth(), engine.DM.getWHeight(), "ツバサ");
    SetTargetFPS(60);

    engine.DM.initCanvas();
    
    Gctx.game.changeGameState(GameState::TITLE);

    while(!WindowShouldClose())
    {
        engine.DM.scaleWindow();

        if(!Gctx.game.Update()) break;
        if(DEV_MODE) dbg.Update();

        BeginTextureMode(engine.DM.getCanvas());
        ClearBackground(BLACK);
        Gctx.game.Draw();
        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);
        engine.DM.drawCanvasOnScreen();
        if(DEV_MODE) dbg.Draw();
        EndDrawing();
    }
    printf("before unload\n");
    engine.AM.unloadAssets();
    engine.DM.unloadCanvas();
    printf("after unload\n");
    CloseWindow();
    printf("after close\n");
}