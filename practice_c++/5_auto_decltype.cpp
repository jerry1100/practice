/*
   We can use 'auto' or 'decltype' to initialize or declare a new variable
   without having to explicitly state its type. We accomplish this by using an
   existing variable and telling the compiler to initialize or declare our new
   variable with the same type as our existing variable.

   The difference between 'auto' and 'decltype' is that 'auto' is used to
   initialize a new variable using the type and value of an existing variable,
   whereas 'decltype' just declares a new variable using the type of an
   existing variable.

   This can be useful in situations where explicitly typing out the type of a
   variable reduces code readibility, such as types with a long or complex
   name.
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
