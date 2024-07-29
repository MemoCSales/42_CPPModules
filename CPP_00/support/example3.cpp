#include <string>
#include <iostream>
#include <cctype>

class MyClass
{
public:
    void myMethod();
};

void MyClass::myMethod() {
    std::cout << "Hello World!" << std::endl;
}

int main() {
    MyClass myObj;
    myObj.myMethod();
    return (0);
}
