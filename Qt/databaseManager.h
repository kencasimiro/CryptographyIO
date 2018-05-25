#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QDebug>
#include <QFile>
#include <QSqlRecord>

#include "constants.h"

/**
 * @brief The databaseManager class: used to manipulate the SQLite database for this program
 * @author Kenneth Casimiro
 * @date May 2018
 */
class databaseManager
{
public:
    static databaseManager& instance();                 // creates an instance (use 1 at a time)
    databaseManager(const databaseManager&) = delete;   // delete copy constructor
    void operator =(const databaseManager&) = delete;   // delete assignment operator
    bool isOpen() const;                                // checks if database is open

private:
    databaseManager();              // constructor
    ~databaseManager();             // destructor
    QSqlDatabase programDatabase;   // database
};

#endif // DATABASEMANAGER_H
