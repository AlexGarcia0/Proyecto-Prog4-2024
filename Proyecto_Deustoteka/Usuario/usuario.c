#include <stdio.h>
#include <string.h>
#include "usuario.h"

void registrarUsuario(Usuario usuarios[], int *numUsuarios) {
	Usuario nuevoUsuario;
	printf("Ingresa el nombre: ");
	scanf("%s", nuevoUsuario.nombre);
	printf("Ingresa los apellidos: ");
	scanf("%s", nuevoUsuario.apellidos);
	printf("Ingresa el nombre de usuario: ");
	scanf("%s", nuevoUsuario.nomUsuario);
	printf("Ingresa la contraseña: ");
	scanf("%s", nuevoUsuario.contrasenya);
	printf("Ingresa el correo electrónico: ");
	scanf("%s", nuevoUsuario.email);
	printf("Ingresa el número de teléfono: ");
	scanf("%s", nuevoUsuario.telefono);

	usuarios[*numUsuarios] = nuevoUsuario;
	(*numUsuarios)++;
}

void mostrarUsuarios(Usuario usuarios[], int numUsuarios) {
	printf("Usuarios registrados:\n");
	for (int i = 0; i < numUsuarios; i++) {
		printf("Nombre: %s %s\n", usuarios[i].nombre, usuarios[i].apellidos);
		printf("Usuario: %s\n", usuarios[i].usuario);
		printf("Email: %s\n", usuarios[i].email);
		printf("Teléfono: %s\n", usuarios[i].telefono);
		printf("\n");
	}
}

Usuario *buscarUsuarioPorNombre(Usuario usuarios[], int numUsuarios, const char *nombre) {
	for (int i = 0; i < numUsuarios; i++) {
		if (strcmp(usuarios[i].nomUsuario, nomUsuario) == 0) {
			return &usuarios[i];
		}
	}
	return NULL;
}
