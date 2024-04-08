#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <stdio.h>
#include"../sqlite3.h"

typedef struct {
	char nombre[50];
	char apellidos[50];
	char dni[15];
	char telefono[15];
	char cargo[50];
	char email[50];
	char contrasenya[50];
} Empleado;


void agregarEmpleado(Empleado *empleado, sqlite3 *db);
void eliminarEmpleado(const char* dni, sqlite3 *db);
void mostrarEmpleados(sqlite3 *db);

#endif /* EMPLEADO_H */
