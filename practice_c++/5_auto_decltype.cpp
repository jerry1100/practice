/*
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
