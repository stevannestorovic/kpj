#ifndef _FUNKCIJE_HPP
#define _FUNKCIJE_HPP 1
#include <iostream>
#include <string>

using namespace std;

class Funkcija {
public: 
        virtual double izracunaj(double x) const = 0;
        virtual Funkcija* izvod()const=0;
	virtual Funkcija* kopija()const = 0;
        virtual void ispisi() const = 0;
};

class Konstanta : public Funkcija {
public:
        Konstanta(int i): _i(i) {}
        double izracunaj(double x) const;
	Funkcija* kopija()const;
        Funkcija* izvod()const;
        void ispisi() const;
private:
        double _i;
};

class Id : public Funkcija {
public:
        Id() {}
        double izracunaj(double x) const {return x;}
	Funkcija* kopija()const {return new Id();}
        Funkcija* izvod()const {return new Konstanta(1);}
        void ispisi() const {cout << "x";}
};

class BinOp: public Funkcija {
public:
        BinOp(Funkcija *l, Funkcija *d) {_levi=l->kopija(); _desni=d->kopija();}
protected:
        Funkcija *_levi;
        Funkcija *_desni;
};       

class Zbir : public BinOp {
public:
        Zbir(Funkcija *l, Funkcija *d):BinOp(l, d) {}
        double izracunaj(double x) const;
	Funkcija* kopija()const;
        Funkcija* izvod()const;
        void ispisi() const ;
};

class Proizvod : public BinOp {
public:
        Proizvod(Funkcija *l, Funkcija *d):BinOp(l, d) {}
        double izracunaj(double x) const;
	Funkcija* kopija()const;
        Funkcija* izvod()const;
        void ispisi() const;
};

class Sinus : public Funkcija {
public:
        Sinus(Funkcija* f){_f = f;}
        double izracunaj(double x) const;
	Funkcija* kopija()const;
        Funkcija* izvod()const;
        void ispisi() const;
private:
        Funkcija *_f;
};

class Cosinus : public Funkcija {
public:
        Cosinus(Funkcija* f) {_f = f;}
        double izracunaj(double x) const;
	Funkcija* kopija()const;
        Funkcija* izvod()const;
        void ispisi() const;
private:
        Funkcija *_f;
};

#endif
