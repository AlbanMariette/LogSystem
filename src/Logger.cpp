#include <future>
#include "Logger.h"
#include "LogContent.h"
#include "ConsoleAppender.h"

Logger::Logger(const std::string& name, LogLevel minLevel) : _name(name), _minLogLevel(minLevel)
{

}
Logger::Logger(const Logger& copy) : _name(copy._name), _minLogLevel(copy._minLogLevel)
{
    // for each appender in map do a copy of the object behind the pointer
    //because just copy the map will cause failure due to pointer
    std::map<std::string,Appender*>::const_iterator it = copy._appendersMap.begin();
    for(it;it!=copy._appendersMap.end();it++)
    {
		if (it->second->getType() == AppenderType::CONSOLE_APPENDER)
		{
			_appendersMap.insert(std::make_pair(it->first, new ConsoleAppender(dynamic_cast<ConsoleAppender&>(*it->second))));
		}
        
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
    return std::move(_appendersMap);
}
bool Logger::addAppender(Appender* appender)
{
    if(!appender)
        return false;
    _appendersMap.insert(std::make_pair(appender->getName(),appender));
    return true;
}
bool Logger::delAppender(Appender* appender)
{
    return delAppender(appender->getName());
}
bool Logger::delAppender(const std::string& name)
{
    std::map<std::string,Appender*>::iterator it = _appendersMap.find(name);
    if(it!=_appendersMap.end())
    {
        delete it->second;
        return true;
    }
    return false;
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
    for(std::map<std::string,Appender*>::iterator it = _appendersMap.begin();it!=_appendersMap.end();it++)
    {
        if(it->second->shouldLogLevel(content.getLevel()))
        {
            it->second->write(content);
        }
    }
}
void Logger::writeAsync(LogContent& content)
{
    std::async(&Logger::write,this,content);
}
