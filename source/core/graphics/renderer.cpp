#include "renderer.hpp"
#include "window.hpp"


namespace Core {
    namespace Graphics {

        Renderer::Renderer(Window *window): _window(window) {
            _renderer = nullptr;
        }

        Renderer::~Renderer(){
            destroy();
        }

		SDL_Renderer *Renderer::get(){
			return _renderer;
		}

        ReturnStatus::Enum Renderer::create(){
			_renderer = SDL_CreateRenderer(_window->get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (_renderer == nullptr){
                addErrorMessage(SDL_GetError());
                return Core::ReturnStatus::Failed;
            }

			setBlendMode(SDL_BLENDMODE_BLEND);

            return Core::ReturnStatus::Success;
        }

        void Renderer::destroy(){
            if (_renderer != nullptr)
                SDL_DestroyRenderer(_renderer);
        }

        void Renderer::clear(){
            SDL_RenderClear(_renderer);
        }

        ReturnStatus::Enum Renderer::copy(SDL_Texture *texture, SDL_Rect *source_rect, SDL_Rect *dest_rect){
            if  (SDL_RenderCopy(_renderer, texture, source_rect, dest_rect) != 0){
                addErrorMessage(SDL_GetError());
                return Core::ReturnStatus::Failed;
            }

            return Core::ReturnStatus::Success;
        }

        void Renderer::update(){
            SDL_RenderPresent(_renderer);
        }

        ReturnStatus::Enum Renderer::setDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha){
            if  (SDL_SetRenderDrawColor(_renderer, red, green, blue, alpha) != 0){
                addErrorMessage(SDL_GetError());
                return Core::ReturnStatus::Failed;
            }

            return Core::ReturnStatus::Success;
        }

		ReturnStatus::Enum Renderer::setBlendMode(SDL_BlendMode blendMode){
			if (SDL_SetRenderDrawBlendMode(get(), blendMode) != 0){
				addErrorMessage(SDL_GetError());
				return ReturnStatus::Failed;
			}

			return ReturnStatus::Success;
		}

		void Renderer::fillRect(SDL_Rect &rect){
			SDL_RenderFillRect(_renderer, &rect);
		}

    }
}
