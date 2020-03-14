#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include "vector.h"
using namespace std;

int main(){

    try{
        Matrix<double> a(2, 3, 1);
        Matrix<double> b(3, 3, 1.1);

        a = b;

        a.print();
        b.print();
        //(a*4.1).print();
        //(a*b).print();
        //(b.power(0)).print();

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
