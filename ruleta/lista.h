typedef struct NodoL
{
	Elem_lista dato;
	struct NodoL *sig;
} *Lista;

Lista vacia() { return NULL; }

Lista cons(Elem_lista e, Lista l)
{
	Lista t = (Lista)malloc(sizeof(struct NodoL));
	t->dato = e;
	t->sig = l;
	return t;
}

int esVacia(Lista l) { return l == NULL; }

Elem_lista cabeza(Lista l) { return l->dato; }

Lista resto(Lista l) {return l->sig; }

int numElem(Lista l)
{
	if(esVacia(l))
		return 0;
	else
		return 1 + numElem(resto(l));
}

void impLista(Lista l)
{
	if(!esVacia(l))
	{
		impElemL(cabeza(l));
		impLista(resto(l));
	}
}

Lista insOrd(Elem_lista e, Lista l)
{
	if(esVacia(l))
		return cons(e, l);
	else if(esMenorL(e, cabeza(l)))
		return cons(e, l);
	else
		return cons(cabeza(l), insOrd(e, resto(l)));
}

Lista ordLista(Lista l)
{
	if(esVacia(l))
		return l;                  
	else 
		return insOrd(cabeza(l), ordLista(resto(l)));
}

Lista concat(Lista l1, Lista l2)
{
	if(esVacia(l1))
		return l2;
	else 
		return cons(cabeza(l1), concat(resto(l1), l2));
}

Lista invierte(Lista l)
{
	if(esVacia(l))
		return l;
	else
		return concat(invierte(resto(l)), cons(cabeza(l), vacia()));
}
