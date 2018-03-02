#ifndef __EObjects_GameObject
#define __EObjects_GameObject

#include <string>
#include <vector>
#include <map>
#include "components/icomponent.hpp"
#include "../core/typesdescription.hpp"

namespace EObjects {
    
    class GameObject {
    public:
        ~GameObject(void);
        
        // Number of uniqueID elements
        static void setElementNumber(const size_t elementNumber){
            GameObject::elementNamesList.reserve(elementNumber);
        }

        // New uniqueID element
        static GameObject* newObject(std::string i_id){
            static std::vector<std::string>::iterator el_i;
            for (el_i = GameObject::elementNamesList.begin(); el_i != GameObject::elementNamesList.end(); ++el_i)
                if ((*el_i) == i_id) return nullptr;
            
            GameObject::elementNamesList.push_back(i_id);
            return new GameObject(i_id);
        }
        
        Components::IComponent* addGOC(Components::IComponent* newComponent);
        Components::IComponent* getGOC(const std::string nameComponent);
        void clearGOCs(void);
        
        void sendMessage(std::string familyID, void* obj);
        
        GameObject* clone();
        
    private:
        GameObject(const std::string i_id);
        std::string id;
        
		// Lista de componentes que inclusos neste GameObject, cada qual com uma função específica
        typedef std::map<std::string, Components::IComponent*> ComponentTable;
        ComponentTable components;
        static std::vector<std::string> elementNamesList;
    };

}

#endif //__EObjects_GameObject
