#ifndef COLOR_SYSTEM_H
#define COLOR_SYSTEM_H
/*
@brief systeme de coloration des log
*/
enum Color
{

};
class ColorToLevel
{
public:
    ColorToLevel()
    {
        for(int i = LogLevel::MIN_LOG_LEVEL;i<LogLevel::MAX_LOG_LEVEL;i++)
        {
            _colorsMap.insert(std::make_pair(i,COLOR));
        }
    }
private:
    std::map<LogLevel,Color> _colorsMap;
};
#endif
