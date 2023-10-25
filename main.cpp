#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

void loop(SDL_Renderer *renderer);
void draw(SDL_Renderer *renderer, bool alternate);

int main(int argc, char** argv) {
    bool alternate = false;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Flickering test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, 0);
    if(!window) {
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(!renderer) {
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }
    
    loop(renderer);

    return 0;
}

void draw(SDL_Renderer *renderer, bool alternate) {
    SDL_SetRenderDrawColor(renderer, 85, 128, 170, 255);
    SDL_RenderClear(renderer);
    
    SDL_Rect m_rect1, m_rect2;
    m_rect1.w = m_rect1.h = m_rect2.w = m_rect2.h = 50;
    m_rect1.y = m_rect2.y = 175;
    
    m_rect1.x = alternate ? 200 : 150;
    m_rect2.x = alternate ? 150 : 200;
    
    SDL_SetRenderDrawColor(renderer, 95, 142, 152, 255);
    SDL_RenderFillRect(renderer, &m_rect1);
    
    SDL_SetRenderDrawColor(renderer, 72, 114, 152, 255);
    SDL_RenderFillRect(renderer, &m_rect2);
    
    SDL_RenderPresent(renderer);
}

void loop(SDL_Renderer *renderer) {
    SDL_Event event;
    bool running = true;
    bool alternate = false;
    while(running){
        while(SDL_PollEvent(&event) !=0) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        draw(renderer, alternate);
        alternate = !alternate;
    }
}