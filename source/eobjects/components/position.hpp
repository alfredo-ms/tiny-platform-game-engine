#ifndef __EObjects_Components_Position
#define __EObjects_Components_Position

#include "icomponent.hpp"

namespace EObjects {
    
    namespace Components {

		class Position : public IComponent {
		public:
			Position();
			~Position();
        
			virtual std::string getComponentID(void) const { return "EObjects::Components::Position"; };
			std::string getFamilyID(void) const { return "EObjects::Components::Position"; };
			int getX();
			void setX(int x);
			int getY();
			void setY(int y);
			int getW();
			void setW(int w);
			int getH();
			void setH(int h);
			void setRect(SDL_Rect rect);
			SDL_Rect* getRect();

			virtual void update(void);
        
		private:
			SDL_Rect _rect;
		};

	}
}
    
#endif // __EObjects_Components_Position