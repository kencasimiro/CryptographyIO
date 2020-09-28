# Cryptography IO
A qt application that allows the user to create an account (username and password) through a one way cryptographic function (SHA256). Program also creates a salt to be added to the pre-hash password to safeguard passwords in storage. Password and salt is stored in SQLite as hashed. User is able to change their password as well and see through the console of what the one way function hashes out. The program demonstrates the importance of using a one-way cryptographic function rather than 'encryption' so no one can decrypt the password back to the original text.

![Image description](https://github.com/kencasimiro/cryptopgrahyIO/blob/master/Application%20Screenshots/Screen%20Shot%202019-01-13%20at%204.31.57%20AM.png)

![Image description](https://github.com/kencasimiro/cryptographyIO/blob/master/Application%20Screenshots/Screen%20Shot%202019-01-13%20at%204.32.50%20AM.png)

When creating a login account/record:
- Generate random salt.
- Append or prepend the salt value to the user's password.
- Hash the combination of password and salt (using something strong, like SHA256).
- Store the user name, the hashed value and the salt in the database.

When the user attempts to sign in:
- Load the salt value associated with the username.
- Append or prepend (ie. do the same as when they registered) the salt to the supplied password.
- Hash the combination, compare that to the stored hash. If they're different, sign-in fails.

### Prerequisites

Know C++

### Coding Style

C++ Language

[Google C++ Coding Style](https://google.github.io/styleguide/cppguide.html)

## Deployment

Run in Qt 5.11.0

## Built With

* [Qt](https://www.qt.io) - Graphical User Interface
* [SQLite](https://www.sqlite.org/index.html) - Relational Database Management System

## Authors

* **Kenneth Casimiro** - Programmer - [kencasimiro](https://github.com/kencasimiro)

See also the list of [contributors](https://github.com/boolenciaga/CryptographyIO/graphs/contributors) who participated in this project.
