#ifndef __EObjects_Components_Collision_Objects_IObject
#define __EObjects_Components_Collision_Objects_IObject

#include "../../../../core/ibase.hpp"
#include <vector>

namespace EObjects {
	namespace Components {
		namespace Collision {
			namespace Objects {

				class IObject : public Core::IBase {
				public:
					IObject(){};
					virtual ~IObject(void){};

					virtual std::string getComponentID(void) const { return "EObjects::Components::Collision::Objects::IObject"; };
					std::string getFamilyID(void) const { return "EObjects::Components::Collision::Objects::IObject"; };

					Core::Collision::Type::Enum getType(void){
						return _type;
					}

					Core::Collision::Depth::Enum getDepth(void){
						return _depth;
					}

					bool intersect(SDL_Rect *rect01, SDL_Rect *rect02){
						if (rect01->x < (rect02->x + rect02->w) &&
							(rect01->x + rect01->w) > rect02->x &&
							(rect01->y < rect02->y) + rect02->h &&
							(rect01->h + rect01->y) > rect02->y)
							return true;
						else
							return false;
					}

					virtual bool intersect(IObject *obj) = 0;

				protected:
					Core::Collision::Depth::Enum _depth;
					Core::Collision::Type::Enum _type;

				};
			}
		}
	}
}

#endif // __EObjects_Components_Collision_Objects_IObject
