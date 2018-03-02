#include "time.hpp"
#include <chrono>

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
#include <sstream>
#include <iomanip>
#endif

typedef std::chrono::time_point<std::chrono::system_clock>  system_time_point;


// metodos utilizados para retornar strings referentes ao horario atual
namespace Core {
    namespace Utils {
        DataTime::DataTime(){
        }

        DataTime::~DataTime(){
        }

        std::string DataTime::getCurrentSystemTime(std::string format){
            std::tm time = localtime(systemtime_now());
            return put_time(&time,  format.c_str());
        }

        // retorna a variável time (tm) para qualquer plataforma
        tm DataTime::localtime(const std::time_t& time)
        {
            std::tm tm_snapshot;
            #if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
            localtime_s(&tm_snapshot, &time);
            #else
            localtime_r(&time, &tm_snapshot); // POSIX 
            #endif
            return tm_snapshot;
        }


        // para simplificar as coisas, o valor de retorno é somente uma string
        std::string DataTime::put_time(const std::tm* date_time, const char* c_time_format)
        {
            #if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
            std::ostringstream oss;

            // hack FALSO feito para VS2012: fora do padrão C++11 pois é NECESSÁRIO um "const struct tm*  "
            // ref.: C++11 standard: ISO/IEC 14882:2011, § 27.7.1,
            oss << std::put_time(const_cast<std::tm*>(date_time), c_time_format);
            return oss.str();

            #else    // LINUX
            const size_t size = 1024;
            char buffer[size];
            auto success = std::strftime(buffer, size, c_time_format, date_time);

            if (0 == success)
                return c_time_format;

            return buffer;
            #endif
        }

        // extrai std::time_t de std:chrono para "now"
        std::time_t DataTime::systemtime_now(){
            system_time_point system_now = std::chrono::system_clock::now();
            return std::chrono::system_clock::to_time_t(system_now);
        }

    }
}

