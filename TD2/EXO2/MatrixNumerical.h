
#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <type_traits>

template <typename T>
class MatrixNumerical : public MatrixBase<T> { //herite de MatrixBase
    static_assert(std::is_arithmetic<T>::value,
                  "T doit etre un type numerique");

public:
    // Constructeurs
    MatrixNumerical();
    MatrixNumerical(size_t rows, size_t cols);
    // Operateurs
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;

    // Determinant
    T getDeterminant() const;

    // Cofacteur
    T getCoFactor(size_t row, size_t col) const;

    // Inverse
    MatrixNumerical<T> getInverse() const;

    // Matrice identite
    static MatrixNumerical<T> getIdentity(int size);
};

// Instanciations explicites
extern template class MatrixNumerical<int>;
extern template class MatrixNumerical<float>;
extern template class MatrixNumerical<double>;

#endif
