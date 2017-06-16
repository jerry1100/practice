/*
   Variables are used to store data. They are contained in memory and are
   accessed through a variable name, or identifier.

   Variable names can only consist of letters, digits, and/or underscores.
   Furthermore, variable names must begin with a letter or underscore, and
   cannot match any of the reserved keywords such as 'int', 'while', etc. Note
   that variable names are case sensitive: 'Num1' is not the same as 'num1'.

   Along with variable names, there are variable types: characters, integers,
   floating-point, and booleans. There are also void and null types as well.
   These types take up different amounts of memory and are stored differently.
   It's important to note that the different types have a minimum size rather
   than a defined size--so different compilers may define the same type to use
   different amounts of memory.

   Variables can be initialized in three ways: c-like initialization,
   constructor initialization, and uniform initialization.
 */

#include <iostream>
using namespace std;

int main() {
    int a = 5; // c-like initialization
    int b (5); // constructor initialization
    int c {5}; // uniform initialization

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
}
