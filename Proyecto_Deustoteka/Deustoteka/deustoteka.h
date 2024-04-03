#ifndef DEUSTOTEKA_H
#define DEUSTOTEKA_H

#include "..Usuario/usuario.h"
#include "..Libro/libro.h"
#include "..Empleado/empleado.h"


typedef struct {
	int id;
	char nombre[50];
	char calle[50];
} Deustoteka;

void inicializarDeustoteka(Deustoteka *deustoteka, int id, const char *nombre, const char *calle);
void mostrarDeustoteka(const Deustoteka *deustoteka);

#endif /* DEUSTOTEKA_H */
