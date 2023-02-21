#include <iostream>
#include <main.hpp>

using std::cout;
using std::endl;


int main(int argc, char** argv){
    cout << "Hello World!" << endl;
    cout << "This is a library function: " << a_library_function() << endl;
    return 0;
}

std::string a_library_function(){
    return std::string("a function specified in the source code");
}
