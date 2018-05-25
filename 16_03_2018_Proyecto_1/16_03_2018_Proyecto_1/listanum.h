#pragma once
// Lista elemen
#define _CTR_SECURE_NO_WARNINGS_
#define MAX_ELEM 100
#define MYMAX 0x1FFFFFFF
#include "iostream" // cout y cin
#include "fstream" // fichero
#include "sstream" // cadenas de char

/* Multitipo
template ListaNum <int>;
template ListaNum <float>;
template ListaNum <double>;
*/

/*template <class T>*/

class ListaNum
{
private:
	int nElem;
	/*T*/int lista[MAX_ELEM];
public:
	ListaNum() { nElem = 0; };
	void add_elem (int dato);
	/*T*/int get_elem (int pos);
	int get_size ();
	/*T*/int pop();
	std::ostream& print(std::ostream& o);
};