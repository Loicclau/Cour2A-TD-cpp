#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

class MyClass { //init de la class
private:
    std::string my_element; //VARIABLE PRIVEE

public:
    MyClass(std::string value); //constru avec arg
    void print_my_element() const;
};

#endif 