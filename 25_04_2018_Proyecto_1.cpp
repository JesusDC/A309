#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class PuntoBase
{
	public:
		enum tipo_t
		{
			Estrella = 0, Cruz, Circulo
		};
		enum col_t
		{
			Azul = 0, Rojo, Negro
		};
		static string to_string_col(col_t);
		static string to_string_type(tipo_t);
		int get_id() const { return id;} // Se hace protected el print
		void set_id(int id) { this->id = id; }
	protected:
		ostream& print(ostream& o = cout) { o << "ID:" << id << endl; return o; }
	/*private:*/ protected:
		 int id;
	//public: // Hacer protected el constructor
	protected: 
		PuntoBase(int id) :id(id) {}

};

string PuntoBase::to_string_col(col_t c)
{
	string res;
	switch (c)
	{
	case Azul:
		res = "Azul";
		break;
	case Rojo:
		res = "Rojo";
		break;
	case Negro:
		res = "Negro";
		break;
	default:

		break;
	}
	return res;
}


string PuntoBase::to_string_type(tipo_t t)
{
	string res;
	switch (t)
	{
	case Estrella:
		res = "Estrella";
		break;
	case Cruz:
		res = "Cruz";
			break;
	case Circulo:
		res = "Circulo";
			break;
	default:

		break;
	}
	return res;
}


class Punto: public PuntoBase
{
	double x, y;
	public:
		Punto(int id, double x = 0.0, double y = 0.0);
		ostream& print(ostream& o = cout);
		Punto& operator =(const Punto&);
};

Punto::Punto(int id, double x , double y): PuntoBase(id), x(x), y(y){}


ostream& Punto::print(ostream& o)
{
	PuntoBase::print(o);
	o << "[" << x << "," << y << "]" << endl;
	return o;
}

Punto& Punto::operator =(const Punto& p)
{
	if (this != &p)
	{
		cout << "Realizando copia Punto" << endl;
		this->id = p.id;
		this->x = p.x;
		this->y = p.y;
		return *this;
	}	// Al hacer esto no hay copia con = en PUNTO BASE por lo que si no se define la copia de id
	else
	{
		cout << "No es posible copiarme a mi mismo" << endl;
	}

}


class PuntoGordo:public Punto
{
	tipo_t forma;
	col_t color;
	
	public:
		PuntoGordo(const Punto&/*int id, double x = 0.0, double y = 0.0*/, tipo_t forma = Estrella, col_t color = Negro);
		ostream& print(ostream& o = cout);
		PuntoGordo& operator =(const PuntoGordo&);
		PuntoGordo(const PuntoGordo&); // Constructor copia // Si no hay arriba no copiara los parámetros de clases base si no se especifica


};

PuntoGordo::PuntoGordo(const Punto& p, tipo_t t, col_t c) :Punto(p) 
{
	this->forma = t;
	this->color = c;
}

PuntoGordo::PuntoGordo(const PuntoGordo& p):Punto(p)
{

}

ostream& PuntoGordo::print(ostream& o) 
{
	Punto::print(o);
	o << to_string_type(this->forma) << endl;
	o << to_string_col(this->color) << endl;
	return o;
}

PuntoGordo& PuntoGordo::operator =(const PuntoGordo& p)
{
	if (this != &p)
	{
		cout << "Realizando copia PuntoGordo" << endl;
		Punto::operator=(p);
		this->forma = p.forma;
		this->color = p.color;
		return *this;
	}	// Al hacer esto no hay copia en con = en PUNTO BASE
	else
	{
		cout << "No es posible copiarme a mi mismo" << endl;
	}

}

void foo(Punto& p)
{
	p.print();
}

int main()
{
	//PuntoBase p(1); // Constructor protected por lo que no se puede
	Punto punto1(8, 1.0, 3.0);
//	punto1.print();
	//punto1.PuntoBase::print(); // Print prtoected por lo que no se puede
	//p.print(); // Print prtoected por lo que no se puede
	PuntoGordo puntogordo1(punto1, PuntoGordo::Estrella, PuntoGordo::Azul);
//	puntogordo1.print();

	// UPCAST y SLICING
//	foo(punto1);
//	foo(puntogordo1);

	PuntoGordo * pPG;
	pPG = &puntogordo1;
//	pPG->print();
	Punto * pP;
	pP = pPG;
//	pP->print();
/////////////////////////////////////////////////////////////////////

	// IGUALAR PUNTOS (ASIGNAR)

	Punto punto2(punto1);
	PuntoGordo puntogorodo2(puntogordo1); // Copia superficial.
	puntogordo1.print();
	puntogordo1.set_id(100);
	puntogordo1.print();
	puntogorodo2 = puntogordo1;
	puntogorodo2.print();


///////////////////////////////////////////////////////////////
}