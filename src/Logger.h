#ifndef LOGGER_H
#define LOGGER_H
/*INCLUSIONS*/
/*FIN INCLUSIONS*/
class LogContent;
enum LogLevel
{
    LEVEL_TRACE,
    LEVEL_INFO,
    LEVEL_WARNING,
    LEVEL_ERROR,
    LEVEL_CRITICAL

};
class Logger
{
public:
    Logger(LogLevel minLevel);
    Logger(const Logger& copy);
    Logger(Logger&& moved);
    ~Logger();
    std::map<std::string,Appender*>&& Move();
private:
    /*le niveau de log minimum*/
    LogLevel _minLogLevel;
    /*les appenders*/
    std::map<std::string,Appender*> _appendersMap;
};

#endif
