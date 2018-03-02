#ifndef __Core_Graphics_View
#define __Core_Graphics_View

#include "../ibase.hpp"
#include <SDL.h>
#include "renderer.hpp"



namespace Core {
    namespace Graphics {

		// classe utilizada para definir uma determinada área de desenho
		class View: public IBase {
            public:
				View(Renderer *renderer);
                virtual ~View();

                virtual std::string getComponentID(void) const { return "Core::Graphics::View"; };

				Core::ReturnStatus::Enum setViewport();

				SDL_Rect area;

		private:
			Renderer *_renderer;
        };

    }
}

#endif // __Core_Graphics_View

