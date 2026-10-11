
#include "MatrixBase.h"
#include <stdexcept>

template <typename T>
MatrixBase<T>::MatrixBase() : rows(0), cols(0) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c)
    : data(r, std::vector<T>(c)), rows(r), cols(c) {}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, const T& value) {
    if (row >= rows || col >= cols)
        throw std::out_of_range("Indice invalide");

    data[row][col] = value;
}

template <typename T>
T& MatrixBase<T>::getElement() {
    return data.at(0).at(0); }

template <typename T>
T& MatrixBase<T>::getElement(size_t row, size_t col) {
    return data.at(row).at(col); }

template <typename T>
const T& MatrixBase<T>::getElement(size_t row, size_t col) const {
    return data.at(row).at(col);
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;}
template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;}

template <typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}
template class MatrixBase<int>;
template class MatrixBase<float>;
template class MatrixBase<double>;
