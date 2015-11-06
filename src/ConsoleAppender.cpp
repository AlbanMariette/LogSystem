#include "ConsoleAppender.h"

ConsoleAppender(const std::string& name, LogLevel level) : Appender(name,level)
{

}
ConsoleAppender(const ConsoleAppender& copy) : Appender(copy._name,copy.minLogLevel)
{

}
ConsoleAppender(ConsoleAppender&& moved)
{
    //TODO : implementer
}
virtual void write(LogContent& content)
{
    std::cout<<content.getContent()<<std::endl;
}
