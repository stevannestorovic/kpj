#include "Matrix.hpp"

Matrix::Matrix() {
        _elem.resize(0);
}
/*
Matrix::Matrix(const Matrix& m) {
        _elem = m.getElem();
}*/

vector<vector<double> > Matrix::getElem() {
        return _elem;
}

void Matrix::ispisi() const {
        for(int i = 0; i < _elem.size(); i++) {
                cout << "|";
                for(int j = 0; j < _elem[0].size(); j++) {
                        cout << _elem[i][j] << " ";
                }
                cout << "|" << endl;
        }
}

void Matrix::dodajVrstu(vector<double> v) {
       // _elem.resize(_elem.size()+1);
        _elem.push_back(v);
}


/*
int main() {
        Matrix m;
        vector<double> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        m = Matrix();
        m.dodajVrstu(v);
        m.ispisi();

}
*/
