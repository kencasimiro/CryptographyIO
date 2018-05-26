#ifndef LOGIN_H
#define LOGIN_H

#include <QStringBuilder>       // for QString
#include <QString>              // for string equivalent in Qt

#include "constants.h"

/**
 * @brief The login class
 * @author Kenneth Casimiro
 * @date May 2018
 */
class login
{
private:
    int id;                                     // int    - id
    QString emailAddress;                       // string - email address
    QString username;                           // string - username
    QString password;                           // string - password
    QString salt;

public:
    const QString& getEmail() const;            // get email address
    const QString& getUsername() const;         // get username
    const QString& getPassword() const;         // get password
    const QString& getSalt() const;
    int getId() const;                          // get id number

    void setEmail(const QString& email);        // change email address
    void setUsername(const QString& uname);     // change username
    void setPassword(const QString& pass);      // change password
    void setSalt(const QString& Salt);
    void setId(int newId);                      // change id number

    login();                                                                                    // default constructor
    login(const login& Login);                                                                  // constructor w/ parameters
    login(int dbId, const QString& emailAddress, const QString& uname, const QString& pass, const QString& Salt);    // constructor w/ parameters
    login(const QString &emailAddress, const QString& uname, const QString& pass, const QString& Salt);                                           // constructor w/ parameters
    bool operator ==(const login& Login) const;                                                 // overload equality operator (==)
    bool operator !=(const login& Login) const;                                                 // overload not equality operator (!=)
    login& operator =(const login& Login);                                                      // overload assignment operator (=)
    QString toString() const;                                                                   // convert to QString

};

const login NULL_USER;                                                                          // for error check

#endif // LOGIN_H
