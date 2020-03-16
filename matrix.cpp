#include "matrix.h"
#include <stdio.h>
#include <iostream>
#include <stdexcept>
using namespace std;


template<typename T>
size_t Matrix<T>::get_rows() const {
    return this->m_rows;
}


template<typename T>
size_t Matrix<T>::get_cols() const {
    return this->m_cols;
}

template<typename T>
vector<vector<T> > Matrix<T>::get_data() const {
    return this->m_data;
}

template<typename T>
Matrix<T>::Matrix() {
    this->m_cols = 0;
    this->m_rows = 0;
    this->m_data.resize(0);
}

template<typename T>
Matrix<T>::Matrix(size_t n) {
    this->m_rows = n;
    this->m_cols = n;
    this->m_data.resize(n);
    for(size_t i = 0;i < n; i++) {
        this->m_data[i].resize(n);
    }
}

template<typename T>
Matrix<T>::Matrix(std::size_t t_rows, std::size_t t_cols, T initial_value) {
    this->m_rows = t_rows;
    this->m_cols = t_cols;
    this->m_data.resize(t_rows);
    for(size_t i = 0;i < t_rows; i++) {
        this->m_data[i].resize(t_cols, initial_value);
    }
}

// constructor by copy
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m) {

    this->m_data.clear();
    size_t rows = m.get_rows();
    size_t cols = m.get_cols();

    this->m_data.resize(rows);

    for(size_t i = 0; i < rows ; i++){
        this->m_data[i].resize(cols);
    }

    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            this->set_cell(i, j, m.get_cell(i, j));
        }
    }

    this->m_rows = rows;
    this->m_cols = cols;

}

template<typename T>
void Matrix<T>::print() const {
    size_t rows = this->get_rows();
    size_t cols = this->get_cols();
    /*printf("/ ");
    for(size_t i = 0;i < n; i++) {
        printf(" ");
    }
    printf("\\\n");
    */
    for(size_t i = 0;i < rows; i++) {
        printf("| ");
        for(size_t j = 0; j < cols; j++) {
            cout << this->get_cell(i, j) << " ";
        }
        printf("|\n");
    }
    /*printf("/ ");
    for(size_t i = 0;i < n; i++) {
        printf(" ");
    }
    printf("\\\n");
    */
}

template<typename T>
void Matrix<T>::set_cell(size_t i, size_t j, T val) {
    this->m_data[i][j] = val;
}

template<typename T>
T Matrix<T>::get_cell(size_t i, size_t j) const {
    return this->m_data[i][j];
}

// multiply a matrix by a scalar
template<typename T>
Matrix<T> Matrix<T>::operator*(const T val){
    size_t rows = this->get_rows();
    size_t cols = this->get_cols();
    Matrix<T> ans(rows, cols);
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            ans.set_cell(i, j, this->get_cell(i, j) * val);
        }
    }
    return ans;
}

// add a scalar to a matrix
template<typename T>
Matrix<T> Matrix<T>::operator+(const T val){
    size_t rows = this->get_rows();
    size_t cols = this->get_cols();
    Matrix<T> ans(rows, cols);
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            ans.set_cell(i, j, this->get_cell(i, j) + val);
        }
    }
    return ans;
}

// matrix assignment
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m){

    this->m_data.clear();
    size_t rows = m.get_rows();
    size_t cols = m.get_cols();

    this->m_data.resize(rows);

    for(size_t i = 0; i < rows ; i++){
        this->m_data[i].resize(cols);
    }

    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            this->set_cell(i, j, m.get_cell(i, j));
        }
    }

    this->m_rows = rows;
    this->m_cols = cols;
    return *this;
}

// multiply a matrix by an other
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m){
    size_t rows = this->get_rows();
    size_t cols = this->get_cols();
    if(cols != m.get_rows()) {
        throw "columns of the first matrix must equal to rows of the second";
    }
    Matrix<T> ans(rows, m.get_cols());
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < m.get_cols(); j++){
            T sum = 0;
            for(size_t k = 0; k < cols; k++) {
                sum += this->get_cell(i, k) * m.get_cell(k, j);
            }
            ans.set_cell(i, j, sum);
        }
    }
    return ans;
}
/*
template<typename T>
Matrix<T> operator* (const Matrix<T>& m, const Matrix<T>& v) {
    size_t rows = m.get_rows();
    size_t cols = m.get_cols();
    if(cols != v.get_rows()) {
        throw "columns of the first matrix must equal to rows of the second";
    }
    Matrix<T> ans(rows, v.get_cols());
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < v.get_cols(); j++){
            T sum = 0;
            for(size_t k = 0; k < cols; k++) {
                sum += m.get_cell(i, k) * v.get_cell(k, j);
            }
            ans.set_cell(i, j, sum);
        }
    }
    return ans;
}
*/
// matrix addition
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) {
    size_t rows = this->get_rows();
    size_t cols = this->get_cols();
    if(rows != m.get_rows() || cols != m.get_cols()) {
        //runtime_error("the two matrices must have same rows and same columns");
        throw "the two matrices must have same rows and same columns";
    }
    Matrix<T> ans(rows, cols);
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            ans.set_cell(i, j, this->get_cell(i, j) + m.get_cell(i, j));
        }
    }
    return ans;
}

// matrix power
// risk to have overflow for int
template<typename T>
Matrix<T> Matrix<T>::power(int p) {
    if(this->get_cols() != this->get_rows()) {
        throw "the matrix should be square";
    }
    if(p == 0) return Matrix<T>::get_identity(this->get_rows());
    if(p == 1) return *this;

    Matrix<T> b = this->power(p>>1);
    b = b*b;
    if(p&1){
        b = b * (*this);
    }
    return b;
}
template<typename T>
Matrix<T> Matrix<T>::get_identity(size_t n) {
    Matrix<T> id(n, n, 0);
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            id.set_cell(i, j, (i == j ? 1 : 0));
        }
    }
    return id;
}

template<typename T>
Matrix<T>::~Matrix() {
    this->m_data.clear();
}


template class Matrix<int> ;
template class Matrix<double>;

