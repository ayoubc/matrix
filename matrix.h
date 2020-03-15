#ifndef DEF_MATRIX_H
#define DEF_MATRIX_H

#include <vector>
//#include "vector.h"

template<typename T>
class Matrix {
    public:
        Matrix(std::size_t t_rows, std::size_t t_cols, T initial_value=0);
        Matrix(const Matrix<T>& m);

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
        //Vector operator*(const Vector v);
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
