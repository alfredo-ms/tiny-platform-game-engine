#include "playerstate.hpp"


namespace Game {

    PlayerState::PlayerState(){
		setArea("");
		setEvent(Core::Event::Type::Map, "");
		setGameState(Core::GameState::Enum::Intro);
    }

    PlayerState::~PlayerState(){
    }

    Core::ReturnStatus::Enum PlayerState::load(){
		setGameState(Core::GameState::MainGame);
		setArea("resources/areas/area001.xml");
		setEvent(Core::Event::Type::Map, "map0001");

        return Core::ReturnStatus::Success;
    }

	Core::ReturnStatus::Enum PlayerState::load(std::string file){
		return Core::ReturnStatus::Success;
	}

    Core::GameState::Enum PlayerState::gameState(){
        return _gameState;
    }

    void PlayerState::setGameState(Core::GameState::Enum gameState){
        _gameState = gameState;
    }

	void PlayerState::setEvent(Core::Event::Type::Enum type, std::string event){
		_event = event;
		_eventType = type;
	}

	std::string PlayerState::getEvent(){
		return _event;
	}

	Core::Event::Type::Enum PlayerState::getEventType(){
		return _eventType;
	}

	void PlayerState::setArea(std::string area){
		_area = area;
	}

	std::string PlayerState::getArea(){
		return _area;
	}


}
