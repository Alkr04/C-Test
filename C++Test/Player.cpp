#include "player.h"
#include "Extras.h"
#include "Game.h"
#include <iostream>


float moveX = 0;
float moveY = 0;

float speed = 1;

Extras extra;
Game game;



Player::Player(SDL_Renderer* renderer, float x, float y, float w, float h, SDL_Texture* texture) : Object(renderer, x, y, w, h, texture)
{
	rect = { x, y, w, h };
}
Player::~Player() 
{

}

void Player::Update(float DeltaTime, float ScaledDeltaTime)
{

	moveX = 0;
	moveY = 0;



	const bool* keys = SDL_GetKeyboardState(NULL);
            moveY = 1;
        if (keys[SDL_SCANCODE_W])
        {
            moveY = -1;
        }
        else if (keys[SDL_SCANCODE_S])
        {
        }
        if (keys[SDL_SCANCODE_D])
        {
            moveX = 1;
        }
        else if (keys[SDL_SCANCODE_A])
        {
            moveX = -1;
        }

        float magnetude = extra.Normalize(moveX, moveY);

        if (magnetude != 0)
        {
            rect.x += (moveX / magnetude) * speed;
            rect.y += (moveY / magnetude) * speed;
            for (Object* obj : game.GetObjects())
            {
                if (obj != this) 
                {
                    if (obj->intersection(rect) && obj->intersectionX(rect))
                    {
                        rect.y -= (moveY / magnetude) * speed;
                    }
                    if (obj->intersection(rect))
                    {
                        rect.x -= (moveX / magnetude) * speed;

                    }
                }

            }
        }

}
/*void Player::HandleEvent(const SDL_Event& e)
{

}*/