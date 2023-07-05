/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** SdlBase cpp
*/

#include "SdlBase.hpp"

namespace arcade
{
    SdlBase::SdlBase()
    {
        this->_letter = 0;
        this->_color = { 255, 255, 255, 255 };
    }

    SdlBase::~SdlBase()
    {
    }

    void SdlBase::Init()
    {
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        this->_window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
        this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        TTF_Init();
        this->_font = TTF_OpenFont("src/Graphics/Sprites/arial.ttf", 28);
        SDL_Surface* backgroundSurface = IMG_Load("src/Graphics/Sprites/snake.png");
        _backgroundTexture = SDL_CreateTextureFromSurface(_renderer, backgroundSurface);
        SDL_FreeSurface(backgroundSurface);
        SDL_Surface* backgroundSquare = IMG_Load("src/Graphics/Sprites/carre.png");
        _backgroundTextureSquare = SDL_CreateTextureFromSurface(_renderer, backgroundSquare);
        SDL_FreeSurface(backgroundSquare);
    }

    void SdlBase::LoadStruct(MyStruct::_textToDraw textDisplay)
    {
        this->_textDisplay = textDisplay;
        this->InitColor();
    }

    void SdlBase::InitColor()
    {
        for (std::size_t i = 0; i < this->_textDisplay.sprites.size(); i++) {
            this->_texturesSprites = IMG_LoadTexture(this->_renderer, this->_textDisplay.sprites[i].c_str());

            SDL_QueryTexture(this->_texturesSprites, nullptr, nullptr, &this->_tWidth, &this->_tHeight);
            SDL_GetRendererOutputSize(this->_renderer, &this->_wWidth, &this->_wHeight);

            SDL_Rect dest_rect = {
                this->_textDisplay.xSprite[i],
                this->_textDisplay.ySprite[i],
                this->_wWidth,
                this->_wHeight
            };
            SDL_RenderCopy(this->_renderer, this->_texturesSprites, nullptr, &dest_rect);
            SDL_DestroyTexture(this->_texturesSprites);
        }
    }

