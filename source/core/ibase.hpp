#ifndef __Core_IBase
#define __Core_IBase

#include "error_hdlr.hpp"


// classe utilizada para o tratamento de exceptions
namespace Core {

    class IBase: public ErrorHandler {
        public:
            IBase();
            ~IBase();

            virtual std::string getComponentID(void) const = 0;

    };
}

#endif // __Core_IBase
