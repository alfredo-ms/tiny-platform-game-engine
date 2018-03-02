#include "window.hpp"
#include "math.h"

namespace Core {
    namespace Graphics {

		Window::Window(): renderer(this), mainView(&renderer) {
            _window = nullptr;
            _title = "Title";
            _flags = SDL_WINDOW_OPENGL;
            _fullScreen = false;
			internalResolution.set(320, 240);
			screenResolution.set(internalResolution.getW(), internalResolution.getH());
			useDesktopResolution(false);
			setScaleSystem(Core::Video::ScaleType::NearestAspectRatio);
        }

        Window::~Window(){
            destroy();
        }

        SDL_Window* Window::get(){
            return _window;
        }

        SDL_Surface* Window::getSurface(){
            return SDL_GetWindowSurface(_window);
        }

        ReturnStatus::Enum Window::create(){
			if (_useDesktopRes){
				_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_FULLSCREEN_DESKTOP | _flags);
				catchCurrentResolution();
			}else{
				_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenResolution.getW(), screenResolution.getH(), SDL_WINDOW_INPUT_GRABBED | _flags);
			}

			if (_window == nullptr){
                addErrorMessage(SDL_GetError());
                return Core::ReturnStatus::Failed;
            }

			if (renderer.create() != Core::ReturnStatus::Success){
				addErrorMessage(SDL_GetError());
				return Core::ReturnStatus::Failed;
			}

			updateVideoOptions();

            return Core::ReturnStatus::Success;
        }

		void Window::useDesktopResolution(bool useDesktopRes){
			_useDesktopRes = useDesktopRes;
		}

        void Window::destroy(){
            if (_window != nullptr){
                SDL_DestroyWindow(_window);
				_window = nullptr;
			}
        }
        
        void Window::update(){
            SDL_UpdateWindowSurface(_window);
        }

        void Window::setTitle(std::string title){
            _title = title;
        }

        void Window::setFullScreen(bool fullScreen_mode){
			if (((fullScreen_mode == true) && (_fullScreen == false)) || ((fullScreen_mode == false) && (_fullScreen == true)))
                _flags = _flags ^ SDL_WINDOW_FULLSCREEN;
  
			_fullScreen = fullScreen_mode;

			if (_fullScreen == false){
				screenResolution.set(internalResolution.getW(), internalResolution.getH());
			}else{
				catchCurrentResolution();
			}

        }

		void Window::catchCurrentResolution(){
			SDL_DisplayMode displayMode;
			SDL_GetCurrentDisplayMode(0, &displayMode);
			screenResolution.set(displayMode.w, displayMode.h);
		}

		void Window::updateVideoOptions(){
			// Desabilita filtros
			SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"); 

			if (_fullScreen == true){
				mainView.area.x = 0;
				mainView.area.y = 0;
				mainView.area.w = 0;
				mainView.area.h = 0;
			
				if (_scaleType == Core::Video::ScaleType::NoRestrictions){
					mainView.area.w = screenResolution.getW();
					mainView.area.h = screenResolution.getH();
					surfaceSize.set(mainView.area.w, mainView.area.h);
				}else{
					if ((_scaleType == Core::Video::ScaleType::NearestAspectRatio) || (_scaleType == Core::Video::ScaleType::NearestAspectRatio_WithAllScreen)){
						
						float displayRatioW,displayRatioH, minRatio;
						displayRatioW = ((float)screenResolution.getW())/((float)internalResolution.getW());
						displayRatioH = ((float)screenResolution.getH())/((float)internalResolution.getH());
						
						if (displayRatioW >= displayRatioH){
							minRatio = floor(displayRatioH);
							if (_scaleType == Core::Video::ScaleType::NearestAspectRatio)
								mainView.area.x += (((displayRatioW-displayRatioH)*internalResolution.getW())/minRatio)/2;
							else
								mainView.area.w += (((displayRatioW-displayRatioH)*internalResolution.getW())/minRatio);
						}else{
							minRatio = floor(displayRatioW);
							if (_scaleType == Core::Video::ScaleType::NearestAspectRatio)
								mainView.area.y += (((displayRatioH-displayRatioW)*internalResolution.getH())/minRatio)/2;
							else
								mainView.area.h += (((displayRatioH-displayRatioW)*internalResolution.getH())/minRatio);
						}

						// Define qual a região de desenho na tela, utilizando o "aspect ratio" definido acima
						float surfaceW = 0, surfaceH = 0;
						surfaceW = internalResolution.getW()+((screenResolution.getW()/minRatio)-internalResolution.getW());
						surfaceH = internalResolution.getH()+((screenResolution.getH()/minRatio)-internalResolution.getH());
						if (displayRatioW > displayRatioH)
							surfaceW -= ((displayRatioW-displayRatioH)*internalResolution.getW())/minRatio;
						else if (displayRatioH > displayRatioW)
							surfaceH -= ((displayRatioH-displayRatioW)*internalResolution.getH())/minRatio;
						surfaceSize.set(surfaceW+mainView.area.w, surfaceH+mainView.area.h);
						mainView.area.w += surfaceSize.getW();
						mainView.area.h += surfaceSize.getH();

						SDL_RenderSetScale(renderer.get(), minRatio, minRatio);
					}
	
				}

			}
		}

		void Window::setScaleSystem(Core::Video::ScaleType::Enum scaleType){
			_scaleType = scaleType;
		}

    }
}
