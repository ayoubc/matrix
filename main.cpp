#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include "vector.h"
using namespace std;

int main(){

    try{
        //Matrix<double> a(2, 3);
        //Matrix<double> b(3, 3);

        //a = b;

        //a.print();
        //b.print();
        //(a*4.1).print();
        //(a*b).print();
        //(b.power(0)).print();
        //Matrix<double> *v = new Vector<double>(2, 1.2);
        Vector<double> v(2, 1.2);
        Vector<double> k(v);
        k = k+2;
        //v.print();

        /*vector<vector<double> > V = v.get_data();
        for(int i=0 ; i < V.size(); i++) {
            for(int j=0; j<V[i].size(); j++) {
                cout << V[i][j] << endl;
            }
        }*/
        //cout << k.magnitude() << endl;
        (k).print();
        //k.print();
        //delete v;
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
