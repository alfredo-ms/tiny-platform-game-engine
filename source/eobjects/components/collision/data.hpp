#ifndef __EObjects_Components_Collision_Data
#define __EObjects_Components_Collision_Data

#include <map>
#include <vector>

namespace EObjects {
	namespace Components {
		namespace Collision {
			class ICollision;
			
			namespace Data {
			
				namespace GeneralDepth {
					enum Enum {
						Deep,
						Back,
						Front
					};
				}

				typedef std::map <GeneralDepth::Enum, std::vector<ICollision*>> CollisionList;
				

			}

		}
	}
}

#endif // __EObjects_Components_Collision_Data
