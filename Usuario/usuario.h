#ifndef USUARIO_H_
#define USUARIO_H_

#include <stdio.h>
#include <string.h>
#include "../sqlite3.h"

typedef struct usuario{
    char nombre[20];
    char apellidos[50];
    char email[20];
    char telefono[20];
	char nomUsuario[20];
	char contrasenya[20];
}Usuario;

Usuario pedirUsuario();
int verificarUsuario(const char* nomUsuario, const char* contrasenya, sqlite3* db);
void registrarUsuario(Usuario *usuario, sqlite3 *db);
void mostrarUsuarios(sqlite3 *db);
int buscarNombreUsuario(const char *nombreUsuario, sqlite3 *db);

#endif /* USUARIO_H */
