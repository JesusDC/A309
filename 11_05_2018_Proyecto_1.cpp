// Funcion virtual pura sin esqueleto ni definicion
// virtual <tipo> <id_funcion> <argumentos> = 0 
// Constructores no de heredan

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Objeto // Clase abstracta
{
	int size;
	int proze;
public:
	virtual string get_name() = 0; // Funcion virtual pura
	// Contrato para que todos tengan las derivadas lo cumplan
	virtual int get_grosor() = 0;

};

class Armas:public Objeto // Vuelve a ser una clase abstracta ya que le metodo tampoco existe
{
	int grosor;
public:
	int get_grosor() { return grosor; } // Sigue siendo abstracta por lo que no es una entidad completa
};

class Espada:public Armas
{
	string name;
public:
	string get_name() { return name; }
	Espada(string str = "Tizona") :name(str) {};
};

// Ejempldo de uso de la jerarquia
string foo(Objeto *o)
{
	return (o->get_name());
}

void main()
{
	//Objeto o; // No se puede
	Espada e;
	cout << e.get_name() << endl;
	cout << foo(&e) << endl;
	Objeto *po = new Espada("Excalibur");
	cout << foo(po) << endl;
}

// <<Inteface>>