#include "gomove.hpp"

namespace TPGE {

    GOMove::GOMove(float f_definedSpeed){
        setSpeed(f_definedSpeed);
        setTempSpeed(f_definedSpeed);
        setDirection(MoveDirection::Stand);
    }
    
    GOMove::~GOMove(){
    }
    
    void GOMove::update(GameObject* go, void* temp){
        return;
    }

    void GOMove::setSpeed(float f_definedSpeed){
        this->f_speed = f_definedSpeed;
    }
    
    void GOMove::setTempSpeed(float f_definedTempSpeed){
        this->f_tempSpeed = f_definedTempSpeed;
    }
    
    void GOMove::setDirection(MoveDirection::Enum e_definedDirection){
        this->direction = e_definedDirection;
    }
    
    MoveDirection::Enum GOMove::getDirection(){
        return this->direction;
    }
    
}
