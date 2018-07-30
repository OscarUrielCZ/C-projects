typedef char* Elem;

void impElem(Elem e, int color) { printf("\e[%dm%s\e[49m", color, e); }

int esMenor(Elem e1, Elem e2) { return strcasecmp(e1, e2) <= 0; }
