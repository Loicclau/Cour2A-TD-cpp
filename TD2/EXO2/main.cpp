
#include "MatrixNumerical.h"
#include <iostream>

int main() {
    // ont cree 2 matrice
    MatrixNumerical<double> A(2, 2);
    MatrixNumerical<double> B(2, 2);
    A.addElement(0, 0, 1);
    A.addElement(0, 1, 2);
    A.addElement(1, 0, 3);
    A.addElement(1, 1, 4);
    B.addElement(0, 0, 5);
    B.addElement(0, 1, 6);
    B.addElement(1, 0, 7);
    B.addElement(1, 1, 8);


    //test des 2 class
    std::cout << "Matrice A :" << std::endl;
    A.Display();

    std::cout << "A + B :" << std::endl;
    (A + B).Display();

    std::cout << "A - B :" << std::endl;
    (A - B).Display();

    std::cout << "A * B :" << std::endl;
    (A * B).Display();

    std::cout << "Determinant de A : "
              << A.getDeterminant() << std::endl;
    std::cout << "Inverse de A :" << std::endl;
    A.getInverse().Display();
    return 0;
}
