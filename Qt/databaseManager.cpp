#include "databaseManager.h"

// databaseManager() - constructor
// -------------------------------
// - adds the database
// - sets the datbase path
// - checks if the path already exists
// - if not open; puts an error message (could not open connection)
// - if it is open; puts a success message (can open connection)
// - if not for both; puts an error message  (path does not exist)
databaseManager::databaseManager()
{
    programDatabase = QSqlDatabase::addDatabase("QSQLITE");                 // determines what SQL it uses
    programDatabase.setDatabaseName(DB_PATH);                               // sets the database path

    if(QFile::exists(DB_PATH))          // checks if it exist
    {
        if(!programDatabase.open())     // checks if it is not open
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

// ~databaseManager() - destructor
// -------------------------------
// closes the database
databaseManager::~databaseManager()
{
    if(programDatabase.open())                      // closes it if its open once destructor is called
    {
        programDatabase.close();
    }
    qDebug() << "Destroying database manager.";
}

// databaseManager() - instance()
// ------------------------------
// returns the instance of databaseManager variable
databaseManager& databaseManager::instance()
{
    static databaseManager dmInstance;

    return dmInstance;
}
