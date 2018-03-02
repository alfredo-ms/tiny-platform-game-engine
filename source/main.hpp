#ifndef __Main
#define __Main

#include "appbase.hpp"

class Main {
    public:
        Main();
        ~Main();

        Core::ReturnStatus::Enum init();
        int run();

    private:
		AppBase *base;
};

#endif // __Main
