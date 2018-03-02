#ifndef __Core_Graphics_Renderer
#define __Core_Graphics_Renderer

#include "../ibase.hpp"
#include <SDL.h>


namespace Core {
    namespace Graphics {

		class Window;

		// classe utilizada para a renderização de imagens
		class Renderer: public IBase {
            public:
                Renderer(Window *window);
                virtual ~Renderer();

                virtual std::string getComponentID(void) const { return "Core::Graphics::Renderer"; };

				SDL_Renderer * get();
                ReturnStatus::Enum create();
                void update();
                void clear();
                void destroy();
				ReturnStatus::Enum copy(SDL_Texture *texture, SDL_Rect *source_rect, SDL_Rect *dest_rect);
				ReturnStatus::Enum setDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
				ReturnStatus::Enum setBlendMode(SDL_BlendMode blendMode);
				void fillRect(SDL_Rect &rect);

            private:
                Window *_window;
                SDL_Renderer *_renderer; 
                Uint32 _flags;

        };

    }
}

#endif // __Core_Graphics_Renderer
