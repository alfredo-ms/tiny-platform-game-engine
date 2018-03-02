#ifndef __Core_Utils_Time
#define __Core_Utils_Time

#include <string>
#include <ctime>


// metodos utilizados para retornar strings referentes ao horario atual
namespace Core {
    namespace Utils {

        class DataTime {
            public:
                DataTime();
                ~DataTime();

                std::string getCurrentSystemTime(const std::string format);

            private:
                std::string put_time(const std::tm* date_time, const char* c_time_format);
                tm localtime(const std::time_t& time);
                std::time_t systemtime_now();
        };

    }
}

#endif // __Core_Utils_Time
