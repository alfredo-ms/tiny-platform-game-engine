#include "simplecollision.hpp"


namespace EObjects {
	namespace Components {
		namespace Collision {

			SimpleCollision::SimpleCollision(){
				_object = nullptr;
			}

			SimpleCollision::SimpleCollision(SimpleCollision *template_obj){
				_object = nullptr;
			}

			SimpleCollision::~SimpleCollision(){
				if (_template == false)
					ICollision::id_counter--;
			}

			SimpleCollision::ICollision* SimpleCollision::getInstance(){
				SimpleCollision *newObj = new SimpleCollision();
				newObj->_template = false;

				return newObj;
			}

			ICollision* SimpleCollision::getInstance(ICollision *template_obj){
				SimpleCollision *newObj = new SimpleCollision();
				newObj->_template = false;

				return newObj;
			}

			ICollision* SimpleCollision::getTemplate(){
				SimpleCollision *newObj = new SimpleCollision();
				newObj->_template = true;

				return newObj;
			}

			void SimpleCollision::update(void){
				if (isActive() == false)
					return;



			}
			
			std::vector<Objects::IObject*>* SimpleCollision::getCurrentObjects(){
				return nullptr;
			}

			Objects::IObject* SimpleCollision::firstObject(){
				return _object;
			}

			Objects::IObject* SimpleCollision::nextObject(){
				return nullptr;
			}

			Objects::IObject* SimpleCollision::addObject(Objects::IObject *object){
				Objects::IObject *old_object = _object;
				_object = object;
				
				return old_object;
			}

		}
	}
}
