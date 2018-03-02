#ifndef __EObjects_Components_Collision_Objects_Rect
#define __EObjects_Components_Collision_Objects_Rect

#include "iobject.hpp"


namespace EObjects {
	namespace Components {
		namespace Collision {
			namespace Objects {

				class Rect : public IObject {
				public:
					Rect();
					virtual ~Rect(void);

					virtual std::string getComponentID(void) const { return "EObjects::Components::Collision::Objects::Rect"; };

					virtual void setType(Core::Collision::Type::Enum type);
					virtual void setDepth(Core::Collision::Depth::Enum depth);

					virtual bool intersect(IObject *obj);

					void copyRect(SDL_Rect *rect);
					void setX(int x);
					void setY(int y);
					void setW(int w);
					void setH(int h);
					SDL_Rect* getRect();
					int getX();
					int getY();
					int getW();
					int getH();


				private:
					SDL_Rect _rect;
				};
			}
		}
	}
}

#endif // __EObjects_Components_Collision_Objects_Rect
