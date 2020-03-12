#include "vector.h"
#include <stdio.h>
using namespace std;

size_t Vector::get_dimension() const {
    return this->m_dim;
}

vector<double> Vector::get_data() const {
    return this->m_data;
}

Vector::Vector(size_t n, double initial_value): m_dim(n) {
    this->m_data.resize(n, initial_value);
}

Vector::Vector(size_t n, vector<double> t_data): m_dim(n), m_data(t_data) {}

Vector::Vector(const Vector& v): m_dim(v.get_dimension()), m_data(v.get_data()) {}

void Vector::print() const {
    printf("[ ");
    for(size_t i = 0;i < this->m_dim; i++) {
        printf("%.2f ", this->get_cell(i));
    }
    printf("]\n");
}

void Vector::set_cell(size_t i, double val) {
    this->m_data[i] = val;
}

double Vector::get_cell(size_t i) const {
    return this->m_data[i];
}


Vector Vector::operator*(const double val){
    size_t n = this->m_dim;
    Vector c(n);
    for (size_t i = 0; i < n; i++){
        c.set_cell(i, this->get_cell(i) * val);
    }
    return c;
}

Vector Vector::operator+(const Vector v) {
    size_t n = this->m_dim;
    Vector c(n);
    for (size_t i = 0; i < n; i++){
        c.set_cell(i, this->get_cell(i) + v.get_cell(i));
    }
    return c;
}

Vector::~Vector() {
    this->m_data.clear();
}
