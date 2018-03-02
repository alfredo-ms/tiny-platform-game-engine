#ifndef __Game_PlayerState
#define __Game_PlayerState

#include "../core/ibase.hpp"


namespace Game {

    class PlayerState: public Core::IBase {
        public:
            PlayerState();
            ~PlayerState();

            virtual std::string getComponentID(void) const { return "Game::PlayerState"; };
            Core::ReturnStatus::Enum load();
			Core::ReturnStatus::Enum load(std::string file);
            Core::GameState::Enum gameState();
            void setGameState(Core::GameState::Enum gameState);
			void setEvent(Core::Event::Type::Enum type, std::string event);
			std::string getEvent();
			Core::Event::Type::Enum getEventType();
			void setArea(std::string area);
			std::string getArea();

        private:
            Core::GameState::Enum _gameState;
			std::string _event;
			Core::Event::Type::Enum _eventType;
			std::string _area;
    };
}

#endif // __Game_PlayerState
