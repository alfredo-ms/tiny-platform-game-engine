#ifndef __Core_Graphics_Window
#define __Core_Graphics_Window

#include "../ibase.hpp"
#include <SDL.h>
#include "renderer.hpp"
#include "view.hpp"

// classe utilizada para a criação e manuseio de janelas
namespace Core {
    namespace Graphics {

		struct Resolution {
		public:
			void set(size_t w, size_t h) { _res_w = w; _res_h = h; };
			void setW(size_t w) { _res_w = w; };
			void setH(size_t h) { _res_h = h; };
			size_t getW() { return _res_w; };
			size_t getH() { return _res_h; };
		private:
			size_t _res_w, _res_h;
		};

        class Window: public IBase {
            public:
                Window();
                virtual ~Window();

                virtual std::string getComponentID(void) const { return "Core::Graphics::Window"; };

                SDL_Window* get();
                SDL_Surface* getSurface();
                ReturnStatus::Enum create();
                void destroy();
                void update();
                void setTitle(std::string title);
                void setFullScreen(bool fullScreen_mode);
				void useDesktopResolution(bool useDesktopRes);
				void setScaleSystem(Core::Video::ScaleType::Enum scaleType);
				Renderer renderer;

				Resolution internalResolution;
				Resolution surfaceSize;
				Resolution screenResolution;
				View mainView;

            private:
				void catchCurrentResolution();
				void updateVideoOptions();
                SDL_Window *_window;
                std::string _title;
                Uint32 _flags;
                bool _fullScreen;
				bool _useDesktopRes;
				Core::Video::ScaleType::Enum _scaleType;
        };

    }
}

#endif // __Core_Graphics_Window

