#include <stdio.h>
#include <string.h>
#include "usuario.h"

#include "../sqlite3.h"

#define MAX_USUARIOS 100

Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;


Usuario pedirUsuario(){
	Usuario u;

	printf("Introduce el nombre de usuario/a: ");
	fflush(stdout);
	fflush(stdin);
	gets(u.nomUsuario);

	printf("Introduce la contrasenya: ");
	fflush(stdout);
	fflush(stdin);
	gets(u.contrasenya);
	return u;
}


int verificarUsuario(const char* nomUsuario, const char* contrasenya, sqlite3* db) {
	char *sql = "SELECT * FROM usuarios WHERE nomUsuario = ?";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
		fprintf(stderr, "Error al preparar la consulta para verificar usuarios: %s\n", sqlite3_errmsg(db));
		return 0;
	}

	sqlite3_bind_text(stmt, 1, nomUsuario, -1, SQLITE_STATIC);


	int resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado == SQLITE_ROW) {
    	printf("Inicio de sesión exitoso \n");
        return 1;
    } else {
    	printf("Usuario no encontrado");
        return 0;
    }
}

void registrarUsuario(Usuario *usuario, sqlite3 *db) {
    printf("Ingresa el nombre: ");
    fflush(stdout);
    scanf("%s", usuario->nombre);

    printf("Ingresa los apellidos: ");
    fflush(stdout);
    scanf("%s", usuario->apellidos);

    int nombreUsuarioEnUso;
	do {
		printf("Ingresa el nombre de usuario: ");
		fflush(stdout);
		scanf("%19s", usuario->nomUsuario);
		nombreUsuarioEnUso = buscarNombreUsuario(usuario->nomUsuario, db);
		if (nombreUsuarioEnUso) {
			printf("El nombre de usuario ya está en uso. Por favor, elija otro.\n");
		}
	} while (nombreUsuarioEnUso);

    printf("Ingresa la contraseña: ");
    fflush(stdout);
    scanf("%s", usuario->contrasenya);

    printf("Ingresa el correo electrónico: ");
    fflush(stdout);
    scanf("%s", usuario->email);

    printf("Ingresa el número de teléfono: ");
    fflush(stdout);
    scanf("%s", usuario->telefono);




    char *sql = "INSERT INTO usuarios (nombre, apellidos, email, telefono, nomUsuario, contrasenya) VALUES (?, ?, ?, ?, ?, ?)";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Error al preparar la consulta en usuarios: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, usuario->nombre, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, usuario->apellidos, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, usuario->email, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, usuario->telefono, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, usuario->nomUsuario, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, usuario->contrasenya, -1, SQLITE_STATIC);

    int result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
        fprintf(stderr, "Error al insertar el usuario: %s\n", sqlite3_errmsg(db));
    } else {
        printf("Usuario registrado correctamente en la base de datos.\n");
    }

    sqlite3_finalize(stmt);
}

void mostrarUsuarios(sqlite3 *db) {
	char *sql = "SELECT nombre, apellidos, email, telefono, nomUsuario FROM usuarios";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
		fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
		return;
	}

	int result;
	while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
		Usuario usuario;
		snprintf(usuario.nombre, sizeof(usuario.nombre), "%s", sqlite3_column_text(stmt, 0));
		snprintf(usuario.apellidos, sizeof(usuario.apellidos), "%s", sqlite3_column_text(stmt, 1));
		snprintf(usuario.email, sizeof(usuario.email), "%s", sqlite3_column_text(stmt, 2));
		snprintf(usuario.telefono, sizeof(usuario.telefono), "%s", sqlite3_column_text(stmt, 3));
		snprintf(usuario.nomUsuario, sizeof(usuario.nomUsuario), "%s", sqlite3_column_text(stmt, 4));
	}

	if (result != SQLITE_DONE) {
		fprintf(stderr, "Error al obtener los usuarios: %s\n", sqlite3_errmsg(db));
	}

	sqlite3_finalize(stmt);
}


int buscarNombreUsuario(const char *nombreUsuario, sqlite3 *db) {
	char *sql = "SELECT COUNT(*) FROM usuarios WHERE nomUsuario = ?";
	sqlite3_stmt *stmt;
	int resultado = 0;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
		fprintf(stderr, "Error al preparar la consulta buscar nombre de usuario: %s\n", sqlite3_errmsg(db));
		return resultado;
	}

	sqlite3_bind_text(stmt, 1, nombreUsuario, -1, SQLITE_STATIC);

	if (sqlite3_step(stmt) == SQLITE_ROW) {
		resultado = sqlite3_column_int(stmt, 0);
	}

	sqlite3_finalize(stmt);
	return resultado;
}

