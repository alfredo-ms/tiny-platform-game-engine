#ifndef __Collections_Images_ImageCollection
#define __Collections_Images_ImageCollection

#include "image.hpp"
#include <map>


namespace Collections {
	namespace Images {

		class ImageCollection : public Image {
		public:
			ImageCollection(const std::string imagePath, AppBase *base);
			ImageCollection(AppBase *base);
			~ImageCollection();

			virtual std::string getComponentID(void) const { return "Collections::Images::ImageCollection"; };
			virtual std::string getFamilyID(void) const { return Image::getFamilyID(); };

			inline SDL_Rect& getFrame(Core::integer_id id){ return this->imgCollectionGroup[id]; };
			void addFrame(Core::integer_id id, int x, int y, int w, int h);
			void addFrame(Core::integer_id id, SDL_Rect rect);
			void clearImagePositions();

			void draw(Core::integer_id image_id, int x, int y);
			void draw(Core::integer_id image_id, SDL_Rect *dstRect);
			void draw(Core::integer_id image_id, SDL_Rect *dstRect, bool flipped);

			Core::ReturnStatus::Enum removeImagePosition(Core::integer_id id);

		private:
			typedef std::map<Core::integer_id, SDL_Rect> ImgCollectionGroup;
			ImgCollectionGroup imgCollectionGroup;
			SDL_Rect _tempRect;
		};
	}
}

#endif // __Collections_Images_ImageCollection
