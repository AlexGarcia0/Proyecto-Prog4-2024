#include <stdio.h>
#include <string.h>
#include "empleado.h"
#include"../sqlite3.h"

void agregarEmpleado(Empleado *empleado, sqlite3 *db) {
	printf("Ingresa el nombre del empleado: ");
	fflush(stdout);
	scanf("%s", empleado->nombre);

	printf("Ingresa los apellidos del empleado: ");
	fflush(stdout);
	scanf("%s", empleado->apellidos);

	printf("Ingresa el DNI del empleado: ");
	fflush(stdout);
	scanf("%s", empleado->dni);

	printf("Ingresa el teléfono: ");
	fflush(stdout);
	scanf("%s", empleado->telefono);

	printf("Ingresa el cargo: ");
	fflush(stdout);
	scanf("%s", empleado->cargo);

	printf("Ingresa el email: ");
	fflush(stdout);
	scanf("%s", empleado->email);

	printf("Ingresa la contraseña: ");
	fflush(stdout);
	scanf("%s", empleado->contrasenya);

	char *sql = "INSERT INTO empleados (nombre, apellidos, dni, telefono, cargo, email, contrasenya) VALUES (?, ?, ?, ?, ?, ?, ?)";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
		fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
		return;
	}

	sqlite3_bind_text(stmt, 1, empleado->nombre, -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, empleado->apellidos, -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, empleado->dni, -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 4, empleado->telefono, -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 5, empleado->cargo, -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 6, empleado->email, -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 7, empleado->contrasenya, -1, SQLITE_STATIC);

	int result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		fprintf(stderr, "Error al insertar el empleado: %s\n", sqlite3_errmsg(db));
	} else {
		printf("Empleado registrado correctamente en la base de datos.\n");
	}

	sqlite3_finalize(stmt);
}


void eliminarEmpleado(const char* dni, sqlite3 *db) {
	char *sql = "DELETE FROM empleados WHERE dni = ?";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
		fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
		return;
	}

	sqlite3_bind_text(stmt, 1, dni, -1, SQLITE_STATIC);


	int result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		fprintf(stderr, "Error al eliminar el empleado: %s\n", sqlite3_errmsg(db));
	} else {
		printf("Empleado con DNI %s eliminado correctamente de la base de datos.\n", dni);
	}

	sqlite3_finalize(stmt);
}

void mostrarEmpleados(sqlite3 *db) {
	char *sql = "SELECT * FROM empleados";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
		fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
		return;
	}

	printf("Listado de empleados:\n");
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		printf("Nombre: %s %s, DNI: %s, Teléfono: %s, Cargo: %s, Email: %s\n",
				sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1),
				sqlite3_column_text(stmt, 2), sqlite3_column_text(stmt, 3),
				sqlite3_column_text(stmt, 4), sqlite3_column_text(stmt, 5));
	}

	sqlite3_finalize(stmt);
}
