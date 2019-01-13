#include "loginManager.h"

loginManager::loginManager() {}         // causes declaration of class within itself
loginManager::~loginManager(){}         // causes deletion of class within intself

loginManager& loginManager::instance()
{
    static loginManager instance;       // only one instance of loginManager

    return instance;
}

// create Login account
bool loginManager::createLoginAccount(const login &Login) const
{
    if(Login.getUsername().isEmpty() || Login.getPassword().isEmpty() || Login.getEmail().isEmpty())            // checks if user input is empty
    {
        qDebug() << "Cannot create a login record if username, email address, or password is not provided.";    // error message if user input is empty
        return false;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO LoginInfo (id, email, username, password, salt) VALUES(:idNum, :emailAddress, :username, :password, :salt)");  // creates a new login record with user input into their respective areas
    insertQuery.bindValue("idNum", Login.getId());              // gets user input of id num (does not since it is auto incremented - check database
    insertQuery.bindValue(":emailAddress", Login.getEmail());   // gets user input - email address
    insertQuery.bindValue(":username", Login.getUsername());    // gets user input - username
    insertQuery.bindValue(":password", Login.getPassword());    // gets user input - password (hashed+appended salt)
    insertQuery.bindValue(":salt", Login.getSalt());            // gets user input - salt (random generated string that was made when account is created

    if(insertQuery.exec())
    {
        qDebug() << "Login account creation succeeded!";        // success message
        return true;
    }
    else
    {
        qDebug() << "Login account creation has failed!" << insertQuery.lastError();    // fail message
        return false;
    }
}

// delete Login account by using the id number of the account
bool loginManager::deleteLoginAccount(int loginId) const
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM LoginInfo WHERE id = :idID");  // finds the record with the id number
    deleteQuery.bindValue(":idID", loginId);                        // gets user input - id number

    // checks if its in the database or not (error check)
    bool exist;
    QString temp;
    temp = QString::number(loginId);
    QSqlQuery query;
    query.prepare("SELECT * FROM LoginInfo");
    query.bindValue(":id", loginId);
    query.exec();
    while(query.next())
    {
        if(query.value(0).toString() != temp)
        {
            exist = false;          // if its not in the database
        }
        else
        {
            exist = true;           // if its in the database
            break;                  // break loop
        }
    }

    if(exist == true)
    {
        if(deleteQuery.exec())
        {
            qDebug() << "Login record has been deleted!";   // success message in console if it has been deleted
            return true;
        }
        else
        {
            qDebug() << "Login record has failed!";         // message in console if it has failed
            return false;
        }
    }
    else
    {
        qDebug() << "Login record has failed!";             // message in console if it has failed
        return false;
    }
}

// update Login account (NEEDS TO BE IMPLEMENTED (MIGHT BE ANPOTHER WAY) <------------------------------- DEVELOPER NOTICE :)
bool loginManager::updateLoginAccount(const login &Login) const
{
    QSqlQuery updateQuery;

    updateQuery.prepare("UPDATE LoginInfo SET email = :emailAddress, username = :username, password = :password, salt = :salt WHERE id = :userId");
    updateQuery.bindValue(":emailAddress", Login.getEmail());
    updateQuery.bindValue(":username", Login.getUsername());
    updateQuery.bindValue(":password", Login.getPassword());
    updateQuery.bindValue(":userId", Login.getId());
    updateQuery.bindValue(":salt", Login.getSalt());

    if(updateQuery.exec())
    {
        qDebug() << "Login account has been edited!";
        return true;
    }
    else
    {
        qDebug() << "Login account edit has failed!";
        return false;
    }
}

// authenticate login account
login loginManager::authenticate(const QString &Username, const QString &Password) const
{
    loginManager::instance();   // gets an instance of loginManager
    QSqlQuery query;

    query.prepare("SELECT id, email, username, password, salt FROM LoginInfo WHERE username = (:Username)");    // selects all from loginInfo where username matches
    query.bindValue(":Username", Username);                     // gets user input - username

    if(query.exec())
    {
        int idID       = query.record().indexOf("id");          // gets the data of id
        int idEmail    = query.record().indexOf("email");       // gets the data of email
        int idUsername = query.record().indexOf("username");    // gets the data of username
        int idPassword = query.record().indexOf("password");    // gets the data of password
        int idSalt     = query.record().indexOf("salt");        // gets the data of salt

        if(query.next())
        {
            QString dbemail    = query.value(idEmail).toString();       // used for compare
            QString dbusername = query.value(idUsername).toString();    // used for compare
            QString dbpassword = query.value(idPassword).toString();    // used for compare
            QString dbsalt     = query.value(idSalt).toString();        // used for compare
                int dbid       = query.value(idID).toInt();             // used for compare

            qDebug() << "Salt associated with the user account: " << dbsalt;
            QString temp;
            temp = Password + dbsalt;   // combines user input password and stored salt

            qDebug() << "Salt and user entered password is added together: " << temp;

            QByteArray hash = QCryptographicHash::hash(temp.toLocal8Bit(), QCryptographicHash::Sha256);     // hashes the password+salt
            hash = hash.toHex();        // makes it into ASCII (string)
            qDebug() << "Hashed password of the above password + salt: " << hash;

            if(dbpassword == hash)      // checks if its the same
            {
                qDebug() << "Hashed password matches with the stored hashed password that was saved" << hash;
                return login(dbid, dbemail, dbusername, dbpassword, dbsalt); // returns the record if it is
            }
        }
    }
    else
    {
        qDebug() << "Error authenticating: " << query.lastError();      // console message for when it fails
    }

    return NULL_USER;   // returns as error if it fails authenticating
}
