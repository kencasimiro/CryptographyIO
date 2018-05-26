#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QMessageBox>                  // for QMessageBox
#include <QSqlQuery>                    // QSqlQuery
#include <QSqlError>                    // for QSqlQuery error
#include <QSqlRecord>                   // for QSqlRecord
#include <QVariant>                     // for QVariant
#include <QDebug>                       // for debugging purposes
#include <qcryptographichash.h>         // used for hashing (SHA256)

#include "login.h"          // login class
#include "constants.h"      // constant variables

/**
 * @brief The loginManager class. Allows to create, delete, update, and authenticate a login record in SQLite
 * @author Kenneth Casimiro
 * @date May 2018
 */
class loginManager
{
public:
    static loginManager& instance();                                                // creates an instance of loginManager
    loginManager(loginManager const&) = delete;                                     // disable copy
    void operator=(loginManager const&) = delete;                                   // disable copy
    bool createLoginAccount(const login& Login) const;                              // create login record in SQLite
    bool deleteLoginAccount(int loginId) const;                                     // delete login record in SQLite
    bool updateLoginAccount(const login& Login) const;                              // update login record in SQLite
    login authenticate(const QString& Username, const QString& Password) const;     // authenticate the login

private:
    loginManager();         // forbid creartion outside of class
    ~loginManager();        // forbid to delete instance outside of class
};

#endif // LOGINMANAGER_H
