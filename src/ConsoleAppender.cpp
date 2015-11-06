#include "ConsoleAppender.h"
/*
@fn ConsoleAppender(const std::string& name,LogLevel level)
@params name reference constante sur une chaine de caractere representant le nom de l'appender console
        level le niveau minimum de log
@brief constructeur
@return no return
*/
ConsoleAppender(const std::string& name, LogLevel level) : Appender(name,level)
{

}
/*
@fn ConsoleAppender(const ConsoleAppender& coy)
@params copy une reference constante sur un objet ConsoleAppender à copier
@brief constructeur de copie
@return no return
*/
ConsoleAppender(const ConsoleAppender& copy) : Appender(copy._name,copy.minLogLevel)
{

}
/*
@fn ConsoleAppender(ConsoleAppender&& moved)
@params moved une reference de deplacement sur un objet ConsoleAppender à déplacer
@brief constructeur de déplacement
@return no return
*/
ConsoleAppender(ConsoleAppender&& moved)
{
    //TODO : implementer
}
/*
@fn virtual void write(LogContent& content)
@params content une reference sur un objet LogContent à traiter
@brief methode permettant de traiter un objet LogContent
@return void
*/
virtual void write(LogContent& content)
{
    std::cout<<content.getContent()<<std::endl;
}
