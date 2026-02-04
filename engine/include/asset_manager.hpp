#pragma once
#include<raylib.h>
#include<string>
#include<map>

class assetManager{
private: 
    std::map<std::string, Texture2D> textures;
    std::map<std::string, Font> fonts;
    bool unloaded = false;

public: 
    Texture2D& getTexture(const std::string& path);    
    Font& getFont(const std::string& path);
    void unloadAssets();
    ~assetManager();
};