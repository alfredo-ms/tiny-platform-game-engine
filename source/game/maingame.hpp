#ifndef __Game_MainGame
#define __Game_MainGame

#include "../appbase.hpp"
#include "playerstate.hpp"


namespace Game {

    class MainGame: public Core::IBase {
        public:
            MainGame(AppBase *base);
            ~MainGame();

            virtual std::string getComponentID(void) const { return "Game::MainGame"; };
            Core::ReturnStatus::Enum reload();
			Core::ReturnStatus::Enum loop();

        private:

            AppBase *_base;
    };
}

#endif // __Game_MainGame
