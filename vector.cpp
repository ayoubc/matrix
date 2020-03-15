#include "vector.h"
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;


/*

Vector Vector::operator+(const Vector v) {
    size_t n = this->m_dim;
    Vector c(n);
    for (size_t i = 0; i < n; i++){
        c.set_cell(i, this->get_cell(i) + v.get_cell(i));
    }
    return c;
}

double Vector::magnitude() {

    size_t n = this->get_dimension();
    double res = 0.0;
    for(size_t i = 0;i < n; i++) {
        res += this->get_cell(i) * this->get_cell(i);
    }
    return sqrt(res);
}
Vector::~Vector() {
    this->m_data.clear();
}
*/

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

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v){

    this->m_data.clear();
    size_t rows = v.get_rows();

    this->m_data.resize(rows);

    for(size_t i = 0; i < rows ; i++){
        this->m_data[i].resize(1);
    }

    for (size_t i = 0; i < rows; i++){
        this->set_cell(i, v.get_cell(i));
    }

    this->m_rows = rows;
    return *this;
}
template class Vector<int>;
template class Vector<double>;
