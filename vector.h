#ifndef DEF_VECTOR_H
#define DEF_VECTOR_H

#include <vector>
#include "matrix.h"

template <typename T>
class Vector: public Matrix<T> {
    public:
        Vector(std::size_t n, T initial_value=0);
        Vector(const Vector& v);

        void set_cell(std::size_t i, T val);
        double magnitude();

        Vector<T> unit_vector();

        //operators overloading
        Vector<T> operator*(const T val);
        Vector<T> operator+(const T val);


        Vector<T> operator+(const Vector<T>& v);
        Vector<T>& operator=(const Vector<T>& v);


        ~Vector();

};

#endif
