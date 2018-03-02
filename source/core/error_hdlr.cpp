#include "error_hdlr.hpp"
#include "utils/time.hpp"


// inicializa variáveis estáticas
bool Core::ErrorHandler::b_hasErrors = false;
std::ostringstream Core::ErrorHandler::errorStream(std::ostringstream::ate);


namespace Core {

    ErrorHandler::ErrorHandler(){
    }

    ErrorHandler::~ErrorHandler(){
    }

    void ErrorHandler::addErrorMessage(const std::string error_message){
        if (ErrorHandler::hasErrors() == false)
            ErrorHandler::b_hasErrors = true;

        Utils::DataTime dataObj;
        errorStream <<" * "<< dataObj.getCurrentSystemTime("%c")<<": "<<error_message<<std::endl;
    }

}
