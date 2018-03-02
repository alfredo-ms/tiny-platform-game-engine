#ifndef __EObjects_Components_Collision_ICollision
#define __EObjects_Components_Collision_ICollision

#include "../icomponent.hpp"
#include "objects/iobject.hpp"
#include "data.hpp"

namespace EObjects {
	namespace Components {
		namespace Collision {

			class ICollision : public IComponent{
			public:
				ICollision(){};
				virtual ~ICollision(void){};
								
				virtual std::string getComponentID(void) const { return "EObjects::Components::Collision::ICollision"; };
				std::string getFamilyID(void) const { return "EObjects::Components::Collision::ICollision"; };

				virtual void update(void) = 0;
				virtual std::vector<Objects::IObject*>* getCurrentObjects() = 0;
				virtual Objects::IObject* firstObject() = 0;
				virtual Objects::IObject* nextObject() = 0;
				bool isActive(){ return _active; };
				void setActive(bool active){ _active = active; };

				static Data::CollisionList collisionList;
				static Core::integer_id id_counter;
			
			private:
				bool _active;
			};

			Core::integer_id ICollision::id_counter = 0;

		}
	}
}

#endif // __EObjects_Components_Collision_ICollision
