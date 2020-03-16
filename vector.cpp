#include "Vector.h"
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

template<typename T>
Vector<T>::Vector(): Matrix<T>() {}

template<typename T>
Vector<T>::Vector(size_t n, T initial_value) : Matrix<T>(n, 1, initial_value){}

template<typename T>
Vector<T>::Vector(const Vector& v) : Matrix<T>(v){}


template<typename T>
Vector<T>::~Vector() {}

template<typename T>
void Vector<T>::set_cell(size_t i, T val){
    this->m_data[i][0] = val;
}



template<typename T>
double Vector<T>::magnitude() {

    size_t n = this->get_rows();
    double res = 0.0;
    for(size_t i = 0;i < n; i++) {
        res += this->get_cell(i) * this->get_cell(i);
    }
    return sqrt(res);
}

template<typename T>
Vector<T> Vector<T>::unit_vector(){
    return (*this) * (1/this->magnitude());
}

template<typename T>
Vector<T> Vector<T>::operator*(const T val){
    size_t n = this->get_rows();
    Vector ans(n);
    for (size_t i = 0; i < n; i++){
        ans.set_cell(i, this->get_cell(i) * val);
    }
    return ans;
}

template<typename T>
Vector<T> Vector<T>::operator+(const T val){
    size_t n = this->get_rows();
    Vector ans(n);
    for (size_t i = 0; i < n; i++){
        ans.set_cell(i, this->get_cell(i) + val);
    }
    return ans;
}

// I use matrix as parameter so that a can do multiplication of matrix and vector
// then assign the result (which is matrix) to a vector
// like that I don't have to define multiplication operator of matrix and vector;
template<typename T>
Vector<T>& Vector<T>::operator=(const Matrix<T>& v){

    this->m_data.clear();
    size_t rows = v.get_rows();
    this->m_rows = rows;
    this->m_cols = 1;
    this->m_data.resize(rows);

    for(size_t i = 0; i < rows ; i++){
        this->m_data[i].resize(1);
    }

    for (size_t i = 0; i < rows; i++){
        this->set_cell(i, v.get_cell(i, 0));
    }
    return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& v) {
    size_t rows = this->get_rows();

    if(rows != v.get_rows()) {
        throw "the two vectors must have same rows";
    }
    Vector<T> ans(rows);
    for (size_t i = 0; i < rows; i++){
        ans.set_cell(i, this->get_cell(i) + v.get_cell(i));
    }
    return ans;
}

/*template<typename T>
Vector<T> operator* (const Matrix<T>& m, const Vector<T>& v) {
    if(v.get_rows() != m.get_cols()) {
        throw "columns of the first matrix must equal to rows of vector";
    }
    size_t rows = m.get_rows();
    Vector<T> ans(rows);
    for (size_t i = 0; i < rows; i++){
        T sum = 0;
        for (size_t j = 0; j < m.get_cols(); j++){
            sum += m.get_cell(i, j) * v.get_cell(j);
        }
        ans.set_cell(i, sum);
    }
    return ans;
}
*/

template class Vector<int>;
template class Vector<double>;
