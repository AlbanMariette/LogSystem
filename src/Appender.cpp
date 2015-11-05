#include "Appender.h"
#include "Logger.h"
#include "LogContent.h"

Appender::Appender(LogLevel level) : _minLogLevel(level)
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
    if(levelToTest<_minLogLevel)
    {
        return false;
    }
    return true;
}
