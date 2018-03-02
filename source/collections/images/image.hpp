#ifndef __Collections_Images_Image
#define __Collections_Images_Image

#include "../icollections.hpp"
#include "../../appbase.hpp"


namespace Collections {
	namespace Images {

		class Image : public ICollections {
			public:
				Image(const std::string imagePath, AppBase* base);
				Image(AppBase* base);
				~Image();

				void draw(SDL_Rect *srcRect, SDL_Rect *dstRect);
				void draw(SDL_Rect *srcRect, SDL_Rect *dstRect, bool flipped);
				int getImageWidth();
				int getImageHeight();

				Core::ReturnStatus::Enum loadImage(const std::string imagePath);
            
				virtual std::string getComponentID(void) const { return "Collections::Images::Image"; };
				std::string getFamilyID(void) const { return "Collections::Images::Image"; };

			protected:
				AppBase *_base;
				SDL_Texture *_texture;
				int _imageWidth;
				int _imageHeight;

		};



	}
}

#endif // __Collections_Images_Image