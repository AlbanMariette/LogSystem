#include "Logger.h"
#include "LogContent.h"
#include "Appender.h"
Logger::Logger(const std::string& name, LogLevel minLevel) : _name(name), _minLogLevel(minLevel)
{

}
Logger::Logger(const Logger& copy) : _name(copy._name), _minLogLevel(copy._minLogLevel)
{
    // for each appender in map do a copy of the object behind the pointer
    //because just copy the map will cause failure due to pointer
    std::map<std::string,Appender*>::iterator it = copy._appendersMap.begin();
    for(it;it!=copy._appendersMap.end();it++)
    {
        _appendersMap.insert(std::make_pair(it->first,new Appender(*it->second)));
    }
}
Logger::Logger(Logger&& moved) : _name(moved._name), _minLogLevel(moved._minLogLevel), _appendersMap(std::move(moved.Move()))
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
    _name = "";
    _minLogLevel = 0;
    return std::move(_appendersMap);
}
bool Logger::shouldLogLevel(const LogLevel& levelToTest)
{
    if(levelToTest<_minLogLevel)
    {
        return false;
    }
    return true;
}
const std::string& Logger::getName()
{
    return _name;
}
void Logger::write(LogContent& content)
{
    for(AppenderMap::iterator it = _appenders.begin();it!=_appenders.end();it++)
    {
        if(it->second->shouldLogLevel(content.getLevel()))
        {
            it->second->Write(msg);
        }
    }
}
