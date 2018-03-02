#include "imagetypesupport.hpp"
#include "SDL_image.h"


namespace Core {
	namespace Graphics {

		ImageTypeSupport *ImageTypeSupport::getInstance(){
			static ImageTypeSupport imgSupport;
			return &imgSupport; 
		}

		ImageTypeSupport::ImageTypeSupport(){
			initiated = false;
		}

		ImageTypeSupport::~ImageTypeSupport(){
			stop();
		}

		Core::ReturnStatus::Enum ImageTypeSupport::init(){
			 int imgFlags = IMG_INIT_PNG;
			 if( !(IMG_Init(imgFlags) & imgFlags) ){
				initiated = false;
				addErrorMessage(IMG_GetError());
                return Core::ReturnStatus::Failed;
			 }
			 
			 initiated = true;
			 return Core::ReturnStatus::Success;
		}

		void ImageTypeSupport::stop(){
			if (initiated == true)
				IMG_Quit();
		}

	}
}