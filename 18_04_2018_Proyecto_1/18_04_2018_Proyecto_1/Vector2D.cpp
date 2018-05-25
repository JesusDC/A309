#include <iostream>
#include "Vector2D.h"
#include <math.h>

using namespace std;

Vector2D::~Vector2D()
{
}

Vector2D Vector2D::operator +(Vector2D b)
{
	Vector2D res(*this);
	res.x += b.x;
	res.y += b.y;
	return res;
}

ostream& Vector2D::print(ostream& o) const
{
	o << "[" << this->x << "," << this->y << "]" << endl;
	return o;
}

bool Vector2D::operator ! ()
{
	return  (this->x == 0.0 && this->y == 0.0); // retorna un TRUE si se verifica la declaración entre parentesis
}

Vector2D Vector2D::operator +(double k)
{
	Vector2D res(*this);
	res.x += k;
	res.y += k;
	return res;
}

string Vector2D::to_string()
{
	stringstream sstr;
	sstr << "[" << this->x << "," << this->y << "]"<<endl;
	string res(sstr.str());
	return res;
}

double Vector2D::modulo() const
{
	double res;
	res = sqrt(x*x + y * y);
	return res;
}

Vector2D& Vector2D::operator +=(const Vector2D &punto)
{
	this->x += punto.x;
	this->y += punto.y;
	return *this;
}

Vector2D& Vector2D::operator ++()
{
	this->x += 1.0;
	this->y += 1.0;
	return *this;
}