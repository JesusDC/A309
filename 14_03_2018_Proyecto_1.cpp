#define _CRT_SECURE_NO_WARNINGS
#include "iostream" // cout y cin
#include "fstream" // fichero
#include "sstream" // cadenas de char
#include "string.h"


using namespace std;

struct datos_t {
	char nombre[100];
	char course[100];
	int id;
	int id_grupo;
};

stringstream& format_string(datos_t& d, stringstream& o)
{
	cout << "Nombre: " << d.nombre << endl;
	o << "Asignatura: " << d.course << endl;
	o << "matricula_id: " << d.id << endl;
	o << "group_id: "<< d.id_grupo << endl;
	return o;
}
/*
void print_string(string str) // Si se hiciera con & podria modificarse y no genera una copia de la cadena.
{
	cout << str << endl;
}

void print_dato(datos_t &d)
{

}

stringstream& print_dato(const datos_t &d, stringstream& sstr)
{

	return sstr;
}*/

ostream& print_dato(const datos_t& d, ostream& o)
{
	o << "Nombre: " << d.nombre << endl;
	o << "Asignatura: " << d.course << endl;
	o << "matricula_id: " << d.id << endl;
	o << "group_id: " << d.id_grupo << endl;
	return o;
}


void main()
{
	datos_t dato;
	stringstream sstr ("");
	strcpy(dato.nombre, "Jesus");
	strcpy(dato.course, "Infomratica");
	dato.id = 52313;
	dato.id_grupo = 309;

	ofstream f("log.txt", ofstream::out);
	if (!f)
	{
		cout << "ERROR AL ABRIR EL FICHERO" << endl;
	}
	//cout << format_string(dato, sstr).str() << endl;
	//print_dato(dato, f);
	f.close();
	cout << ofstream::out << endl;
}

////////////////////////////////////////////


		//Paso argumentos main

/*int main(char argc, char** argv)
{
	if (argc!=2)
	{
		cout << "Por favor rellene correctamente los parametros del programa: " << endl;
		return -1;
	}
	cout << "El primer parametro es: " << argv[0] << endl;
	cout << "El segundo parametro es: " << argv[1] << endl;
	return 1;
}*/

