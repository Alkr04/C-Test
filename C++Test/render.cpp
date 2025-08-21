
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
    SDL_Window* win = SDL_CreateWindow("SDL3 Demo", 800, 600, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);

    SDL_Gamepad* gamepad = SDL_OpenGamepad(0);

    //background color
    SDL_SetRenderDrawColor(ren, 50, 150, 50, 255);

    //cool sprite
    SDL_Texture* sprite = IMG_LoadTexture(ren, "player.bmp");
    float xPos = 100, yPos = 100;
    int xMove = 0, yMove = 0;
    float moveScale = .01f;

    //tranparency
    //SDL_Surface* surf = IMG_Load("player.bmp");
    ////yeet all color
    //SDL_SetSurfaceColorKey(surf, true, SDL_MapSurfaceRGB(surf, 255, 255, 255)) == false;
    ////new texture from modified surface
    //SDL_Texture* keyed = SDL_CreateTextureFromSurface(ren, surf);
    ////overwrite sprite
    //sprite = SDL_CreateTextureFromSurface(ren, surf);
    ////free memory
    //SDL_DestroySurface(surf);

    //funny spin
    //double angle = 0;

    bool running = true;
    SDL_Event ev;

    while (running) {

        //Event handling
        while (SDL_PollEvent(&ev)) {
            if (ev.key.key == SDLK_ESCAPE) {
                running = false;
            }
            //if (ev.type == SDL_EVENT_GAMEPAD_AXIS_MOTION) {
            //    
            //    if (ev.gaxis.axis == SDL_GAMEPAD_AXIS_LEFTX) {
            //        //do something :^)
            //    }
            //}

            ////mouse events example
            //if (ev.type = SDL_EVENT_MOUSE_BUTTON_DOWN) {
            //    bool left = ev.button.down == SDL_BUTTON_LEFT;
            //    bool right = ev.button.down == SDL_BUTTON_RIGHT;
            //    //dosomething(left, right);
            //}
            //if (ev.type = SDL_EVENT_MOUSE_MOTION) {
            //    float x = ev.motion.x;
            //}

        }

        //mouse
        //float* x = 0; 
        //float* y = 0;
        //SDL_MouseButtonFlags mbFlags = 0;
        //mbFlags = SDL_GetMouseState(x, y);

        ////gamepad
        //Sint16 gamepadAxisX = 0;
        //if (gamepad)
        //    gamepadAxisX = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTX);


        // Polling
        const bool* keys = SDL_GetKeyboardState(NULL);
        SDL_PumpEvents();


        //move sprite
        xMove = 0;
        yMove = 0;

        //mouse click example
        //if (mbFlags & SDL_BUTTON_MASK(SDL_BUTTON_LEFT))
        //    xMove = 1;
        ////gamepad example
        //if (gamepadAxisX > 0)
        //    xMove = 1;

        if (keys[SDL_SCANCODE_W])
            yMove = -1;
        if (keys[SDL_SCANCODE_A])
            xMove = -1;
        if (keys[SDL_SCANCODE_S])
            yMove = 1;
        if (keys[SDL_SCANCODE_D])
            xMove = 1;

        xPos += xMove * moveScale;
        yPos += yMove * moveScale;

        //clear last frame
        SDL_RenderClear(ren);


        // draw calls

        //make rect to render sprite into
        SDL_FRect* dst = new SDL_FRect{ xPos, yPos, 64,64 };

        //scretch the rendering rect
        //dst->w *= 2;

        //clip, draw only part of texture on rect
        //SDL_RenderTexture(ren, sprite, new SDL_FRect{ 0,0, 32, 64 }, dst);

        //rotated
        /*angle += .01;
        SDL_RenderTextureRotated(ren, sprite, NULL, dst, angle, NULL, SDL_FLIP_NONE);*/

        //normal render
        SDL_RenderTexture(ren, sprite, NULL, dst);


        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}

