#include "LogSystem.h"


LogSystem::LogSystem() : _loggersMap(), _isAsync(false)
{

}
LogSystem::LogSystem(bool async): _loggersMap(), _isAsync(async)
{

}
LogSystem::LogSystem(const LogSystem& copy) : _isAsync(copy._isAsync)
{
    std::map<std::string,Logger*>::iterator it = copy._loggersMap.begin();
    for(it;it!=copy._loggersMap.end();it++)
    {
        _loggersMap.insert(std::make_pair(it->first,new Logger(*it->second)));
    }s
}
LogSystem::LogSystem(LogSystem&& moved) : _isAsync(moved._isAsync), _loggersMap(std::move(moved.Move()))
{

}
LogSystem::~LogSystem()
{
    _isAsync = 0;
    std::map<std::string,Logger*>::iterator it = _loggersMap.begin();
    for(it;it!=_loggersMap.end();it++)
    {
        delete it->second;
    }
    _loggersMap.clear();
}
/*METHODES*/
std::map<std::string,Logger*>&& LogSystem::Move()
{
    _isAsync =0;
    return std::move(_loggersMap);
}
bool LogSystem::addLogger(Logger* logger)
{
    if(!logger)
        return false;
    _loggersMap.insert(std::make_pair(logger->getName(),logger));
    return true;
}
bool LogSystem::deleteLogger(Logger* logger)
{
    return deleteLogger(logger->getName());
}
bool LogSystem::deleteLogger(const std::string& name)
{
    std::map<std::string,Logger*>::iterator it = _loggersMap.find(name);
    if(it!=_loggersMap.end())
    {
        delete it->second;
        return true;
    }
    return false;
}
Logger* Logger::GetLogger(const std::string& name)
{
    std::map<std::string,Logger*>::iterator it = _loggersMap.find(name);
    if(it!=_loggersMap.end())
    {
        return it->second;
    }
    return nullptr;
}
void LogSystem::writeOnLogger(const std::string& name,std::unique_ptr<LogMessage>& msg)
{
    Logger* temp = GetLogger(name);
    if(!temp||!temp->shouldLogLevel(msg.getLevel()))
    {
        return;
    }
    if(_isAsync)
    {
        temp->writeAsync(msg.get());
    }
    else
        temp->write(msg.get());
}
