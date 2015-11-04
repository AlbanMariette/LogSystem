#ifndef LOG_CONTENT_H
#define LOG_CONTENT_H
/*INCLUSIONS*/
#include <string>
#include "Logger.h"
/*FIN INCLUSIONS*/
class LogContent
{
public:
    LogContent(std::string& level);
    LogContent(const LogContent& copy);
    LogContent(LogContent&& moved);
    ~LogContent();
    std::string&& Move();
    const LogLevel& getLevel() const;
    const std::string& getContent() const;
private:
    /*le niveau de log*/
    LogLevel _logLevel;
    std::string _content;
};
#endif
