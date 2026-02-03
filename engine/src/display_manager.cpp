#include "display_manager.hpp"
#include<cmath>

void displayManager::scaleWindow()
{
    scale = fminf((float)GetScreenWidth()/canvasWidth, (float)GetScreenHeight()/canvasHeight);
    fit = {canvasWidth*scale, canvasHeight*scale};
    offsetX = (GetScreenWidth() - (int)fit.x)/2;
    offsetY = (GetScreenHeight() - (int)fit.y)/2;
};

void displayManager::drawCanvasOnScreen() const {
    //displayManager::srcRec = {0,0,getCanvasWidth(), -getCanvasHeight()};
    Rectangle srcRec = {0,0,(float)getCanvasWidth(), -(float)getCanvasHeight()};
    Rectangle desRec = {(float)getOffsetX(), (float)getOffsetY(), (float)getFit().x, (float)getFit().y};
    DrawRectangle(offsetX, offsetY, fit.x, fit.y, {26,26,26,255});

    //BeginShaderMode(shader.getShader98());
    //shader.BindPalette();
    DrawTexturePro(canvas.texture, srcRec, desRec, {0,0}, 0, WHITE);
    //EndShaderMode();
}

void displayManager::initCanvas()
{
    canvas = LoadRenderTexture(canvasWidth, canvasHeight);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT);
    //shader.InitShader();
}

displayManager::displayManager()
{
}

displayManager::~displayManager()
{
    UnloadRenderTexture(canvas);
}