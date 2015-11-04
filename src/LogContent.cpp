#include "LogContent.cpp"
LogContent::LogContent(std::string& level) : _logLevel(level)
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
    _logLevel = 0;
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
