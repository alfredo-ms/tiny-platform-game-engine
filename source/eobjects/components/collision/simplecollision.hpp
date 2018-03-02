#ifndef __EObjects_Components_Collision_SimpleCollision
#define __EObjects_Components_Collision_SimpleCollision

#include "icollision.hpp"


namespace EObjects {
	namespace Components {
		namespace Collision {
			class SimpleCollision : public ICollision {
			public:
				static ICollision* getInstance();
				static ICollision* getInstance(ICollision *template_obj);
				static ICollision* getTemplate();

				virtual std::string getComponentID(void) const { return "EObjects::Components::Collision::SimpleCollision"; };

				virtual void update(void);
				virtual std::vector<Objects::IObject*>* getCurrentObjects();
				virtual Objects::IObject* firstObject();
				virtual Objects::IObject* nextObject();

				Objects::IObject* addObject(Objects::IObject *object);

			private:
				SimpleCollision();
				SimpleCollision(SimpleCollision *template_obj);
				~SimpleCollision();
				bool _template;
				Objects::IObject *_object;
			};
		}
	}
}

#endif // __EObjects_Components_Collision_SimpleCollision
