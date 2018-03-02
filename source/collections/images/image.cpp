#include "image.hpp"
#include "SDL_image.h"


namespace Collections {
	namespace Images {
        
		Image::Image(const std::string imagePath, AppBase *base) : _base(base) {
			_texture = nullptr;
			_imageWidth = 0;
			_imageHeight = 0;
			loadImage(imagePath);
		}

		Image::Image(AppBase *base) : _base(base) {
			_texture = nullptr;
			_imageWidth = 0;
			_imageHeight = 0;
		}
        
		Image::~Image(){
			if (this->_texture != nullptr){
				SDL_DestroyTexture(_texture);
				_texture = nullptr;
			}
		}
			
		void Image::draw(SDL_Rect *srcRect, SDL_Rect *dstRect){
			SDL_RenderCopy(_base->mainWindow.renderer.get(), _texture, srcRect, dstRect);
		}

		void Image::draw(SDL_Rect *srcRect, SDL_Rect *dstRect, bool flipped){
			SDL_RendererFlip flipType = SDL_FLIP_NONE;
			if (flipped)
				flipType = SDL_FLIP_HORIZONTAL;

			SDL_RenderCopyEx(_base->mainWindow.renderer.get(), _texture, srcRect, dstRect, 0, nullptr, flipType);
		}

        
		Core::ReturnStatus::Enum Image::loadImage(const std::string imagePath){
			SDL_Surface *loadedSurface = IMG_Load(imagePath.c_str());
			if (loadedSurface == NULL){
				addErrorMessage(IMG_GetError());
				return Core::ReturnStatus::Failed;
			}else{ 
				_texture = SDL_CreateTextureFromSurface(_base->mainWindow.renderer.get(), loadedSurface);
				if(_texture == NULL){ 
					_texture = nullptr;
					addErrorMessage(SDL_GetError());
					return Core::ReturnStatus::Failed;
				}
 
				SDL_QueryTexture(_texture, NULL, NULL, &_imageWidth, &_imageHeight);

				SDL_FreeSurface(loadedSurface); 
			} 

			return Core::ReturnStatus::Success;
		}

		int Image::getImageWidth(){
			return _imageWidth;
		}

		int Image::getImageHeight(){
			return _imageHeight;
		}
		
	}    
}
