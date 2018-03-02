#ifndef __EObjects_Components_Graphics_IPicture
#define __EObjects_Components_Graphics_IPicture

#include "../icomponent.hpp"

namespace EObjects {
	namespace Components {
		namespace Graphics {
			
			class IPicture : public IComponent{
			public:
				IPicture(){};
				virtual ~IPicture(void){};

				virtual std::string getComponentID(void) const { return "EObjects::Components::Graphics::Picture"; };
				std::string getFamilyID(void) const { return "EObjects::Components::Graphics::Picture"; };

				virtual void update(void) = 0;
				virtual Core::Layer::Enum getLayer(void) = 0;

			};

		}
	}
}

#endif // __EObjects_Components_Graphics_IPicture
