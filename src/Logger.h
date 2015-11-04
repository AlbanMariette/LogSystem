#ifndef LOGGER_H
#define LOGGER_H
/*INCLUSIONS*/
/*FIN INCLUSIONS*/
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
    Logger();
    Logger(const Logger& copy);
    Logger(Logger&& moved);
    ~Logger();
    std::map<std::string,Appender*>&& Move();
private:
    /*les appenders*/
    std::map<std::string,Appender*> _appendersMap;
};

#endif
