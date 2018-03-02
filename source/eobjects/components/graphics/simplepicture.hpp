#ifndef __EObjects_Components_Graphics_SimplePicture
#define __EObjects_Components_Graphics_SimplePicture

#include "ipicture.hpp"
#include "../../../collections/images/imagecollection.hpp"

namespace EObjects {
	namespace Components {
		namespace Graphics {
			class SimplePicture : public IPicture {
			public:
				SimplePicture(Collections::Images::ImageCollection *imageCollection, Core::integer_id id);
				~SimplePicture();

				virtual std::string getComponentID(void) const { return "EObjects::Components::Graphics::SimplePicture"; };

				virtual void update(void);
				virtual Core::Layer::Enum getLayer(void);
				void setLayer(Core::Layer::Enum layer);
				void changeID(Core::integer_id id);
				void setImageCollection(Collections::Images::ImageCollection *imageCollection);

			private:
				Collections::Images::ImageCollection *_imageCollection;
				Core::integer_id _id;
				Core::Layer::Enum _layer;
			};

		}
	}
}

#endif // __EObjects_Components_Graphics_SimplePicture
