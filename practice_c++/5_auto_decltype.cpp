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

   We can use 'auto' or 'decltype' to initialize or declare a new variable with
   the same type as a previous variable. For example, consider an integer named
   'a' with the value 5. To initialize another integer 'b' to the value of 'a',
   we know we could do 'int b = a;' but we could also do 'auto b = a;'. Using
   'auto' will tell the compiler to figure out the type of 'a' and initialize
   'b' with the same type. This may be useful if the type is a long word and is
   hard to type out, or if one wants to change the type of 'a' frequently and
   doesn't want to have to update all the instances of 'b'. Also note that
   'decltype' works in a similar way.
 */

#include <iostream>
using namespace std;

int main() {
    int a = 5;
    auto b = a; // initialize 'b' with type and value of 'a'
    decltype(a) c; // declare 'c' as same type as 'a'

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    c = a;
    cout << "After setting 'c' to 'a', value of c: " << c << endl;
}
