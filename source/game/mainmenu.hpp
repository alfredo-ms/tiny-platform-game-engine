#ifndef __Game_MainMenu
#define __Game_MainMenu

#include "../appbase.hpp"


namespace Game {

    class MainMenu: public Core::IBase {
        public:
            MainMenu();
            ~MainMenu();

            virtual std::string getComponentID(void) const { return "Game::MainMenu"; };
            Core::ReturnStatus::Enum load();
    };
}

#endif // __Game_MainMenu
