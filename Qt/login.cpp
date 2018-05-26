#include "login.h"

// check id of login accounr
int login::getId() const
{
    return id;
}

// check email address of login account
const QString& login::getEmail() const
{
    return emailAddress;
}

// check username of login account
const QString& login::getUsername() const
{
    return username;
}

// check password of login account
const QString& login::getPassword() const
{
    return password;
}

// check salt of login account
const QString& login::getSalt() const
{
    return salt;
}

// change id of login account
void login::setId(int newId)
{
    id = newId;
}

// change email of login account
void login::setEmail(const QString &email)
{
    emailAddress = email;
}

// change username of login account
void login::setUsername(const QString &uname)
{
    username = uname;
}

// change password of login account
void login::setPassword(const QString &pass)
{
    password = pass;
}

// change salt of login account
void login::setSalt(const QString &Salt)
{
    salt = Salt;
}

// default constructor
login::login()
    :login(UNASSIGNED_DB_ID, "", "","", "")
{}

// constructor used with authentication
login::login(const login &Login)
    :login(Login.id,Login.emailAddress,Login.username,Login.password, Login.salt)
{}

// constructor used with delete login
login::login(int dbId, const QString &emailAddress, const QString &uname, const QString &pass, const QString &Salt)
    :id(dbId), emailAddress(emailAddress), username(uname), password(pass), salt(Salt)
{}

// constructor used with add login
login::login(const QString &emailAddress, const QString &uname, const QString &pass, const QString& Salt)
    :login(UNASSIGNED_DB_ID, emailAddress, uname, pass, Salt)
{}

// overload equality operator
bool login::operator ==(const login& Login) const
{
    return emailAddress.compare(Login.emailAddress) == 0 &&
           username.compare(Login.username) == 0 &&
           password.compare(Login.password) == 0 &&
           salt.compare(Login.salt) == 0 &&
           id == Login.id;
}

// overload does not equal operator
bool login::operator !=(const login& Login) const
{
    return !(*this == Login);
}

// overload assignment operator
login& login::operator =(const login& Login)
{
    if(this != &Login)
    {
        emailAddress = Login.emailAddress;
        username     = Login.username;
        password     = Login.password;
        salt         = Login.salt;
        id           = Login.id;
    }

    return *this;
}

// overload toString function
QString login::toString() const
{
    QString output;

    output = output % "Username: " % username %
                   "\nPassword: "  % password %
                   "\nSalt: " % salt %
                   "\nEmail Address: " % emailAddress %
                   "\nDB Id: "  + id;

    return output;
}