    void SdlBase::DisplayHome()
    {
        SDL_RenderClear(this->_renderer);

        for (std::size_t i = 0; i < this->_textDisplay.text.size(); i++) {
            SDL_Surface* surface = TTF_RenderText_Solid(this->_font, this->_textDisplay.text[i].c_str(), this->_color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
            int surfaceWidth = surface->w;
            int surfaceHeight = surface->h;

            SDL_FreeSurface(surface);

            SDL_Rect dstRect = { static_cast<int>(this->_textDisplay.x[i] * 12 + 8), static_cast<int>(this->_textDisplay.y[i] * 24), surfaceWidth, surfaceHeight };
            SDL_RenderCopy(this->_renderer, texture, nullptr, &dstRect);
            SDL_DestroyTexture(texture);
        }
        SDL_Surface* surface = TTF_RenderText_Solid(this->_font, this->_textDisplay.username.c_str(), this->_color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        int surfaceWidth = surface->w;
        int surfaceHeight = surface->h;

        SDL_FreeSurface(surface);

        SDL_Rect dstRect = { static_cast<int>(0 * 12 + 8), static_cast<int>(13 * 24), surfaceWidth, surfaceHeight };
        SDL_RenderCopy(this->_renderer, texture, nullptr, &dstRect);
        SDL_DestroyTexture(texture);

        SDL_RenderPresent(this->_renderer);
    }

    void SdlBase::DisplayParsing()
    {
    }

    void SdlBase::DisplayMap()
    {
        this->_game = 1;
        this->_gameLaunch = 1;
        SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->_renderer);
        SDL_RenderCopy(_renderer, _backgroundTexture, NULL, NULL);
        SDL_Rect destRect = {1370, 220, 400, 455};
        SDL_RenderCopy(_renderer, _backgroundTextureSquare, NULL, &destRect);
        SDL_Rect destRect2 = {928, 835, 90, 90};
        SDL_RenderCopy(_renderer, _backgroundTextureSquare, NULL, &destRect2);

        TTF_Font* font = TTF_OpenFont("src/Graphics/Sprites/arial.ttf", 28);
        if (!font) {
            // Handle error
        }

        SDL_Color color = { 255, 255, 255, 255 };
        int wrapLength = 500;
        int lineHeight = 20;
        SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, "Commands:", color, wrapLength);
        if (!textSurface) {
            // Handle error
        }
        SDL_Rect textRect = { 300, 550, textSurface->w, textSurface->h };
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
        SDL_RenderCopy(_renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
        const char* lines[] = {
            "[^] : Move Forward",
            "[>] : Move Right",
            "[<] : Move Left",
            "[v] : Move Down",
            "[S] : Previous Library",
            "[D] : Next Library",
            "[Suppr] : Leave"
        };
        int numLines = sizeof(lines) / sizeof(lines[0]);
        for (int i = 0; i < numLines; i++) {
            textSurface = TTF_RenderText_Blended_Wrapped(font, lines[i], color, wrapLength);
            if (!textSurface) {
                // Handle error
            }
            textRect = { 300, 600 + (i+1) * lineHeight, textSurface->w, textSurface->h };
            textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
            SDL_RenderCopy(_renderer, textTexture, NULL, &textRect);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
        }
        TTF_CloseFont(font);

        int i1 = 0;
        for (std::size_t i = 0; i < this->_textDisplay.map.size(); i++) {
            for (int j = 0; this->_textDisplay.map[i][j] != ':'; j++) {
                if (this->_textDisplay.map[i][j] == '#') {
                    i1 = i;
                    SDL_Rect rect = {(j + 70) * 12 + 8, (i1 + 5) * 28, 25, 25};
                    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
                    SDL_RenderFillRect(this->_renderer, &rect);
                } else if (this->_textDisplay.map[i][j] != '#' && this->_textDisplay.map[i][j] != '.') {
                    i1 = i;
                    SDL_Rect rect = {(j + 70) * 12 + 8, (i1 + 5) * 28, 25, 25};
                    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 255, 255);
                    SDL_RenderFillRect(this->_renderer, &rect);
                }
            }
        }
        for (std::size_t i = 0; i < this->_textDisplay.leaderboard.size(); i++) {
            SDL_Surface* surface = TTF_RenderText_Solid(this->_font, this->_textDisplay.leaderboard[i].c_str(), this->_color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
            int surfaceWidth = surface->w;
            int surfaceHeight = surface->h;

            SDL_FreeSurface(surface);

            SDL_Rect dstRect = { static_cast<int>(123 * 12 + 8), static_cast<int>((15 + i) * 24), surfaceWidth, surfaceHeight };
            SDL_RenderCopy(this->_renderer, texture, nullptr, &dstRect);
            SDL_DestroyTexture(texture);
        }
    }

    void SdlBase::DisplayPlayer(std::pair<std::vector<int>, std::vector<int>>)
    {}

    void SdlBase::DisplayOther(int score)
    {
        SDL_Surface* surface = TTF_RenderText_Solid(this->_font, std::to_string(score).c_str(), this->_color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        int surfaceWidth = surface->w;
        int surfaceHeight = surface->h;

        SDL_FreeSurface(surface);

        SDL_Rect dstRect = { static_cast<int>(960), static_cast<int>(860), surfaceWidth, surfaceHeight };
        SDL_RenderCopy(this->_renderer, texture, nullptr, &dstRect);
        SDL_DestroyTexture(texture);

        SDL_RenderPresent(this->_renderer);
    }

    std::string SdlBase::Command()
    {
        while (SDL_PollEvent(&this->_event)) {
            switch (this->_event.type)
            {
                case SDL_QUIT:
                    return ("Exit");
                default:
                    break;
            }
        }
        this->_state = SDL_GetKeyboardState(NULL);
        if (this->_state[SDL_SCANCODE_DELETE]) {
            return ("Exit");
        } else if (this->_state[SDL_SCANCODE_F6]) {
            return ("lib/arcade_ncurses.so");
        } else if (this->_state[SDL_SCANCODE_F5]) {
            return ("lib/arcade_sfml.so");
        }
        if (this->_game != 0 && this->_gameLaunch != 1 && this->_state[SDL_SCANCODE_UP]) {
            this->_gameLaunch = 1;
            return ("PLAY");
        }
        if (this->_game != 0 && this->_gameLaunch == 1 && this->_state[SDL_SCANCODE_UP]) {
            this->_textDisplay.SetInput(0403);
        }
        if (this->_game != 0 && this->_gameLaunch == 1 && this->_state[SDL_SCANCODE_LEFT]) {
            this->_textDisplay.SetInput(0404);
        }
        if (this->_game != 0 && this->_gameLaunch == 1 && this->_state[SDL_SCANCODE_DOWN]) {
            this->_textDisplay.SetInput(0402);
        }
        if (this->_game != 0 && this->_gameLaunch == 1 && this->_state[SDL_SCANCODE_RIGHT]) {
            this->_textDisplay.SetInput(0405);
        }
        return ("");
    }

    std::string SdlBase::GamesCommand()
    {
        if (this->_game != 1 && this->_state[SDL_SCANCODE_F2]) {
            this->_state = 0;
            this->_game = 1;
            return ("lib/arcade_nibbler.so");
        } else if (this->_game != 2 && this->_state[SDL_SCANCODE_F4]) {
            this->_state = 0;
            this->_game = 2;
            return ("lib/arcade_snake.so");
        } else if (this->_game != 0 && this->_state[SDL_SCANCODE_KP_MULTIPLY]) {
            this->_state = 0;
            this->_game = 0;
            return ("lib/arcade_home.so");
        }
        return ("");
    }

    int SdlBase::SetUsername()
    {
        if (this->_event.key.keysym.sym >= 65 && this->_event.key.keysym.sym <= 90) {
            this->_letter = this->_event.key.keysym.sym;
            this->_event.key.keysym.sym = 0;
            return (this->_letter);
        }
        if (this->_event.key.keysym.sym >= 97 && this->_event.key.keysym.sym <= 122) {
            this->_letter = this->_event.key.keysym.sym;
            this->_event.key.keysym.sym = 0;
            return (this->_letter);
        }
        if (this->_event.key.keysym.sym == SDLK_BACKSPACE) {
            this->_event.key.keysym.sym = 0;
            return (0407);
        }
        return (0);
    }

    void SdlBase::QuitArcade()
    {
        SDL_DestroyRenderer(this->_renderer);
        SDL_DestroyWindow(this->_window);
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
    }
}

extern "C"
{
    arcade::IDisplayModule *InitLibrary()
    {
        static arcade::SdlBase display;
        return &display;
    }
}
