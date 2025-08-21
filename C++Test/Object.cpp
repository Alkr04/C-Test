#include "object.h"
#include <iostream>

Object::Object(SDL_Renderer* renderer, float x, float y, float w, float h) : renderer(renderer) 
{
	rect = { x,y,w,h };
	texture = nullptr;
}
Object::Object(SDL_Renderer* renderer, float x, float y, float w, float h, SDL_Texture* texture) : renderer(renderer), texture(texture)
{
	rect = { x, y, w, h };
}
Object::~Object() {}

void Object::HandleEvent(const SDL_Event& e) 
{

}

void Object::Render() 
{
	if (texture) 
	{
		SDL_RenderTexture(renderer, texture, NULL, &rect);
	}
	else 
	{
		SDL_RenderFillRect(renderer, &rect);
	}
}

void Object::Update(float DeltaTime, float ScaledDeltaTime) 
{

}

void Object::SetPosition(int x, int y) 
{
	rect.x = (float)x;
	rect.y = (float)y;
}

bool Object::intersection(const SDL_FRect& other) const
{
	bool noOverlap =
		rect.x + rect.w <= other.x ||
		other.x + other.w <= rect.x||
		rect.y + rect.h <= other.y ||
		other.y + other.h <= rect.y;

	if (rect.y + rect.h - 1 < other.y && other.y < rect.y + rect.h + 1)
	{
		std::cout << other.y << " " << rect.y + rect.h << " ";
		return false;
	}
	return !noOverlap;
}

bool Object::intersectionY(const SDL_FRect & other) const 
{
	bool noOverlapX =
		rect.x + rect.w <= other.x+1 ||
		other.x + other.w <= rect.x+1;
	bool noOverlapY =
		rect.y + rect.h <= other.y ||
		other.y + other.h <= rect.y;
	if (!noOverlapY && noOverlapX) 
	{
		//std::cout << "noOverlap ";
		return false;
	}
	return true;
}
bool Object::intersectionX(const SDL_FRect& other) const
{
	bool noOverlapX =
		rect.x + rect.w <= other.x ||
		other.x + other.w <= rect.x;
	bool noOverlapY =
		rect.y + rect.h <= other.y+2 ||
		other.y + other.h <= rect.y+2;
	if (noOverlapY && !noOverlapX)
	{
		//std::cout << "noOverlap ";
		return false;
	}
	return true;
}
