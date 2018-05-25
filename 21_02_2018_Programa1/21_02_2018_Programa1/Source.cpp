#define _CTR_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Colecciones
// Acceso aleatorio a memoria ARRAY (puede atacar la direccion de memoria de la estructura de la forma que quiera)
// Ejemplo int array[10]
// Aceceso no aleatorio a memoria LISTA ()

// Asignación dinámica de memoria. Malloc

/*int num[10];
int* num_var;*/

/*void main() {
num_var = (int*)malloc(10 * sizeof(int)); // malloc devuelve un void, por lo que se le exige que devuelva un int* con el () previo a la función
// malloc reserva un array
num_var[8] = 5;
*num_var
}*/

// Malloc para 2 dimensiones

/*int ** matrix = 0;

void main() {
int n = 10, m = 20, i = 0;
matrix = (int**)malloc(n * sizeof(int*));
printf("%d\n", matrix);
for (i = 0; i < n; i++) {
matrix[i] = (int*)malloc(m * sizeof(int));
printf("%d\n", matrix[i]);
}
for (i = 0; i < n; i++) {
free(matrix[i]);
}
free(matrix);
} */

// Nodos para centroides

typedef struct nodo {
	int dato;
	struct nodo* siguiente;
} nodo_t;

nodo_t *head; //Cabecera
			  //Operadores

nodo_t* nuevo_elemento() {

	nodo_t* elem = NULL;
	elem = (nodo_t*)malloc(sizeof(nodo_t) * 1);
	if (elem == NULL) {
		printf("No se pudo reservar la memoria.\n");
	}
	return elem;
}

void init(int dato) {
	head = nuevo_elemento();
	head->dato = dato;
	head->siguiente = NULL;
}

void instert_back(int dato)
{
	nodo_t* elem_nuevo;
	nodo_t* actual;
	actual = head;

	//Buscar el ultimo elemento de la cadena
	while (actual->siguiente != NULL) {
		actual = actual->siguiente;
	}
	//Generear el nuevo
	elem_nuevo = (nodo_t*)malloc(sizeof(nodo_t));
	elem_nuevo->dato = dato;
	elem_nuevo->siguiente = NULL;
	// Se ubica al final
	actual->siguiente = elem_nuevo;
}

void pop_back() {
	nodo_t *actual = NULL;
	nodo_t *anterior = NULL;
	actual = head;
	//Buscar el penultimo
	while (actual->siguiente != NULL)
	{
		anterior = actual;
		actual = actual->siguiente;
	}
	//Elimino el ultimo
	free(actual);
	anterior->siguiente = NULL;
}

int get_size()
{
	int res = 0;
	nodo_t *actual = NULL;
	actual = head;
	while (actual != NULL)
	{
		actual = actual->siguiente;
		res++;
	}
	return res;
}

int remove(int dato)
{
	nodo_t *actual = NULL;
	nodo_t *anterior = NULL;
	if (!head)
	{
		return -1;
	}
	actual = head;
	// Cabeza en el dato
	if (head->dato == dato)
	{
		head = actual->siguiente;
		free(actual);
		return(dato);
	}
	//Cabeza no es dato
	while (actual->siguiente != NULL)
	{
		anterior = actual;
		actual = actual->siguiente;
		//Compruebo dato
		if (actual->dato == dato)
		{
			anterior->siguiente = actual->siguiente;
			free(actual);
			return(dato);
		}
	}
}