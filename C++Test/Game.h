#pragma once
#include <SDL3/SDL.h>
#include <string>
#include "object.h"
#include <vector>


class Game 
{
public:
	bool initialize(std::string name, int w, int h ,int flag);
	bool IsRunning();

	void AddObject(Object*);
	void HandleEvents();
	void Updater();
	void Render();
	SDL_Renderer* GetRenderer();
	std::vector<Object*> GetObjects();

	void Quit();
};