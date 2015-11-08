#include "Appender.h"
#include "Logger.h"
#include "LogContent.h"

Appender::Appender(const std::string& name, LogLevel level) : _name(name), _minLogLevel(level)
{

}

Appender::Appender(const Appender& copy) : _minLogLevel(copy._minLogLevel)
{

}

Appender::Appender(Appender&& moved) : _minLogLevel(moved._minLogLevel)
{

}

Appender::~Appender()
{

}

bool Appender::shouldLogLevel(LogLevel levelToLog)
{
    if(levelToLog<_minLogLevel)
    {
        return false;
    }
    return true;
}

const std::string& Appender::getName() const
{
    return _name;
}
const AppenderType& Appender::getType() const
{
	return _appenderType;
}