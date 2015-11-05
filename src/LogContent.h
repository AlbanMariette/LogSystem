#ifndef LOG_CONTENT_H
#define LOG_CONTENT_H
/*INCLUSIONS*/
#include <string>
#include "Logger.h"
/*FIN INCLUSIONS*/
/*
@class LogContent
@brief classe encapsulant le contenu d'un log
*/
class LogContent
{
public:
    /*
    @fn LogContent(LogLevel& level,std::string& content)
    @params level une reference sur le niveau de log de l'objet
            content une reference sur une chaine de caractere representant l'objet à logger
    @brief constructeur
    */
    LogContent(LogLevel& level,std::string& content);
    /*
    @fn LogContent(const LogContent& copy)
    @params copy reference constante sur un autre objet à copier
    @brief constructeur de copie
    */
    LogContent(const LogContent& copy);
    /*
    @fn LogContent(LogContent&& moved)
    @params moved reference sur un objet à déplacer
    @brief constructeur de mouvement
    */
    LogContent(LogContent&& moved);
    /*
    @fn ~LogContent()
    @params no params
    @brief destructeur
    */
    ~LogContent();
    /*
    @fn std::string&& Move()
    @params no params
    @brief methode permettant le deplacement de la chaine de caractere de l'objet
            et son nettoyage proprement
    @return une chaine de caractere deplacée
    */
    std::string&& Move();
    /*
    @fn const LogLevel& getLevel() const
    @params no params
    @brief accesseurs sur le niveau de log
    @return const LogLevel&
    */
    const LogLevel& getLevel() const;
    /*
    @fn const std::string& getContent() const
    @params no params
    @brief accesseurs sur le contenu du log
    @return const std::string&
    */
    const std::string& getContent() const;
private:
    /*le niveau de log*/
    LogLevel _logLevel;
    std::string _content;
};
#endif
