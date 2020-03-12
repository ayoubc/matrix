#ifndef DEF_MATRIX_H
#define DEF_MATRIX_H

#include <vector>
#include "vector.h"
typedef std::vector<double> vd;
//template<typename T>
class Matrix {
    public:
        Matrix(std::size_t n, double initial_value=0.0);
        Matrix(std::size_t n, std::vector<vd> t_data);
        Matrix(const Matrix& m);

        void print() const;
        std::size_t get_dimension() const;
        std::vector<vd> get_data() const;
        void set_cell(std::size_t i, std::size_t j, double val);
        double get_cell(std::size_t i, std::size_t j) const;
        Matrix operator*(const double val);
        Matrix operator*(const Matrix m);
        Vector operator*(const Vector v);
        Matrix operator+(const Matrix m);
        Matrix power(int p);
        static Matrix get_identity(std::size_t n);

        ~Matrix();

    private:
        std::size_t m_dim;
        std::vector<vd> m_data;
};

#endif
