#ifndef _MATRIX_HPP
#define _MATRIX_HPP 1
#include <vector>
#include <iostream>
using namespace std;
class Matrix {
public:
        Matrix();
//      Matrix(const Matrix& m);
        void ispisi() const;
        vector<vector<double> > getElem();
        void dodajVrstu(vector<double> v);
/*        Matrix saberi(Matrix m);
        Matrix pomnozi(Matrix m);
        Matrix oduzmi(Matrix m);
        Matrix skalarnoPomnozi(double x);*/

private:

        vector<vector<double> > _elem;
};

#endif
