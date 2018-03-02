#ifndef __Core_Graphics_ImageTypeSupport
#define __Core_Graphics_ImageTypeSupport

#include "../typesdescription.hpp"
#include "../ibase.hpp"


namespace Core {
	namespace Graphics {

		class ImageTypeSupport : IBase {
		public:
			static ImageTypeSupport *getInstance();
			~ImageTypeSupport();

			virtual std::string getComponentID(void) const { return "Core::Graphics::ImageTypeSupport"; };

			Core::ReturnStatus::Enum init();
			void stop();

		private:
			ImageTypeSupport();
			bool initiated;
		};

	}
}

#endif // __Core_Graphics_ImageTypeSupport