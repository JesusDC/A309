// Dinamyc 
// Tipo de punteros y referencias es el REAL de lo que contiene en
// cada momento.
// Palabra virtual califica como enlace dinamico en la declaracion
// de la clase.
// No hace falta añadirla en la redefiniciones de dichas funciones
// en clases derivadas

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Personaje
{
	int altura;
	//friend ostream& operator <<(ostream &o, const Personaje &p);
public:
	virtual int atacar()
	{
		/*cout << "Ataco como personaje" << endl;*/
		return 0;
	}
	virtual ostream& print(ostream& o) const
	{
		o << "Soy personaje" << endl;
		return o;
	}
};

class Guerrero :public Personaje // De ser private no hay enlace virtua y no hay up cast
{
public:
	int atacar()
	{
		cout << "Ataco como guerrero" << endl;
		return 10;
	}
	ostream& print(ostream& o) const
	{
		o << "Soy guerrero" << endl;
		return o;
	}

};

class Mago:public Guerrero
{
public:
	/*int atacar()
	{
		cout << "Ataco como mago" << endl;
		return 100;
	}*/ // Si la funcion no esta definida el virtual usa la funcino inmediatamente anterior en la derivacion
	ostream& print(ostream& o) const
	{
		o << "Soy mago" << endl;
		return o;
	}
};

// Funcion independiente para atacar cualquier tipo de la jerarquia
void atacar(Personaje &p)
{
	p.atacar();
}

void print(Personaje &p)
{
	p.print(cout);
}

ostream& operator << (ostream& o, const Personaje &p)
{
	p.print(o);
	return o;
}

void main()
{
	Mago m;
	Guerrero g;
	atacar(m);
	print(m);
	atacar(g);
	print(g);
	cout << m << g;
	int c = 10;
	cout << c << endl; // Sigue funcionando con tipos base
}

// El destructor se define como virtual como generealidad virtual
// para evitar que durante la asignacion dinamica al liberar el 
// espacio se eliminen espacios solo de clases base
