#ifndef _TPGEGOMove
#define _TPGEGOMove

#include "../igocomponent.hpp"

namespace TPGE {

    class GOMove : public IGOComponent{
    public:
        GOMove(float f_definedSpeed);
        virtual ~GOMove(void);
    
        virtual string_cname getComponentID(void) const { return "GOMove"; };
        virtual string_cname getFamilyID(void) const { return this->getComponentID(); };
    
        virtual void update(GameObject* ownerGO, void*);
    
        void setSpeed(float f_definedSpeed);
        void setTempSpeed(float f_definedTempSpeed);
        
        void setDirection(MoveDirection::Enum e_definedDirection);
        MoveDirection::Enum getDirection();
    
    private:
        float f_speed;
        float f_tempSpeed;
        MoveDirection::Enum direction;

    };

}

#endif // _TPGEGOMove
