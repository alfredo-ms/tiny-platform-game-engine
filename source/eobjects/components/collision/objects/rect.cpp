#include "rect.hpp"


namespace EObjects {
	namespace Components {
		namespace Collision {
			namespace Objects {

				Rect::Rect(){
				};

				Rect::~Rect(){
				};

				void Rect::setType(Core::Collision::Type::Enum type){
					_type = type;
				}
				
				void Rect::setDepth(Core::Collision::Depth::Enum depth){
					_depth = depth;
				}

				bool Rect::intersect(IObject *obj){
					bool collided = false;
					switch (obj->getType()) {
						case Core::Collision::Type::Rect:
							Rect *rect02 = reinterpret_cast<Rect*>(obj);
							collided = IObject::intersect(&_rect, rect02->getRect());
							break;
					}

					return collided;
				}
				
				void Rect::copyRect(SDL_Rect *rect){
					_rect.x = rect->x;
					_rect.y = rect->y;
					_rect.w = rect->w;
					_rect.h = rect->h;
				}

				void Rect::setX(int x){
					_rect.x = x;
				}

				void Rect::setY(int y){
					_rect.y = y;
				}

				void Rect::setW(int w){
					_rect.w = w;
				}

				void Rect::setH(int h){
					_rect.h = h;
				}

				SDL_Rect* Rect::getRect(){
					return &_rect;
				}

				int Rect::getX(){
					return _rect.x;
				}

				int Rect::getY(){
					return _rect.y;
				}

				int Rect::getW(){
					return _rect.w;
				}

				int Rect::getH(){
					return _rect.h;
				}

				
			}
		}
	}
}

