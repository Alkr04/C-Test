#include <SDL3/SDL.h>
#include <iostream>
#include "Game.h"
#include <string>
#include "object.h"
#include <list>
#include <vector>

//Game::Game(){}
//Game::~Game(){}

    struct FrameData
    {
        int frameCount = 0;
        const Uint32 frameDelay = 1000 / 60;
        Uint32 frameStart = 0;
        Uint32 frameTime = 0;
        Uint64 lastTime = 0;
        float timeScale = 1.f;
        float deltaTime = 0;
        float scaledDeltaTime = 0;
    };

    SDL_Window* window;
    SDL_Renderer* ren;

    bool running = true;
    FrameData fData;

    //std::initializer_list<Object> object = new std::initializer_list<Object>;
    //std::list<Object*> object;
    static std::vector<Object*> object;


	bool Game::initialize(std::string name, int w, int h, int flag)
	{
        //Init SDL core
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            std::cerr << "SDL Init Failed: " << SDL_GetError() << '\n';
            running = false;
            return false;
        }

        //Cool window
        window = SDL_CreateWindow(name.c_str(), w, h, flag);
        //lovely error handling
        if (!window) {

            std::cerr << "Window Creation Failed: " << SDL_GetError() << '\n';
            SDL_Quit();
            running = false;
            return false;
        }

        ren = SDL_CreateRenderer(window, NULL);
	}

    bool Game::IsRunning() 
    {
        return running;
    }


    void Game::AddObject(Object* obj) 
    {
        object.push_back(obj);
    }


    void Game::HandleEvents() 
    {

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                if (event.key.key == SDLK_ESCAPE)
                    running = false;
                break;
            default:
                break;
            }
        }
        SDL_PumpEvents();
    }

    void Game::Updater() 
    {
        Uint64 now = SDL_GetTicks();
        fData.deltaTime = (now - fData.lastTime) / 1000.0f;
        fData.lastTime = now;

        fData.scaledDeltaTime = fData.deltaTime * fData.timeScale;

        for (Object* go : object)
        {
            go->Update(fData.deltaTime, fData.scaledDeltaTime);
        }

        fData.frameStart = SDL_GetTicks();
        fData.frameCount++;

        fData.frameTime = SDL_GetTicks() - fData.frameStart;

        if (fData.frameTime < fData.frameDelay)
        {
            SDL_Delay(fData.frameDelay - fData.frameTime);
        }
    }

    void Game::Render() 
    {
        SDL_RenderClear(ren);

        SDL_SetRenderDrawColor(ren, 50, 150, 50, 255);

        for (Object* obj : object) 
        {
            obj->Render();
        }

        SDL_RenderPresent(ren);
    }

    SDL_Renderer* Game::GetRenderer() 
    {
        return ren;
    }

    std::vector<Object*> Game::GetObjects() 
    {
        return object;
    }

    void Game::Quit() 
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
