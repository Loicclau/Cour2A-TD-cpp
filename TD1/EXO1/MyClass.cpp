#include <iostream>
#include "MyClass.h"

MyClass::MyClass(std::string value) {
    my_element = value;
}

void MyClass::print_my_element() const {
    std::cout << my_element << std::endl;
}