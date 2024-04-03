#include <stdio.h>
#include <string.h>
#include "deustoteka.h"

void inicializarDeustoteka(Deustoteka *deustoteka, int id, const char *nombre, const char *calle) {
	deustoteka->id = id;
	strcpy(deustoteka->nombre, nombre);
	strcpy(deustoteka->calle, calle);
}

void mostrarDeustoteka(const Deustoteka *deustoteka) {
	printf("ID: %d\n", deustoteka->id);
	printf("Nombre: %s\n", deustoteka->nombre);
	printf("Calle: %s\n", deustoteka->calle);
}
