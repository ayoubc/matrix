#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include "vector.h"
using namespace std;

int main(){

    /*vector<vector<double>> v = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    }*/

    Matrix a(3, 1.0);
    Vector v(3, 2.0);
    (a*v).print();
    /*Matrix c(3, 1.0);
    Matrix b = a.power(10) + c;

    a.print();
    b.print();


    b.print();
    */


    return 0;
}
