#pragma once
#include "object.h"
#include <SDL3/SDL.h>

class Player : public Object 
{
	
public:
	Player(SDL_Renderer* renderer, float x, float y, float w, float h, SDL_Texture* texture);
	~Player();


	virtual void Update(float DeltaTime, float ScaledDeltaTime) override;
	//virtual void HandleEvent(const SDL_Event& e) override;
};
