#include "Vector2D.h"
#include <fstream>
#include <iostream>

Vector2D operator + (double k, Vector2D p)
{
	Vector2D res(p);
	res.x += k;
	res.y += k;
	return res;
}

ostream& operator <<(ostream& o, const Vector2D &punto)
{
	o << "[" << punto.x << "," << punto.y << "]" << endl;
	return o;
}
istream& operator >>(istream& i, Vector2D &punto)
{
	
	/*if (!p.is_valid)// DEFINIR A FUNCION ISVALID CON RETORNO DE UN BOOL
	{
		i.setstate(std::ios::failbit); // Fija el estado del flujo con un error
	}*/
	char token;
	i >> token;
	i >> punto.x;
	i >> token;
	i >> punto.y;
	return i;
}

// OPERADORES COMPARATIVOS
template<class T> // USO DE PLANTILLAS
bool operator ==(const T& lhs, const T& rhs)
{
	return(lhs.x == rhs.x && lhs.y == rhs.y);
}
bool operator !=(const Vector2D& lhs, const Vector2D& rhs)
{
	return !operator ==(lhs, rhs);
}
bool operator <(const Vector2D& lhs, const Vector2D& rhs)
{
	return (lhs.modulo() < rhs.modulo());
}
bool operator >(const Vector2D& lhs, const Vector2D& rhs)
{
	return (rhs.modulo() < lhs.modulo());
}
Vector2D operator + (Vector2D punto1, const Vector2D& punto2)
{
	punto1 += punto2;
	return punto1;
}

int main()
{
	Vector2D p1;
	Vector2D v;
	p1.x = 0;
	p1.y = 0;
	ofstream f("punto.txt", ios::out);
	ifstream g("punto.txt", ios::out);
	(p1.operator+(p1)).print(f); //salida al fichero
	//(p1.operator+(p1)).print(); // salida en pantalla
	//f.close();
	if (!p1)
	{
		p1.print();
	}
	double k = 12.5;
	Vector2D p2 = k + p1;
	p2.print();
	p2 = p2 + k;
	//p2.print();
	//cout << p2;
	p2 += p2;
	cout<<p2.to_string();
	g >> p2;
	cout << p2;
	++p2;
	cout << p2;
	f.close();
	g.close();
}