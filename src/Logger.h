#ifndef LOGGER_H
#define LOGGER_H
/*INCLUSIONS*/
/*FIN INCLUSIONS*/
class LogContent;
class Appender;
/*
@enum LogLevel
@brief enumeration representant les niveaux de log
*/
enum LogLevel
{
    LEVEL_TRACE,
    LEVEL_INFO,
    LEVEL_WARNING,
    LEVEL_ERROR,
    LEVEL_CRITICAL

};
/*
@class Logger
@brief classe representant une "interface" de log.
*/
class Logger
{
public:
    /*
    @fn Logger(const std::string& name,LogLevel minLevel)
    @params name une reference constante sur une chaine de caractere representant le nom du logger
            minLevel le niveau de log minimum accepté
    @brief constructeur
    @return no return
    */
    Logger(const std::string& name,LogLevel minLevel);
    /*
    @fn Logger(const Logger& copy)
    @params copy reference constante sur le Logger à copier
    @brief constructeur de copie
    @return no return
    */
    Logger(const Logger& copy);
    /*
    @fn Logger(Logger&& moved)
    @params moved reference de déplacement sur le Logger à copier
    @brief constructeur de déplacement
    @return no return
    */
    Logger(Logger&& moved);
    /*
    @fn ~Logger()
    @params no params
    @brief destructeur
    @return no return
    */
    ~Logger();
    /*
    @fn std::map<std::string,Appender*>&& Move()
    @params no params
    @brief methode permettant le deplacement du Logger
    @return std::map<std::string,Appender*>&& une refernce de deplacement sur une map
    */
    std::map<std::string,Appender*>&& Move();
    /*
    @fn bool addAppender(Appender* appender)
    @params appender pointeur sur l'objet Appender à ajouter. (La classe Logger en devient responsable)
    @brief methode permettant d'ajouter un appender
    @return bool true si l'ajout a réussi, false sinon
    */
    bool addAppender(Appender* appender);
    /*
    @fn bool delAppender(Appender* appender)
    @params appender pointeur sur l'objet Appender à supprimer.
    @brief methode permettant de supprimer un appender
    @return bool true si la deletion a réussie, false sinon (appender inexistant)
    */
    bool delAppender(Appender* appender);
    /*
    @fn bool delAppender(const std::string& name)
    @params name reference constante sur le nom de l'appender
    @brief methode permettant de supprimer un appender
    @return bool true si la deletion a réussie, false sinon (appender inexistant)
    */
    bool delAppender(const std::string& name);
    /*
    @fn bool shouldLogLevel(const LogLevel& levelToTest)
    @params no params
    @brief methode permettant de vérifier si un niveau de log est accepté ou non
    @return bool true si le niveau de log est accepté, false sinon
    */
    bool shouldLogLevel(const LogLevel& levelToTest);
    /*
    @fn const std::string& getName()
    @params no params
    @brief methode retournant le nom du Logger
    @return const std::string&
    */
    const std::string& getName();
    /*
    @fn void write(LogContent& content)
    @params content reference sur un objet LogContent
    @brief methode permettant de logger un contenu
    @return void
    */
    void write(LogContent& content);
    /*
    @fn void writeAsync(LogContent& content)
    @params content reference sur un objet LogContent
    @brief methode permettant de logger un contenu de façon asynchrone
    @return void
    */
    void writeAsync(LogContent& content);
private:
    /*le nom du logger*/
    std::string _name;
    /*le niveau de log minimum*/
    LogLevel _minLogLevel;
    /*les appenders*/
    std::map<std::string,Appender*> _appendersMap;
};

#endif
