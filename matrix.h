#ifndef DEF_MATRIX_H
#define DEF_MATRIX_H

#include <vector>
//#include "Vector.h"

template<typename T>
class Matrix {
    public:
        Matrix();
        Matrix(std::size_t n);
        Matrix(std::size_t n, std::size_t m, T initial_value=0);
        Matrix(const Matrix<T>& mat);

        void print() const;
        std::size_t get_rows() const;
        std::size_t get_cols() const;
        std::vector<std::vector<T> > get_data() const;
        void set_cell(std::size_t i, std::size_t j, T val);
        T get_cell(std::size_t i, std::size_t j=0) const;

        //operators overloading
        Matrix<T> operator*(const T val);
        Matrix<T> operator+(const T val);

        Matrix<T>& operator=(const Matrix<T>& m);

        Matrix<T> operator*(const Matrix<T>& m);
        friend Matrix<T> operator* (const Matrix<T>& m, const Matrix<T>& v);
        //Vector<T> operator*(const Vector<T>& v);
        Matrix<T> operator+(const Matrix<T>& m);
        Matrix<T> power(int p);
        static Matrix<T> get_identity(std::size_t n);

        virtual ~Matrix();

    protected:
        std::size_t m_rows;
        std::size_t m_cols;
        std::vector<std::vector<T> > m_data;
};

#endif
