#ifndef LOG_SYSTEM_H
#define LOG_SYSTEM_H
/*INCLUSIONS*/
#include <map>
#include <memory>
#include <sstream>
#include "Logger.h"
#include "LogContent.h"
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
    bool deleteLogger(const std::string& name);
    /*ECRITURE*/
    template <class ... Args>
    void trace(const std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_TRACE,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void warning(const std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_WARNING,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void info(const std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_INFO,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void error(const std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_ERROR,std::forward<Args>(args)...);
    }
    template <class ... Args>
    void critical(const std::string& name,Args &&... args)
    {
        write(name,LogLevel::LEVEL_CRITICAL,std::forward<Args>(args)...);
    }
private:
    /*
    @fn
    @params name une reference constante sur une chaine de caractere
    @brief methode permettant de recuperer un pointeur sur un logger.
            le pointeur renvoyé n'appartient pas à l'appelant.
    @return Logger*
    */
    Logger* GetLogger(const std::string& name);
    /*ecriture generale*/
    template <class ... Args>
    void write(const std::string& name,LogLevel level,Args &&... args)
    {
        std::ostringstream stream;
		print(stream, std::forward<Args>(args)...);
        std::unique_ptr<LogContent> msg(new LogContent(level,stream.str()));
        writeOnLogger(name,msg);
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
    void writeOnLogger(const std::string& name,std::unique_ptr<LogContent>& msg);
    /*map contenant les loggers classés selon leur nom*/
    std::map<std::string,Logger*> _loggersMap;
    /*booleen : true si le systeme est asynchrone ou false si synchrone*/
    bool _isAsync;

};

#endif
