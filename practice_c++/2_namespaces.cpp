/*
   Namespaces divide the global scope into distinct named scopes. They are 
   useful for preventing collisions, such as two functions with the same name.

   As an example, consider two functions both named 'bar', except one is within
   the 'foo' namespace and the other is within the 'moo' namespace. To access
   the two functions, is 'foo::bar()' and 'moo::bar()' respectively. This is
   okay as the two functions exist within their own namespace and doesn't cause
   any conflict.

   To avoid needing the prefix (say you want the std namespace for everything),
   you can use the 'using namespace' directive, e.g. 'using namespace std;'.
   This tells the compiler to use the std namespace for all the code below the
   directive.
 */

#include <iostream>
using namespace std;

// Namespace foo
namespace foo {
    void bar() {
        cout << "Inside foo::bar()" << endl;
    }
}

// Namespace moo
namespace moo {
    void bar() {
        cout << "Inside moo::bar()" << endl;
    }
}

int main() {
    // Access bar inside foo namespace
    foo::bar();

    // Access bar inside moo namespace
    moo::bar();

    return 0;
}
