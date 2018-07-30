typedef struct Nodo {
	Elem dato;
	struct Nodo *sig;
} *Circular;

int esNueva(Circular q) { return q == NULL; }

Circular nueva() { return NULL; }

Circular formar(Circular q, Elem e) { 
	Circular t = (Circular)malloc(sizeof(struct Nodo));
	t -> dato = e;
	if(esNueva(q)) {
		q = t;
		q -> sig = t;
	}
	else {
		t -> sig = q -> sig;
		q -> sig = t;
	}
	
	return t;
}

Elem primero(Circular q) { return q -> sig -> dato; }

Circular desformar(Circular q) {
	Circular t = q -> sig;
	if(q == q -> sig) {
		free(t);
		return NULL;
	}
	else {
		q ->sig = t -> sig; //q -> sig = q -> sig -> sig
		free(t);
		return q; //efecto colateral, tambien afectamos la cola original en el main
	}
}

Circular rotar(Circular q) { return q->sig; }

void impCircular(Circular q) {
	Circular t = q;
	if(!esNueva(q))
		do {
			impElem(primero(t), 46);
			t =rotar(t);
		} while(t != q);
}

Elem info(Circular q, int pos) {
	Circular cent = q;
	int i;

	for(i=0;i<pos; i++) cent = cent->sig;

	return cent->sig->dato;
}
