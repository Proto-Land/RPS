#include "game.hpp"
#include "gamecontroller.hpp"
#include "control.hpp"

GameContext Gctx;

Game::Game()
{

}

void Game::Init()
{
    switch(state.GS)
    {
        //INIT FUNCTIONS ONLY
        case GameState::TITLE: TS.Init(); break;
        case GameState::MENU: Cctx.Mcontrol.Init(); break;
        case GameState::GAME: Cctx.Gcontrol.Init(); break;
        case GameState::PAUSE: break;
        case GameState::QUIT: break;
    }

}

bool Game::Update()
{
    switch(state.GS)
    {
        //only use update functions
        case GameState::TITLE: TS.Update(); break;
        case GameState::MENU: Cctx.Mcontrol.Update(); break;
        case GameState::GAME: Cctx.Gcontrol.Update(); break;
        case GameState::PAUSE: break;
        case GameState::QUIT: return false;
    }
    return true;
}

void Game::Draw()
{
    DrawRectangle(0,0, DM.getCanvasWidth(), DM.getCanvasHeight(), DARKGRAY);
    switch(state.GS)
    {
        //draw functions
        case GameState::TITLE: TS.Draw(); break;
        case GameState::MENU: Cctx.Mcontrol.Draw(); break;
        case GameState::GAME: Cctx.Gcontrol.Draw(); break;
        case GameState::PAUSE: break;
    }
}

void Game::changeGameState(GameState next)
{
    if(state.GS == next) return;
    
    state.GS = next;
    Init();
}

Game::~Game()
{
    
}