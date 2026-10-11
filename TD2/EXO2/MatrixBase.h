
#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <iostream>
#include <vector>
#include <cstddef>

template <typename T>
class MatrixBase {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t r, size_t c);

    void addElement(size_t row, size_t col, const T& value);

    T& getElement();
    T& getElement(size_t row, size_t col);
    const T& getElement(size_t row, size_t col) const;
    size_t getRows() const;
    size_t getCols() const;

    void Display() const;
};

extern template class MatrixBase<int>;
extern template class MatrixBase<float>;
extern template class MatrixBase<double>;

#endif
