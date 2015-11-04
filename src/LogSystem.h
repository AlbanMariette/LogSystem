#ifndef LOG_SYSTEM_H
#define LOG_SYSTEM_H
/*INCLUSIONS*/
#include <map>
#include "Logger.h"
/*FIN INCLUSIONS*/
class LogSystem
{
public:
    /*CONSTRUCTEURS DESTRUCTEURS*/
    LogSystem();
    LogSystem(bool async);
    LogSystem(const LogSystem& copy);
    LogSystem(LogSystem&& moved);
    ~LogSystem();
    /*METHODES*/
    std::map<std::string,Logger*>&& Move();
    bool addLogger(Logger* logger);
    bool deleteLogger(Logger* logger);
    bool deleteLogger(std::string& name);
    /*ECRITURE*/
    template <class ... Args>
    void trace(std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_TRACE,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void warning(std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_WARNING,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void info(std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_INFO,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void error(std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_ERROR,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void critical(std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_CRITICAL,std::forward<Args>(args)...);
    }
private:
    /*ecriture generale*/
    template <class ... Args>
    void write(std::string& name,LogLevel& level,Args &&... args)
    {
        cout << "Inmpression de " << sizeof...(Args) << " parametres: ";
        std::ostringstream stream;
		print(stream, std::forward<Args>(args)...);
        std::unique_ptr<LogContent> msg(new LogContent(level,stream));
    }
    template <class T, class ... Args>
    void print(std::ostringstream& stream,const T & val,const Args &... args)
    {
      stream<<val;
      print(stream,std::forward<Args>(args)...);
    }
	template <class T>
	void print(std::ostringstream& stream,const T & val)
	{
		stream <<val;
	}
    /*map contenant les loggers classés selon leur nom*/
    std::map<std::string,Logger*> _loggersMap;

};

#endif
