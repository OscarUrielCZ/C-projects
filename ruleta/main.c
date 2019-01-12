#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "elem.h"
#include "circular.h"
#include "elem_lista.h"
#include "lista.h"

void esperar() { fflush(stdin); getchar(); fflush(stdin); }
void limpiar() { system("clear"); }
void espacios(int n) { int i; for(i=0;i<n;i++) printf(" "); }
void delay(int);
void menu_simple();
Circular inicializaRueda(Circular);
int ap_espec();
int val(int, int, char *);
int colorde(char *);
void simular(Circular);
Circular girar(Circular);
void pagarganadores(Lista, Elem);
int similitud_simple(Elem_lista, Elem);

int main() {
	Lista apostadores = vacia();
	Circular rueda = nueva();;;;;;;;;;;
	Elem_lista e;
	int na, seguir;
	char ta;
	
	srand(time(NULL));
	rueda = inicializaRueda(rueda);
	limpiar();

	puts("Presiona ENTER para comenzar el juego.");
	esperar();

	for(;;) {
		limpiar();
		menu_simple();
		na = ap_espec();
		e = registrarElemL(na);
		apostadores = cons(e, apostadores);

		printf("Seguir[1/0]: ");
		scanf("%d", &seguir);

		if(!seguir)
			break;
		printf("\n");
	}

	rueda = girar(rueda);

	esperar();
	limpiar();

	printf("Numero ganador: \n");
	impElem(primero(rueda), colorde(primero(rueda)));
	printf("\n\n");

	esperar();

	pagarganadores(apostadores, primero(rueda));

	printf("Gracias por jugar\n");

	return 0;
}

Circular inicializaRueda(Circular rueda) {
	rueda = formar(rueda, "0");
	rueda = formar(rueda, "28");
	rueda = formar(rueda, "9");
	rueda = formar(rueda, "26");
	rueda = formar(rueda, "30");
	rueda = formar(rueda, "11");
	rueda = formar(rueda, "7");
	rueda = formar(rueda, "20");
	rueda = formar(rueda, "32");
	rueda = formar(rueda, "17");
	rueda = formar(rueda, "5");
	rueda = formar(rueda, "22");
	rueda = formar(rueda, "34");
	rueda = formar(rueda, "15");
	rueda = formar(rueda, "3");
	rueda = formar(rueda, "24");
	rueda = formar(rueda, "36");
	rueda = formar(rueda, "13");
	rueda = formar(rueda, "1");
	rueda = formar(rueda, "00");
	rueda = formar(rueda, "27");
	rueda = formar(rueda, "10");
	rueda = formar(rueda, "25");
	rueda = formar(rueda, "29");
	rueda = formar(rueda, "12");
	rueda = formar(rueda, "8");
	rueda = formar(rueda, "19");
	rueda = formar(rueda, "31");
	rueda = formar(rueda, "18");
	rueda = formar(rueda, "6");
	rueda = formar(rueda, "21");
	rueda = formar(rueda, "33");
	rueda = formar(rueda, "16");
	rueda = formar(rueda, "4");
	rueda = formar(rueda, "23");
	rueda = formar(rueda, "35");
	rueda = formar(rueda, "14");
	rueda = formar(rueda, "2");

	return rueda;
}

void menu_simple() {
	puts("");
	puts("\t1) Rojo.");
	puts("\t2) Negro.");
	puts("\t3) Par.");
	puts("\t4) Impar.");
	puts("\t5) Manque (1-18).");
	puts("\t6) Passe (19-36).");
}

void delay(int n) {
	int i, j;
	for(i = 0; i<n*100;i++)
		for(j = 0; j<1000;j++);
}

int ap_espec() {
	int na = val(1, 6, "Numero de apuesta");
	return na;
}

int val(int a, int b, char *texto) {
	int valor;
	while(1) {
		printf("%s : ", texto);
		scanf("%d", &valor);
		if(valor >= a && valor <= b)
			break;
		else 
			puts("No valido.");
	}

	return valor;
}

int colorde(char *numero) {
	int num, uni, dec;
	if(strcmp(numero, "00") == 0 || strcmp(numero, "0") == 0)
		return 42; //verde
	else if(strcmp(numero, "19") == 0)
		return 41;

	num = atoi(numero);
	while(num > 10) {
		uni = num % 10;
		dec = num / 10;
		num = uni + dec;
	}

	if(num % 2 == 0)
		return 40; //negro
	else 
		return 41; //rojo

	printf("%d\n", num);
	printf("\e[40m%s\e[49m", numero);
}

void simular(Circular rueda) {
	int i;

	espacios(10);
	printf(">\n");
	espacios(10);
	impElem(info(rueda, 0), colorde(info(rueda, 0)));
	printf("\n");

	for(i=1; i<=9;i++) {
		espacios(9-i);
		impElem(info(rueda, 38-i), colorde(info(rueda, 38-i)));
		espacios(i*2+1);
		impElem(info(rueda, i), colorde(info(rueda, i)));
		printf("\n");
	}
	for(i=1; i<=9;i++) {
		espacios(i);
		impElem(info(rueda, 29-i), colorde(info(rueda, 29-i)));
		espacios((10-i)*2);
		impElem(info(rueda, i+9), colorde(info(rueda, i+9)));
		printf("\n");
	}


	espacios(11);
	impElem(info(rueda, 19), colorde(info(rueda, 19)));
	printf("\n");
}

Circular girar(Circular rueda) {
	int random = rand()%100 + 30;

	while(random--) {
		simular(rueda);
		rueda = rotar(rueda);
		delay(300);
		limpiar();
	}
	simular(rueda);
	esperar();
	return rueda;
}

void pagarganadores(Lista apostadores, Elem numero) {
	while(!esVacia(apostadores)) {
		impElemL(cabeza(apostadores));
		if(similitud_simple(cabeza(apostadores), numero)) {
			printf("Tuviste exito. \n");
			printf("Remoneracion: %li dolares.\n", 2*cantidad_ap(cabeza(apostadores)));
		}
		else {
			printf("Suerte para la proxima.\n");
			printf("Remoneracion: 0 dolares.\n");
		}
		printf("\n");
		esperar();
		apostadores = resto(apostadores);
	}
}

int similitud_simple(Elem_lista apost, Elem numero) {
	int na = num_ap(apost);
	int num = atoi(numero);
	if(na == 1 && colorde(numero) == 41) //son rojo?
		return 1;
	else if(na == 2 && colorde(numero) == 40) // negro?
		return 1;
	else if(na == 3 && num%2 == 0)
		return 1;
	else if(na == 4 && num%2 == 1)
		return 1;
	else if(na == 5 && (num>=1 && num<=18 ))
		return 1;
	else if(na == 6 && (num>=19 && num<=36))
		return 1;
	else 
		return 0;
}