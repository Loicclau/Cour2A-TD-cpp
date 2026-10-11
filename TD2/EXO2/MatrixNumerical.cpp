
#include "MatrixNumerical.h"
#include <stdexcept>

// Constructeur par defaut
template <typename T>
MatrixNumerical<T>::MatrixNumerical()
    : MatrixBase<T>() {}

// Constructeur avec dimensions
template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols)
    : MatrixBase<T>(rows, cols) {}

// operateur Addition
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(
    const MatrixNumerical<T>& other) const {

    if (this->getRows() != other.getRows() ||
        this->getCols() != other.getCols()) {
        throw std::invalid_argument("Dimensions incompatibles pour +");
    }

    MatrixNumerical<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            result.addElement(i, j,
                this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

// operateur de Soustraction
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(
    const MatrixNumerical<T>& other) const {

    if (this->getRows() != other.getRows() ||
        this->getCols() != other.getCols()) {
        throw std::invalid_argument("Dimensions incompatibles pour -");
    }

    MatrixNumerical<T> result(this->getRows(), this->getCols());

    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            result.addElement(i, j,
                this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result; }

// Multiplication matricielle
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(
    const MatrixNumerical<T>& other) const {

    if (this->getCols() != other.getRows()) {
        throw std::invalid_argument("Dimensions incompatibles pour *");
    }

    MatrixNumerical<T> result(this->getRows(), other.getCols());

    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < other.getCols(); j++) {
            T sum = T{};

            for (size_t k = 0; k < this->getCols(); k++) {
                sum += this->getElement(i, k) *
                       other.getElement(k, j);
            }

            result.addElement(i, j, sum);
        }
    }

    return result;
}

// Division element par element
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(
    const MatrixNumerical<T>& other) const {

    if (this->getRows() != other.getRows() ||
        this->getCols() != other.getCols()) {
        throw std::invalid_argument("Dimensions incompatibles pour /");
    }

    MatrixNumerical<T> result(this->getRows(), this->getCols());

    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            T divisor = other.getElement(i, j);

            if (divisor == T{}) {
                throw std::invalid_argument("Division par zero");
            }

            result.addElement(i, j,
                this->getElement(i, j) / divisor);
        }
    }

    return result;
}

// Calcul du cofacteur
template <typename T>
T MatrixNumerical<T>::getCoFactor(size_t row, size_t col) const {
    size_t n = this->getRows();

    if (n != this->getCols()) {
        throw std::invalid_argument("La matrice doit etre carree");
    }
    if (row >= n || col >= n) {
        throw std::out_of_range("Indice invalide");
    }
    if (n == 1) { return T(1); }

    MatrixNumerical<T> minor(n - 1, n - 1);

    size_t mi = 0;

    for (size_t i = 0; i < n; i++) {
        if (i == row) {
            continue;
        }

        size_t mj = 0;

        for (size_t j = 0; j < n; j++) {
            if (j == col) { continue;}

            minor.addElement(mi, mj, this->getElement(i, j));
            mj++;
        } mi++;
    }

    T determinant = minor.getDeterminant();

    if ((row + col) % 2 != 0) {
        determinant = -determinant;
    }

    return determinant;
}

// Calcul du determinant
template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    size_t n = this->getRows();

    if (n != this->getCols()) {
        throw std::invalid_argument("La matrice doit etre carree");
    }

    if (n == 0) {
        throw std::invalid_argument("Matrice vide");
    }

    if (n == 1) {
        return this->getElement(0, 0);
    }

    if (n == 2) {
        return this->getElement(0, 0) * this->getElement(1, 1)
             - this->getElement(0, 1) * this->getElement(1, 0);
    }

    T determinant = T{};

    for (size_t j = 0; j < n; j++) {
        determinant += this->getElement(0, j) * getCoFactor(0, j);
    } return determinant;
}

// Calcul de la matrice inverse par la methode des cofacteurs
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    size_t n = this->getRows();

    if (n != this->getCols()) {
        throw std::invalid_argument("La matrice doit etre carree");
    }

    T determinant = getDeterminant();

    if (determinant == T{}) {
        throw std::invalid_argument("Matrice non inversible");
    }

    MatrixNumerical<T> inverse(n, n);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            inverse.addElement(i, j,
                getCoFactor(j, i) / determinant);
        }
    } return inverse;
}

// Creation d'une matrice identite
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size) {
    if (size <= 0) {
        throw std::invalid_argument("La taille doit etre positive");
    }

    MatrixNumerical<T> identity(
        static_cast<size_t>(size),
        static_cast<size_t>(size)
    );
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            identity.addElement(i, j, (i == j) ? T(1) : T(0));
        }
    } return identity;
}

// Instanciations explicites
template class MatrixNumerical<int>;
template class MatrixNumerical<float>;
template class MatrixNumerical<double>;
