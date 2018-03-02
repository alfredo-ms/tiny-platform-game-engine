#ifndef __EObjects_Components_IComponent
#define __EObjects_Components_IComponent

#include <string>
#include "../../core/typesdescription.hpp"
#include "../../core/ibase.hpp"


namespace EObjects {
    
    class GameObject;
    namespace Components {

		class IComponent : Core::IBase {
		public:
			IComponent(){ _owner = nullptr; };
			virtual ~IComponent(){};
        
			virtual std::string getComponentID(void) const = 0;
			virtual std::string getFamilyID(void) const = 0;

			void setOwner(EObjects::GameObject *owner){ _owner = owner; };
			EObjects::GameObject* getOwner(){ return _owner; };
        
			virtual void update(void) = 0;
        
		private:
			EObjects::GameObject *_owner;
		};

	}
}
    
#endif // __EObjects_Components_IComponent