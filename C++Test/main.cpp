
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <string>
#include <iostream>
#include <cmath>
#include "Extras.h"
#include "Game.h"
#include "Object.h"
#include "Player.h"
#include "Mapbuilder.h"

using namespace std;



int main(int argc, char* argv[]) {

    Game game;
    Extras extra;
    MapBuilder mapBuilder;

    if (!game.initialize("name", 800, 600, 0))
    {
        return -1;

    }


    SDL_Renderer* ren = game.GetRenderer();

    SDL_Texture* Sprite = IMG_LoadTexture(ren, "Textures/Henry.png");   
    SDL_Texture* brick = IMG_LoadTexture(ren, "Textures/brick.png");

    

    float Speed = 1;
    /*for (int i = 0; i < 800; i += 50)
    {
        game.AddObject(new Object(game.GetRenderer(), i, 500, 50, 50, Sprite));   

    }*/
    mapBuilder.BuildMap(game, brick);

    game.AddObject(new Player(game.GetRenderer(), 300, 300, 64, 64, Sprite));
    
    while (game.IsRunning()) {
        
        game.HandleEvents();
        game.Updater();          
        
        game.Render();

    }
    game.Quit();
    return 0;
}

