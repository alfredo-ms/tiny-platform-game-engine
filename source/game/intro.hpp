#ifndef __Game_Intro
#define __Game_Intro

#include "../appbase.hpp"


namespace Game {

    class Intro: public Core::IBase {
        public:
            Intro();
            ~Intro();

            virtual std::string getComponentID(void) const { return "Game::Intro"; };
            Core::ReturnStatus::Enum load();
    };
}

#endif // __Game_Intro
