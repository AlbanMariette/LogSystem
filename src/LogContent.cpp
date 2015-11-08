#include "LogContent.h"
LogContent::LogContent(LogLevel level, std::string& content) : _logLevel(level), _content(content)
{
}
LogContent::LogContent(const LogContent& copy) : _logLevel(copy._logLevel), _content(copy._content)
{

}
LogContent::LogContent(LogContent&& moved) :_logLevel(moved._logLevel), _content(std::move(moved.Move()))
{

}
LogContent::~LogContent()
{

}
std::string&& LogContent::Move()
{
    return std::move(_content);
}
const LogLevel& LogContent::getLevel() const
{
    return _logLevel;
}
const std::string& LogContent::getContent() const
{
    return _content;
}
