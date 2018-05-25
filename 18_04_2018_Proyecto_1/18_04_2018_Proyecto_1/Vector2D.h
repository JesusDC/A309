#pragma once
#include <sstream>
#include <iostream>

using namespace std;

class Vector2D
{
public:
	float x;
	float y;
	~Vector2D();
	Vector2D() :x(0.0), y(0.0) {}
	Vector2D operator + (Vector2D);
	bool operator ! ();
	ostream& print(ostream& = cout) const;
	Vector2D operator +(double k);
	friend ostream& operator <<(ostream& os, const Vector2D &punto);
	//convertir a string
	string to_string();
	double modulo() const;
	Vector2D& operator +=(const Vector2D &punto);
	Vector2D& operator ++();
};

