#include "view.hpp"


namespace Core {
    namespace Graphics {

		View::View(Renderer *renderer) : _renderer(renderer) {
		}

		View::~View(){
		}

        Core::ReturnStatus::Enum View::setViewport(){
			if (SDL_RenderSetViewport(_renderer->get(),&area) != 0){
				addErrorMessage(SDL_GetError());
				return Core::ReturnStatus::Failed;
			}

			return Core::ReturnStatus::Success;
		}

    }
}