#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include "vector.h"
using namespace std;
template<typename T>
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

int main(){

    try{

        Vector<double> v(2, 1);
        Matrix<double> m(3, 2, 1.0);
        //m.print();

        Matrix<double> m2 = m*v;
        //m2.print();
        Vector<double> v2 = m*v;
        //v2 = v;

        v2.print();
        cout << v2.magnitude() << endl;
        //v2.print();
    }
    catch(const char* msg){
        //printf("%s\n", msg);
        cout << msg << endl;
    }
    /*catch(exception exc){
        //printf("%s\n", msg);
        cout << exc.what() << endl;
    }*/
    return 0;
}
