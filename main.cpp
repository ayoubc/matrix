#include <iostream>
#include <stdio.h>
#include "matrix.h"
#include "vector.h"
using namespace std;

int main(){

    try{
        /*vector<vd> v;
        for(int i=0; i<3; i++) {
            vector<double> tmp;
            for(int j=0;j<3;j++){
                tmp.push_back(i+j);
            }
            v.push_back(tmp);
        }
        Matrix a(3, v);*/
        Matrix a(3, 1);
        Vector v(3, 2);
        a.print();
        v.print();

        (a*v).print();
    }
    catch(const char* msg){
        //printf("%s\n", msg);
        cout << msg << endl;
    }
    return 0;
}
