#include "goanimation_data.hpp"


namespace TPGE {
    
    namespace BaseObject {
    
        namespace Animation {
        
            // Nested class methods
            
            Sequence::Sequence(){
                _init();
            }
            
            Sequence::Sequence(integer_id framesNumber){
                _init();
                setFrameCount(framesNumber);
            }
            
            void Sequence::_init(){
                this->i_maxFrames = 0;
                this->i_maxWidth = 0;
                this->i_maxHeight = 0;
                setCurrentFrame(0);
            }
            
            Sequence::~Sequence(){
                clear();
            }
            
            void Sequence::addFrame(Frame frameSequence, sf::IntRect &frameRect){
                frame_list.push_back(frameSequence);
                this->i_maxFrames++;
                
                if (maxFrameWidth() < frameRect.width)
                    this->i_maxWidth = frameRect.width;
                
                if (maxFrameHeight() < frameRect.height)
                    this->i_maxHeight = frameRect.height;
            }
            
            void Sequence::clear(){
                this->frame_list.clear();
            }
            
            void Sequence::next(){
                this->it_frameSequence++;
                if (this->it_frameSequence == this->frame_list.end()){
                    begin();
                }else{
                    setCurrentFrame(this->it_frameSequence->getFrameID());
                }
            }
            
            void Sequence::begin(){
                this->it_frameSequence = this->frame_list.begin();
                setCurrentFrame(0);
            }
            
            
            void Sequence::setFrameCount(integer_id framesNumber){
                frame_list.reserve(framesNumber);
            };

        }
        
    }
    
}