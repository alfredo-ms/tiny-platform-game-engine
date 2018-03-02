#include "appbase.hpp"
#include <iostream>


AppBase::AppBase(){
	playerState.setGameState(Core::GameState::Intro);
	imgSupport = Core::Graphics::ImageTypeSupport::getInstance();
}

AppBase::~AppBase(){
    getInstance()->close();
}

Core::ReturnStatus::Enum AppBase::init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        getInstance()->addErrorMessage(SDL_GetError());
        return Core::ReturnStatus::Failed;
    }

    return Core::ReturnStatus::Success;
}

void AppBase::close(){
	imgSupport->stop();
	SDL_Quit();
}

int AppBase::showCursor(bool show){
	if (show == true)
		return SDL_ShowCursor(1);
	else
		return SDL_ShowCursor(0);
}

AppBase *AppBase::getInstance(){
	static AppBase _instance = AppBase();
	return &_instance;

}
