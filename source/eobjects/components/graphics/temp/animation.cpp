#include "goanimation.hpp"

namespace TPGE {
    
    GOAnimation::GOAnimation(BaseObject::Image* loaded_image, GameObject* e_ownerGO)
    : GOImageCollection(loaded_image, e_ownerGO){
        this->s_selectedAnimation = "";
    };
    
    GOAnimation::~GOAnimation(){
        clearAnimationList();
    }
    
    void GOAnimation::update(GameObject* ownerGO, void* temp){
        
        // Set in the object the current image defined in this animation.
        GOImageCollection::setImagePositionByID(this->listAnimationSequence[getCurrentAnimationName()].getSelectedFrame().getImageID());
        
        switch (getSpriteDirection()) {
            case ImageDirection::Right:
                this->image->draw(ownerGO, getImagePosition(getImagePositionID()));
                break;
                
            case ImageDirection::Left:
                this->temp_positionUpdate.x = getCurrentAnimation().maxFrameWidth()-getImagePosition(getImagePositionID()).width;
                this->temp_positionUpdate.y = 0;
                this->image->draw(ownerGO, this->temp_positionUpdate, sf::IntRect(getImagePosition(getImagePositionID()).left+getImagePosition(getImagePositionID()).width, getImagePosition(getImagePositionID()).top, -getImagePosition(getImagePositionID()).width, getImagePosition(getImagePositionID()).height));
                break;
                
            case ImageDirection::Up:
                break;
                
            case ImageDirection::Down:
                break;
        }
        
        play();
    }
    
    void GOAnimation::clearAnimationList(){
        for (ListAnimationSequence::iterator iteratorAnimationSequence = this->listAnimationSequence.begin(); iteratorAnimationSequence != this->listAnimationSequence.end(); ++iteratorAnimationSequence){
            iteratorAnimationSequence->second.clear();
            listAnimationSequence.erase(iteratorAnimationSequence->first);
        }
    }
    
    void GOAnimation::setAnimation(string_cname str_animation){
        this->s_selectedAnimation = str_animation;
        this->listAnimationSequence[str_animation].begin();
        this->listAnimationSequence[str_animation].setCurrentFrame(this->listAnimationSequence[str_animation].getSelectedFrame().getFrameID());
    }
    
    void GOAnimation::play(){
        if (this->listAnimationSequence[getCurrentAnimationName()].getSelectedFrame().getMilliseconds() < this->clock.getElapsedTime().asMilliseconds()){
            listAnimationSequence[getCurrentAnimationName()].next();
            this->clock.restart();
        }
    }
    
    void GOAnimation::addAnimation(string_cname str_animation, BaseObject::Animation::Sequence as_sequence){
        this->listAnimationSequence.insert(std::make_pair(str_animation, as_sequence));
    }
    
    BaseObject::Animation::Sequence& GOAnimation::getAnimation(string_cname str_animation){
        return this->listAnimationSequence[str_animation];
    }
    
}
