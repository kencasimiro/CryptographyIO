#include "databaseManager.h"

databaseManager::databaseManager()
{
    programDatabase = QSqlDatabase::addDatabase("QSQLITE");
    programDatabase.setDatabaseName(DB_PATH);

    if(QFile::exists(DB_PATH))
    {
        if(!programDatabase.open())
        {
            qDebug() << "Error: Could not open connection to database.";
        }
        else
        {
            qDebug() << "Database connection is open.";
        }
    }
    else
    {
        qDebug() << "Cannot open database because the database path does not exist.";
    }
}

databaseManager::~databaseManager()
{
    if(programDatabase.open())
    {
        programDatabase.close();
    }
    qDebug() << "Destroying database manager.";
}

databaseManager& databaseManager::instance()
{
    static databaseManager dmInstance;

    return dmInstance;
}
