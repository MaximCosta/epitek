/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** SdlBase hpp
*/

#ifndef SDLBASEHEADER
#define SDLBASEHEADER

#include "../IDisplayModule.hpp"

// SDL2 include
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

namespace arcade
{
    class SdlBase : public IDisplayModule {
        public:
            SdlBase();
            ~SdlBase();

            void Init();
            void LoadStruct(MyStruct::_textToDraw textDisplay);
            void InitColor();

            void DisplayHome();
            void DisplayParsing();
            void DisplayMap();
            void DisplayPlayer(std::pair<std::vector<int>, std::vector<int>>);
            void DisplayOther(int score);

            std::string Command();
            std::string GamesCommand();
            int SetUsername();
            void QuitArcade();

        protected:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Event _event;
            SDL_Color _color;

            const Uint8 *_state;
            TTF_Font* _font;

            SDL_Texture* _texturesSprites;
            std::vector<SDL_Texture*> _textures;
            std::vector<SDL_Rect> _rects;

            int _tWidth;
            int _tHeight;
            int _wWidth;
            int _wHeight;
            int _letter;
            int _game;
            int _gameLaunch;
            SDL_Texture* _backgroundTexture;
            SDL_Texture* _backgroundTextureSquare;

            std::string _path;

            MyStruct::_textToDraw _textDisplay;

        private:
    };
}

#endif /* !SDLBASEHEADER */
