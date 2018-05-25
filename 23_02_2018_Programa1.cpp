	// Hola mundo en un fichero, extraer lineas, extraer numeros x e y
#define SIZE_OF_LINE 250
#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM_PUNTOS 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyStruct
{
	float x;
	float y;
}punto_t; 

punto_t lista_puntos[MAX_NUM_PUNTOS];

void main()
{
	int POS_PUNTO = 0;
	int n, m;
	char token;
	char word[50];
	char line [SIZE_OF_LINE];
	FILE* f = fopen("hola.txt", "r");
	if (!f)
	{
		perror("Error al leer el archivo");
		return;
	}
	// Parse linea a linea
	while (!feof(f))
	{
		fgets(line, 250, f);
		if (ferror(f))
		{
			printf("Error al leer la linea.\nAcabo la lectura.");
		}
		//printf("%s", line);
		//Protocolo x e y
		if (line[0]== '\n' || line [0] == '\0')
		{
			continue;
		}
		switch (line[0])
		{
		case 'c':
			break;
		case 'p':
			sscanf("%c %c %d %d", &token, word, &n, &m);
			if (4!= sscanf("%c %c %d %d", &token, word, &n, &m))
			{
				printf("Error al leer la cadena");
				return;
			}
			break;
		case 'e':

		default:
			break;
		}
		sscanf(line, "%f %f", &lista_puntos[POS_PUNTO].x, &lista_puntos[POS_PUNTO].y);
		printf("%.2f %.2f\n", lista_puntos[POS_PUNTO].x, lista_puntos[POS_PUNTO].y);
		POS_PUNTO++;
	}
	fclose(f);
}