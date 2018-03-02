#include "position.hpp"

namespace EObjects {
    namespace Components {

		Position::Position(){ 
			_rect.x = 0;
			_rect.y = 0;
			_rect.w = 0;
			_rect.h = 0;
		}
		
		Position::~Position(){};

		int Position::getX() {
			return _rect.x;
		}
		
		void Position::setX(int x) {
			_rect.x = x;
		}

		int Position::getY() { 
			return _rect.y;
		}
		
		void Position::setY(int y) { 
			_rect.y = y;
		}

		int Position::getW(){
			return _rect.w;
		}

		void Position::setW(int w){
			_rect.w = w;
		}
		
		int Position::getH(){
			return _rect.h;
		}

		void Position::setH(int h){
			_rect.h = h;
		}
		
		void Position::setRect(SDL_Rect rect){
			_rect = rect;
		}
		
		SDL_Rect* Position::getRect(){
			return &_rect;
		}


		void Position::update(void) {
		}
	}
}
