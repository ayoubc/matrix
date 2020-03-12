#include "matrix.h"
#include <stdio.h>
using namespace std;

size_t Matrix::get_dimension() const {
    return this->m_dim;
}

vector<vd> Matrix::get_data() const {
    return this->m_data;
}

Matrix::Matrix(size_t n, double initial_value): m_dim(n) {

    this->m_data.resize(n);
    for(size_t i = 0;i < n; i++) {
        this->m_data[i].resize(n, initial_value);
    }
}

Matrix::Matrix(size_t n, vector<vd> t_data): m_dim(n), m_data(t_data) {}

// constructor by copy
Matrix::Matrix(const Matrix& m): m_dim(m.get_dimension()), m_data(m.get_data()) {}

void Matrix::print() const {
    size_t n = this->get_dimension();
    /*printf("/ ");
    for(size_t i = 0;i < n; i++) {
        printf(" ");
    }
    printf("\\\n");
    */
    for(size_t i = 0;i < n; i++) {
        printf("| ");
        for(size_t j = 0; j < n; j++) {
            printf("%.2f ", this->get_cell(i, j));
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

void Matrix::set_cell(size_t i, size_t j, double val) {
    this->m_data[i][j] = val;
}

double Matrix::get_cell(size_t i, size_t j) const {
    return this->m_data[i][j];
}

// multiply a matrix by a scalar
Matrix Matrix::operator*(const double val){
    size_t n = this->get_dimension();
    Matrix c(n);
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            c.set_cell(i, j, this->get_cell(i, j) * val);
        }
    }
    return c;
}
// multiply a matrix by an other
Matrix Matrix::operator*(const Matrix m){
    size_t n = this->get_dimension();
    Matrix c(n);
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            double sum = 0.0;
            for(size_t k = 0; k < n; k++) {
                sum += this->get_cell(i, k) * m.get_cell(k, j);
            }
            c.set_cell(i, j, sum);
        }
    }
    return c;
}

Vector Matrix::operator*(const Vector v){
    size_t n = this->get_dimension();
    Vector c(n);
    for (size_t i = 0; i < n; i++){
        double sum = 0.0;
        for (size_t k = 0; k < n; k++){
            sum += this->get_cell(i, k) * v.get_cell(k);
        }
        c.set_cell(i, sum);
    }
    return c;
}
// matrix addition
Matrix Matrix::operator+(const Matrix m) {
    size_t n = this->get_dimension();
    Matrix c(n);
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            c.set_cell(i, j, this->get_cell(i, j) + m.get_cell(i, j));
        }
    }
    return c;
}

// matrix power
Matrix Matrix::power(int p) {
    if(p == 0) return Matrix::get_identity(this->get_dimension());
    if(p == 1) return *this;

    Matrix b = this->power(p/2);
    b = b*b;
    if(p%2 != 0){
        b = b * (*this);
    }
    return b;
}

Matrix Matrix::get_identity(size_t n) {
    Matrix id(n);
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            double val = (i == j ? 1.0 : 0.0);
            id.set_cell(i, j, val);
        }
    }
    return id;
}
Matrix::~Matrix() {
    this->m_data.clear();
}
