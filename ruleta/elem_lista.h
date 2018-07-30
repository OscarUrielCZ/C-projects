typedef struct {
	char *nombre;
	int na; //numero de apuesta
	long int cantidad;
} Elem_lista;

Elem_lista consElemL(char *nom, int na, long int cant) {
	Elem_lista e;
	char* pal = (char*)malloc(25);
	strcpy(pal, nom);
	e.nombre = pal;
	e.na = na;
	e.cantidad = cant;

	return e;
}

int num_ap(Elem_lista e) { return e.na; }
long int cantidad_ap(Elem_lista e) { return e.cantidad; }

Elem_lista registrarElemL(int na) {
	char nombre[25];
	long int cantidad;

	printf("Nombre: " );
	scanf("%s", nombre);
	printf("Cantidad: ");
	scanf("%li", &cantidad);

	return consElemL(nombre, na, cantidad);
}

void impElemL(Elem_lista e) { 
	printf("Nombre: %s\n", e.nombre);
	//printf("Apostando: %li dolares.\n", e.cantidad); 
}

int esMenorL(Elem_lista e1, Elem_lista e2) { return strcasecmp(e1.nombre, e2.nombre) <= 0; }
