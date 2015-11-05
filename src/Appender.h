#ifndef APPENDER_H
#define APPENDER_H
/*INCLUSIONS*/

/*FIN INCLUSIONS*/
class LogContent;
class Logger;
enum LogLevel;
class Appender
{
public:
    /*
    @fn Appender(LogLevel level)
    @params level le niveau minimum de log
    @brief constructeur
    @return no return
    */
    Appender(LogLevel level);
    /*
    @fn Appender(const Appender& coy)
    @params copy une reference constante sur un objet Appender à copier
    @brief constructeur de copie
    @return no return
    */
    Appender(const Appender& copy);
    /*
    @fn Appender(Appender&& moved)
    @params moved une reference de deplacement sur un objet Appender à déplacer
    @brief constructeur de déplacement
    @return no return
    */
    Appender(Appender&& moved);
    /*
    @fn ~Appender()
    @params no params
    @brief destructeur
    @return no return
    */
    ~Appender();
    /*
    @fn bool shouldLogLevel(LogLevel levelToLog)
    @params levelToLog le niveau de log à vérifier
    @brief methode permettant de vérifier si un niveau de log est accepté ou non
    @return bool
    */
    bool shouldLogLevel(LogLevel levelToLog);
    /*
    @fn virtual void write(LogContent& content)=0
    @params content une reference sur un objet LogContent à traiter
    @brief methode permettant de traiter un objet LogContent
    @return void
    */
    virtual void write(LogContent& content)=0;
private:
    /*le niveau minimum de log*/
    LogLevel _minLogLevel;

};
#endif
