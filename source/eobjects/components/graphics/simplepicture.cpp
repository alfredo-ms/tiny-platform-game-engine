#include "simplepicture.hpp"
#include "../../gameobject.hpp"
#include "../position.hpp"


namespace EObjects {
	namespace Components {
		namespace Graphics {

			SimplePicture::SimplePicture(Collections::Images::ImageCollection *imageCollection, Core::integer_id id){
				setImageCollection(imageCollection);
				changeID(id);
			}

			SimplePicture::~SimplePicture(){
			}

			void SimplePicture::update(){
				EObjects::Components::Position *position = static_cast<EObjects::Components::Position *>(getOwner()->getGOC("EObjects::Components::Position"));
				_imageCollection->draw(_id, position->getX(), position->getY());
			}

			Core::Layer::Enum SimplePicture::getLayer(){
				return _layer;
			}

			void SimplePicture::setLayer(Core::Layer::Enum layer){
				_layer = layer;
			}

			void SimplePicture::changeID(Core::integer_id id){
				_id = id;
			}

			void SimplePicture::setImageCollection(Collections::Images::ImageCollection *imageCollection){
				_imageCollection = imageCollection;
			}

		}
	}
}