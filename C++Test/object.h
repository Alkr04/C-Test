#pragma once
#include <SDL3/SDL.h>

class Object 
{
public:
	Object(SDL_Renderer*, float, float, float, float);
	Object(SDL_Renderer*, float, float, float, float, SDL_Texture*);
	~Object();

	virtual void HandleEvent(const SDL_Event& e);
	virtual void Render();
	virtual void Update(float, float);
	virtual void SetPosition(int, int);

	bool intersection(const SDL_FRect& other)const;
	bool intersectionY(const SDL_FRect& other)const;
	bool intersectionX(const SDL_FRect& other)const;

protected:
	SDL_Renderer* renderer = nullptr;
	SDL_FRect rect;
	SDL_Texture* texture = nullptr;


};
