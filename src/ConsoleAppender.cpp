#include "ConsoleAppender.h"
#include "Logger.h"
#include "LogContent.h"
#include <iostream>
ConsoleAppender::ConsoleAppender(const std::string& name, LogLevel level) : Appender(name, level)
{
	_appenderType = AppenderType::CONSOLE_APPENDER;
}
ConsoleAppender::ConsoleAppender(const ConsoleAppender& copy) : Appender(copy._name, copy._minLogLevel)
{

}
void ConsoleAppender::write(LogContent& content)
{
    std::cout<<content.getContent()<<std::endl;
}
