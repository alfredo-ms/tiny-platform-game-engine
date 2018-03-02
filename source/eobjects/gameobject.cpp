#include "gameobject.hpp"

// Initialize static variables
std::vector<std::string> EObjects::GameObject::elementNamesList = std::vector<std::string>();

namespace EObjects {

    GameObject::GameObject(const std::string i_id){
        this->id = i_id;
    }

    GameObject::~GameObject(){
        this->clearGOCs();
    }
    
    Components::IComponent *GameObject::addGOC(Components::IComponent* newComponent){
        ComponentTable::iterator tgoIterator = this->components.find(newComponent->getFamilyID());
    
        Components::IComponent *oldComponent = nullptr;
    
        if (tgoIterator != this->components.end()){
            oldComponent = tgoIterator->second;
            components.erase(newComponent->getFamilyID());
        }
    
        this->components[newComponent->getFamilyID()] = newComponent;
        //newComponent->setOwnerGO(this);
    
        return oldComponent;
    }

    Components::IComponent *GameObject::getGOC(std::string nameComponent){
        ComponentTable::iterator tgoIterator = components.find(nameComponent);    
        return tgoIterator == components.end() ? nullptr : tgoIterator->second;
    }

    void GameObject::clearGOCs(void){
        for (ComponentTable::iterator tgoIterator = components.begin(); tgoIterator != components.end(); ++tgoIterator){
            delete tgoIterator->second;
        }
    
        components.clear();
    }
    
    void GameObject::sendMessage(std::string familyID, void* obj){
//        this->components[familyID]->update(obj);
    }
    
    GameObject* GameObject::clone(){
        GameObject *newGO = new GameObject(this->id);
        newGO->components = this->components;
        return newGO;
    }

}
