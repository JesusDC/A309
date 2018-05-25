#include "listanum.h"

/*template <class T>*/
using namespace std;

/*template <class T>*/
void ListaNum::add_elem(int dato) 
{
	if (nElem<MAX_ELEM)
	{
		lista[nElem++] = dato;
	}
}


/*template <class T>*/
int ListaNum::get_elem(int pos)
{
	if (pos < nElem-1)
	{
		return lista[pos];
	}
	return MYMAX;
}


/*template <class T>*/
int ListaNum::get_size() // T ListaNum<T>
{
	return nElem;
}



/*template <class T>*/
std::ostream& ListaNum::print(std::ostream& o)
{
	o << "[";
	for (int i = 0; i < nElem; i++)
	{
		o << lista[i] <<" ";
	}
	o << "]" << " ["<<nElem<<"] ";
	return o;
}

int ListaNum::pop()
{
	nElem--;
	return lista[nElem];
}
