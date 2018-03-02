#include "imagecollection.hpp"

namespace Collections {
	namespace Images {

		ImageCollection::ImageCollection(const std::string imagePath, AppBase *base)
			: Image(imagePath, base){
		}

		ImageCollection::ImageCollection(AppBase *base)
			: Image(base){
		}

		ImageCollection::~ImageCollection(){
			clearImagePositions();
		}

/*		void ImageCollection::update(void* temp){

			switch (getSpriteDirection()) {
			case ImageDirection::Right:
				this->image->draw(getOwnerGO(), getImagePosition(getImagePositionID()));
				break;

			case ImageDirection::Left:
				this->image->draw(getOwnerGO(), sf::IntRect(getImagePosition(getImagePositionID()).left + getImagePosition(getImagePositionID()).width, getImagePosition(getImagePositionID()).top, -getImagePosition(getImagePositionID()).width, getImagePosition(getImagePositionID()).height));
				break;

			case ImageDirection::Up:
				break;

			case ImageDirection::Down:
				break;
			}
		}*/

		void ImageCollection::addFrame(Core::integer_id id, int x, int y, int w, int h){
			ImgCollectionGroup::iterator tgoIterator = this->imgCollectionGroup.find(id);

			if (tgoIterator != this->imgCollectionGroup.end())
				this->imgCollectionGroup.erase(id);

			this->imgCollectionGroup[id].x = x;
			this->imgCollectionGroup[id].y = y;
			this->imgCollectionGroup[id].w = w;
			this->imgCollectionGroup[id].h = h;
		}

		void ImageCollection::addFrame(Core::integer_id id, SDL_Rect rect){
			ImgCollectionGroup::iterator tgoIterator = this->imgCollectionGroup.find(id);

			if (tgoIterator != this->imgCollectionGroup.end())
				this->imgCollectionGroup.erase(id);

			this->imgCollectionGroup[id] = rect;
		}

		void ImageCollection::clearImagePositions(){
			for (ImgCollectionGroup::iterator tgoIterator = this->imgCollectionGroup.begin(); tgoIterator != this->imgCollectionGroup.end(); ++tgoIterator){
				imgCollectionGroup.erase(tgoIterator->first);
			}
		}

		Core::ReturnStatus::Enum ImageCollection::removeImagePosition(Core::integer_id id){
			ImgCollectionGroup::iterator tgoIterator = this->imgCollectionGroup.find(id);

			if (tgoIterator != this->imgCollectionGroup.end()){
				this->imgCollectionGroup.erase(id);
				return Core::ReturnStatus::Success;
			}

			return Core::ReturnStatus::Failed;
		}

		void ImageCollection::draw(Core::integer_id image_id, int x, int y){
			_tempRect.x = x;
			_tempRect.y = y;
			_tempRect.h = imgCollectionGroup[image_id].h;
			_tempRect.w = imgCollectionGroup[image_id].w;
			SDL_RenderCopy(_base->mainWindow.renderer.get(), _texture, &imgCollectionGroup[image_id], &_tempRect);
		}

		void ImageCollection::draw(Core::integer_id image_id, SDL_Rect *dstRect){
			SDL_RenderCopy(_base->mainWindow.renderer.get(), _texture, &imgCollectionGroup[image_id], dstRect);
		}

		void ImageCollection::draw(Core::integer_id image_id, SDL_Rect *dstRect, bool flipped){
			SDL_RendererFlip flipType = SDL_FLIP_NONE;
			if (flipped)
				flipType = SDL_FLIP_HORIZONTAL;

			SDL_RenderCopyEx(_base->mainWindow.renderer.get(), _texture, &imgCollectionGroup[image_id], dstRect, 0, nullptr, flipType);
		}

	}
}
