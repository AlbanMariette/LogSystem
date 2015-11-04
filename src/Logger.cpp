#include "Logger.h"

Logger::Logger(LogLevel minLevel) : _minLogLevel(minLevel)
{

}
Logger::Logger(const Logger& copy) : _minLogLevel(copy._minLogLevel)
{
    //TODO : for each appender in map do a copy of the object behind the pointer
    //because just copy the map will cause failure due to pointer
}
Logger::Logger(Logger&& moved) : _minLogLevel(moved._minLogLevel), _appendersMap(std::move(moved.Move()))
{

}
Logger::~Logger()
{
    //clear the map properly
    std::map<std::string,Appender*>::iterator it = _appendersMap.begin();
    for(it;it!=_appendersMap.end();it++)
    {
        delete it->second;
    }
    _appendersMap.clear();
}
std::map<std::string,Appender*>&& Logger::Move()
{
    _minLogLevel = 0;
    return std::move(_appendersMap);
}
