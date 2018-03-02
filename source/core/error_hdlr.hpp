#ifndef __Core_ErrorHandler
#define __Core_ErrorHandler

#include "typesdescription.hpp"
#include <sstream>
#include <fstream>


// classe utilizada para o tratamento de erros
namespace Core {

    class ErrorHandler {
        public:
            ErrorHandler();
            virtual ~ErrorHandler();

            static void errorOutput(){
                if (ErrorHandler::hasErrors() == true){
                    errorStream <<" * errorOutput called *************************************************************** "<<std::endl;
                    createFile_ErrorList();
                }
            }

            static bool hasErrors(){
                return b_hasErrors;
            }

        protected:
            void addErrorMessage(std::string error_message);

        private:
            static void createFile_ErrorList(){
                if (ErrorHandler::hasErrors() == true){
                    std::ofstream file;
                    file.open(__ERRORLOG_FILE_NAME, std::ios::out | std::ios::binary | std::ios::app);
                    file << errorStream.str();
                    file.close();
                }
            }

            // variables
            static bool b_hasErrors;
            static std::ostringstream errorStream;

    };
}

#endif // __Core_ErrorHandler
