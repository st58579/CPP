#pragma once
#ifndef CVICENI_08_MATRIX_H
#define CVICENI_08_MATRIX_H

#include <stdexcept>
#include <iostream>

template<typename T>
class Matrix {
public:
    Matrix(int row, int col);

    Matrix(const Matrix<T>& m);

    ~Matrix();

    void set(int row, int col, T value);

    void setFrom(T* array);

    T& get(int row, int col);

    const T& get(int row, int col) const;

    template<typename R>
    Matrix<R> retype();

    Matrix transpose() const;

    Matrix multiply(const Matrix& m) const;
    Matrix multiply(T scalar) const;

    Matrix sum(const Matrix& m) const;
    Matrix sum(T scalar) const;

    bool isEqual(const Matrix& m) const;
    void print() const;

private:
    T** mtr;
    int rowCount;
    int colCount;
};

template<typename T>
Matrix<T>::Matrix(int row, int col) {
    rowCount = row;
    colCount = col;
    mtr = new T * [row];
    for (int i = 0; i < row; ++i) {
        mtr[i] = new T[col];
        for (int j = 0; j < col; ++j) {
            mtr[i][j] = 0;
        }
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m) {
    mtr = new T * [m.rowCount];
    for (int i = 0; i < m.colCount; ++i) {
        mtr[i] = new T[m.colCount];
        for (int j = 0; j < m.colCount; ++j) {
            mtr[i][j] = m.get(i, j);
        }
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rowCount; ++i) {
        delete[] mtr[i];
    }
    delete[] mtr;
}

template<typename T>
void Matrix<T>::set(int row, int col, T value) {
    if (row < rowCount && col < colCount) {
        mtr[row][col] = value;
    }
    else {
        throw std::invalid_argument{ "Invalid index" };
    }
}

template<typename T>
void Matrix<T>::setFrom(T* array) {
    int arrSize = sizeof(array) / sizeof(array[0]);
    int ptr = 0;
    if (arrSize < colCount * rowCount) {
        throw std::invalid_argument{ "Invalid array size" };
    }
    else {
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                mtr[i][j] = array[ptr];
                ptr++;
            }
        }
    }
}

template<typename T>
T& Matrix<T>::get(int row, int col) {
    if (row < rowCount && col < colCount) {
        return mtr[row][col]; //????????/
    }
    else {
        throw std::invalid_argument{ "Invalid index" };
    }
}

template<typename T>
const T& Matrix<T>::get(int row, int col) const {
    if (row < rowCount && col < colCount) {
        return mtr[row][col]; // ????????
    }
    else {
        throw std::invalid_argument{ "Invalid index" };
    }
}


template<typename T>
template<typename R>
Matrix<R> Matrix<T>::retype() {
    Matrix<R> matrix = new Matrix<R>(rowCount, colCount);
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            matrix.set(i, j,(R)mtr[i][j]);
        }
    }
    return matrix;
}


template<typename T>
bool Matrix<T>::isEqual(const Matrix<T>& m) const {
    if (rowCount == m.rowCount && colCount == m.colCount) {
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                if (mtr[i][j] != m.get(i, j)) {
                    return false;
                }
            }
        }
    }
    else {
        return false;
    }
    return true;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> transposed = new Matrix<T>(colCount, rowCount);
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            transposed.set(j,i, mtr[i][j]);
        }
    }
    return transposed;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const Matrix<T>& m) const {
    if (colCount != m.rowCount) { throw std::invalid_argument{ "count of m1 cols != count of m2 rows!" }; }
    Matrix<T> mult = new Matrix(rowCount, m.colCount);
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < m.colCount; ++j) {
            for (int k = 0; k < colCount; ++k) {
                mult.set(i,j,mtr[i][k] * m.get(k, j));
            }
        }
    }
    return mult;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(T scalar) const {
    Matrix<T> mult = new Matrix<T>(rowCount, colCount);
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            mtr[i][j] *= scalar;
        }
    }
    return mult;
}

template<typename T>
Matrix<T> Matrix<T>::sum(const Matrix& m) const {
    if (rowCount == m.rowCount && colCount == m.colCount) {
        Matrix<T> sum = new Matrix<T>(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                sum[i][j] += mtr[i][j] + m.get(i, j);
            }
        }
    }
    else {
        throw std::invalid_argument{ "wrong matrix size" };
    }
    return sum;
}
template<typename T>
Matrix<T> Matrix<T>::sum(T scalar) const {
    Matrix<T> sum = new Matrix<T>(rowCount, colCount);
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            sum[i][j] += mtr[i][j] + scalar;
        }
    }
    return sum;
}
template<typename T>
void Matrix<T>::print() const {
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            std::cout << mtr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif //CVICENI_08_MATRIX_H