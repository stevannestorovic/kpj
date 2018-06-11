#include "Skup.hpp"
using namespace std;


void Skup::ispisi() {
	cout << "{";
	for(int i = 0; i < _elementi.size()-1; i++) {
		cout << _elementi[i] << ", ";
	}
	cout << _elementi[_elementi.size()-1] << "}" << endl;
}
