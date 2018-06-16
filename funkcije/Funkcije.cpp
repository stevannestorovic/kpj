#include "Funkcije.hpp"
#include <cmath>

double Konstanta::izracunaj(double x) const{
        return _i;
}

void Konstanta::ispisi() const{
        cout << _i;
}

Funkcija* Konstanta::kopija() const {
	return new Konstanta(_i);
}

Funkcija* Konstanta::izvod() const{
        return new Konstanta(0);
}



Funkcija* Zbir::kopija() const {
	return new Zbir(_levi->kopija(), _desni->kopija());
}

double Zbir::izracunaj(double x) const{
        return _levi->izracunaj(x) + _desni->izracunaj(x);
}

Funkcija* Zbir::izvod()const {
	return new Zbir(_levi->izvod(), _desni->izvod());
}
void Zbir::ispisi() const{
        _levi->ispisi();
        cout << " + ";
        _desni->ispisi();
}



Funkcija* Proizvod::kopija() const {
	return new Proizvod(_levi->kopija(), _desni->kopija());
}

Funkcija* Proizvod::izvod() const {
        Funkcija *p1 = new Proizvod(_levi->izvod(), _desni->kopija());
        Funkcija *p2 = new Proizvod(_levi->kopija(), _desni->izvod());
        return new Zbir(p1, p2);
}
double Proizvod::izracunaj(double x) const{
        return _levi->izracunaj(x) * _desni->izracunaj(x);
}

void Proizvod::ispisi() const{
        cout << "( ";
        _levi->ispisi();
        cout << " * ";
        _desni->ispisi();
        cout << ") ";
}



double Sinus::izracunaj(double x)const {
        return sin(x);
}
Funkcija* Sinus::kopija() const {
	return new Sinus(_f->kopija());
}

void Sinus::ispisi() const{
        cout << "sin( ";
        _f->ispisi();
        cout << " )";

}
Funkcija* Sinus::izvod()const {
        return new Proizvod(new Cosinus(_f), _f->izvod());
}

Funkcija* Cosinus::kopija() const {
	return new Cosinus(_f->kopija());
}


double Cosinus::izracunaj(double x)const {
        return cos(x);
}
Funkcija* Cosinus::izvod() const{
        return new Proizvod(new Konstanta(-1), new Proizvod(new Sinus(_f), _f->izvod()));
}
void Cosinus::ispisi() const{
        cout << "cos( ";
        _f->ispisi();
        cout << " )";
}

