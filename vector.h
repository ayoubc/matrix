#ifndef DEF_VECTOR_H
#define DEF_VECTOR_H

#include <vector>

class Vector {
    public:
        Vector(std::size_t n, double initial_value=0.0);
        Vector(std::size_t n, std::vector<double> t_data);
        Vector(const Vector& v);

        void print() const;
        std::size_t get_dimension() const;
        std::vector<double> get_data() const;
        void set_cell(std::size_t i, double val);
        double get_cell(std::size_t i) const;
        double magnitude();
        Vector operator*(const double val);
        Vector operator+(const Vector v);

        ~Vector();


    private:
        std::size_t m_dim;
        std::vector<double> m_data;
};

#endif
