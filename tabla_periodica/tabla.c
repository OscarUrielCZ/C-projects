#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t
{
	char* nombre;
	char* simbolo;
	char* numero;
	char* masa;
}Elemento;


Elemento leerElemento(FILE*);
void imprimirElemento(Elemento);

void inicializa(FILE*, Elemento [], int);
void cargarTabla(FILE*, Elemento [], int);
void ordena(Elemento [], int);

void intercambiar(Elemento [], int, int);
int esmayor(char* a, char* b) { return strcasecmp(a, b) > 0; }
int esmenor(char* a, char* b) { return strcasecmp(a, b) < 0; }
int buscar(Elemento [], char [], int, int*);

int main() {
	char *nombre_archivo = "elementos.txt";
	FILE* aa = fopen(nombre_archivo, "r");
	Elemento e[120];
	int n = 118;
	char pal[40];
	int estado = 0, m;
	inicializa(aa, e, n);
	
	puts("Escribe el elemento a buscar: ");
	scanf("%s", pal);
	
	m = buscar(e, pal, n, &estado); //binary search algorithm
	
	puts("");
	if(estado)
		imprimirElemento(e[m]);
	else
		puts("No se ha encontrado el elemento");
	
	return 0;

}

int tamano(char* pal)
{
	int i = 0;
	while(pal[i])
		i++;
	return i;
}

Elemento leerElemento(FILE* aa)
{
	Elemento e;
	char pal[40];
	
	fscanf(aa, "%s", pal);
	e.nombre = (char*)malloc(tamano(pal)+1);
	strcpy(e.nombre, pal);
	
	fscanf(aa, "%s", pal);
	e.simbolo = (char*)malloc(tamano(pal)+1);
	strcpy(e.simbolo, pal);
	
	fscanf(aa, "%s", pal);
	e.numero = (char*)malloc(tamano(pal)+1);
	strcpy(e.numero, pal);
	
	fscanf(aa, "%s", pal);
	e.masa = (char*)malloc(tamano(pal)+1);
	strcpy(e.masa, pal);
	
	return e;
}

void imprimirElemento(Elemento e)
{
	printf("\tNumero atomico: 	%s\n", e.numero);
	printf("\tSimbolo:		%s\n", e.simbolo);
	printf("\tNombre: 		%s\n", e.nombre);
	printf("\tMasa: 			%s\n", e.masa);
}

void inicializa(FILE* aa, Elemento e[], int n)
{
	cargarTabla(aa, e, n);
	ordena(e, n);
}

void cargarTabla(FILE* aa, Elemento e[], int n)
{
	for(int i = 0; i < n; i++)
		e[i] = leerElemento(aa);
}

void ordena(Elemento e[], int n)
{
	for(int j = 0; j < n-1; j++)
		for(int i = 0; i < n-1-j; i++)
			if(esmayor(e[i].nombre, e[i+1].nombre))
				intercambiar(e, i, i+1);
}

void intercambiar(Elemento e[], int a, int b)
{
	Elemento aux;
	aux.nombre = e[a].nombre;
	aux.simbolo = e[a].simbolo;
	aux.numero = e[a].numero;
	aux.masa = e[a].masa;
	
	e[a].nombre = e[b].nombre;
	e[a].simbolo = e[b].simbolo;
	e[a].numero = e[b].numero;
	e[a].masa = e[b].masa;
	
	e[b].nombre = aux.nombre;
	e[b].simbolo = aux.simbolo;
	e[b].numero = aux.numero;
	e[b].masa = aux.masa;
}

int buscar(Elemento e[], char pal[], int n, int* estado)
{
	int L = 0, R = n-1, m;
	while(L <= R)
	{
		m = (L + R) / 2 ;
		if(esmenor(e[m].nombre, pal))
			L = m + 1;
		else if(esmayor(e[m].nombre, pal))
			R = m - 1;
		else if(strcasecmp(e[m].nombre, pal) == 0) 
		{
			*estado = 1;
			break;
		}
	}
	return m;
}
