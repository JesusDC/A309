#include <string>
#include <iostream> // cout y cin
#include <fstream> // fichero
#include <sstream> // cadenas de char
#include "listanum.h"

using namespace std;

int main()
{
	ListaNum l;
	l.add_elem(10);
	l.add_elem(20);
	// Salida en pantalla
	l.print(cout);

	// Salida fichero
	ofstream f("log.txt");
	if (f)
	{
		l.print(f);
		f.close();
	}

}