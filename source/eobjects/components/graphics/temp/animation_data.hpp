#ifndef _TPGEGOAnimation_Data
#define _TPGEGOAnimation_Data

#include "../igobaseobject.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace TPGE {
    
    namespace BaseObject {
        
        namespace Animation {
            
            class Frame : IGOBaseObject {
            public:
                Frame(integer_id i_definedFrameID, integer_id i_definedImageID, integer_id i_definedMilliseconds){
                    setFrameID(i_definedFrameID);
                    setImageID(i_definedImageID);
                    setMilliseconds(i_definedMilliseconds);
                };
                ~Frame(){};
                
                string_cname getComponentID(void) const { return "Animation::Frame"; };
                string_cname getFamilyID(void) const { return IGOBaseObject::getFamilyID(); };
                
                inline void setFrameID(integer_id i_definedFrameID){ this->frame_id = i_definedFrameID; };
                inline void setImageID(integer_id i_definedImageID){ this->image_id = i_definedImageID; };
                inline void setMilliseconds(integer_id i_definedMilliseconds){ this->milliseconds = i_definedMilliseconds; };
                inline void setSpeed(float f_definedSpeed){ this->speed = f_definedSpeed; };
                
                inline integer_id getImageID(){ return this->image_id; };
                inline integer_id getFrameID(){ return this->frame_id; };
                inline integer_id getMilliseconds(){ return milliseconds; };
                inline float getSpeed(){ return speed; };
                
            private:
                integer_id image_id;
                integer_id frame_id;
                integer_id milliseconds;
                float speed;
            };

            
            class Sequence : IGOBaseObject {
            public:
                Sequence();
                Sequence(integer_id framesNumber);
                
                string_cname getComponentID(void) const { return "Animation::Sequence"; };
                string_cname getFamilyID(void) const { return IGOBaseObject::getFamilyID(); };
                
                ~Sequence();
                
                                
                inline int& maxFrameWidth(){ return this->i_maxWidth; };
                inline int& maxFrameHeight(){ return this->i_maxHeight; };
                
                void setFrameCount(integer_id framesNumber);
                void addFrame(Frame frameSequence, sf::IntRect& frameRect);
                inline void setCurrentFrame(integer_id id_frame){ this->i_selectedFrame = id_frame; };
                inline Frame& getSelectedFrame(){ return this->frame_list[this->i_selectedFrame]; };
                
                void clear();
                void next();
                void begin();
                
            private:
                std::vector<Frame>::iterator it_frameSequence;
                std::vector<Frame> frame_list;
                
                int i_maxWidth;
                int i_maxHeight;
                integer_id i_selectedFrame;
                integer_id i_maxFrames;
                
                void _init();
            };
        }
    }
}

#endif // _TPGEGOAnimation_Data
