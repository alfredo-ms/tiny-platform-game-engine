#ifndef __Core_Utils_PopUP
#define __Core_Utils_PopUP

#include "../typesdescription.hpp"
#include "..//graphics/window.hpp"


// métodos utilizados para mostrar mensagens diversas diretamente no sistema operacional
namespace Core {
    namespace Utils {
        namespace PopUP_Type {
            enum Enum{
                Error,
                Warning,
                Information,
            };
        }

        void ShowPopUP(Core::Graphics::Window *window_child, std::string title, std::string message, PopUP_Type::Enum type);

    }
}

#endif // __Core_Utils_PopUP
