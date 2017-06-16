/*
   Strings are an example of a compound variable type. Compound variable types
   are built upon the fundamental types (integers, characters, etc.) and can
   provide more functionality than the fundamental types. Strings can store a
   sequence of characters, such as words and phrases, which can be very useful.

   To use compound variable types, the appropriate header must be included. To
   use strings, we must first include <string> from the standard library.

   Strings can be initialized in the same way as other variables: c-like
   initialization, constructor initialization, and uniform initialization.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Hello world 1"; // c-like initialization
    string str2 ("Hello world 2"); // constructor initialization
    string str3 {"Hello world 3"}; // uniform initialization

    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "String 3: " << str3 << endl;
}
