# Hash and Salt a Password
This program hashes using the SHA256 algorithm and appeneds a password with a random generated salt.

A qt application that allows the user to create an account (username and password) through a one way cryptographic function (SHA256). Program also creates a salt to be added to the pre-hash password to safeguard passwords in storage. Password and salt is stored in SQLite as hashed. User is able to change their password as well and see through the console of what the one way function hashes out. The program demonstrates the importance of using a one-way cryptographic function rather than 'encryption' so no one can decrypt the password back to the original text.

![Image description](https://github.com/boolenciaga/HashSaltPassword/blob/master/Application%20Screenshots/Screen%20Shot%202019-01-13%20at%204.01.42%20AM.png)


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

* **Kenneth Casimiro** - Programmer - [boolenciaga](https://github.com/boolenciaga)

See also the list of [contributors](https://github.com/boolenciaga/HashSaltPassword/graphs/contributors) who participated in this project.

## License

MIT License

Copyright (c) 2018 wuwukennywu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Acknowledgments
