#ifndef _TPGEGOMovePlayerInput
#define _TPGEGOMovePlayerInput

#include "gomove.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace TPGE {
    
    class GOMovePlayerInput : public GOMove{
    public:
        GOMovePlayerInput(float f_definedSpeed);
        virtual ~GOMovePlayerInput(void);
        
        virtual string_cname getComponentID(void) const { return "GOMovePlayerInput"; };
        virtual string_cname getFamilyID(void) const { return GOMove::getComponentID(); };
        
        virtual void update(GameObject* ownerGO, void*);
        
        
    private:
        std::map<sf::Event::EventType, sf::Event::KeyEvent> keyboardMapping;
        std::map<sf::Event::EventType,sf::Event::KeyEvent> joystickdMapping;
        
    };
    
}

#endif // _TPGEGOMovePlayerInput
