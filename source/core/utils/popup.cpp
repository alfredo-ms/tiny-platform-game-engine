#include "popup.hpp"
#include <string>


// métodos utilizados para mostrar mensagens diversas diretamente no sistema operacional
namespace Core {
    namespace Utils {

	void ShowPopUP(Core::Graphics::Window *window_child, std::string title, std::string message, PopUP_Type::Enum type){
	    // flag padrão, para inicialização
            Uint32 flag_msbBox = SDL_MessageBoxFlags::SDL_MESSAGEBOX_ERROR;

	    switch (type) {
		case PopUP_Type::Error:
		    flag_msbBox = SDL_MessageBoxFlags::SDL_MESSAGEBOX_ERROR;
		    break;
		case PopUP_Type::Information:
		    flag_msbBox = SDL_MessageBoxFlags::SDL_MESSAGEBOX_INFORMATION;
		    break;
		case PopUP_Type::Warning:
		    flag_msbBox = SDL_MessageBoxFlags::SDL_MESSAGEBOX_WARNING;
		    break;
	    }

		if (window_child == nullptr)
		SDL_ShowSimpleMessageBox(flag_msbBox, title.c_str(), message.c_str(), NULL);
	    else
		SDL_ShowSimpleMessageBox(flag_msbBox, title.c_str(), message.c_str(), window_child->get());
	}
    }

}
