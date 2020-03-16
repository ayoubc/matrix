#ifndef DEF_VECTOR_H
#define DEF_VECTOR_H

#include <vector>
#include "Matrix.h"

template <typename T>
class Vector: public Matrix<T> {
    public:
        Vector();
        Vector(std::size_t n, T initial_value=0);
        Vector(const Vector& v);

        void set_cell(std::size_t i, T val);
        double magnitude();

        Vector<T> unit_vector();

        //operators overloading
        Vector<T> operator*(const T val);
        Vector<T> operator+(const T val);

        Vector<T> operator+(const Vector<T>& v);
        Vector<T>& operator=(const Matrix<T>& v);

        //friend  Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v);

        ~Vector();

};

#endif
