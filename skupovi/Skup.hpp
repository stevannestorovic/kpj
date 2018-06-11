#ifndef _SKUP_H
#define _SKUP_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>

using namespace std;
class Skup: public Set {
public:
	Skup();
	int kardinalnost();
	void ispisi();
	bool sadrzi(int x);
private:
	vector<int> _elementi;

};
#endif
