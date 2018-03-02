#ifndef _TPGEGOAnimation
#define _TPGEGOAnimation

#include "goimagecollection.hpp"
#include "goanimation_data.hpp"


namespace TPGE {
    
    class GOAnimation : public GOImageCollection {
    public:
        GOAnimation(BaseObject::Image* loaded_image, GameObject* e_ownerGO);
        ~GOAnimation();
        
        
        // Here, void is a pointer to sf::RenderWindow
        virtual void update(GameObject* ownerGO, void*);
        
        virtual string_cname getComponentID(void) const { return "GOAnimation"; };
        virtual string_cname getFamilyID(void) const { return GOImageHandler::getFamilyID(); };
        
        void setAnimation(string_cname str_animation);
        void clearAnimationList();
        void addAnimation(string_cname str_animation, BaseObject::Animation::Sequence as_sequence);
        BaseObject::Animation::Sequence& getAnimation(string_cname str_animation);
        
        inline string_cname& getCurrentAnimationName(){ return this->s_selectedAnimation; };
        inline BaseObject::Animation::Sequence& getCurrentAnimation(){ return this->listAnimationSequence[getCurrentAnimationName()]; };
        
        void play();
        
    private:
        typedef std::map<std::string, BaseObject::Animation::Sequence> ListAnimationSequence;
        ListAnimationSequence listAnimationSequence;
        
        std::string s_selectedAnimation;
        sf::Clock clock;
        
        position_type temp_positionUpdate;

    };
    
    
}

#endif // _TPGEGOAnimation