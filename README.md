# Hash and Salt a Password
This program hashes using the SHA256 algorithm and appeneds a password with a random generated salt.

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

* **Kenneth Casimiro** - Programmer - [wuwukennywu](https://github.com/boolenciaga)

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
