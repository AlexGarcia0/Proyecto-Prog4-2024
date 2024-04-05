#include <stdio.h>
#include <string.h>
#include "usuario.h"

int contrasenyaCorrecta(char *contrasenyaU,char *contrasenya){
	int correcta = 0;
	if(strcmp(contrasenyaU, contrasenya)==0){
		correcta = 1;
	}
	return correcta;
}

Usuario pedirUsuario(){
	Usuario u;

	printf("Introduce el nombre de usuario/a: ");
	fflush(stdout);
	fflush(stdin);
	gets(u.nom);

	printf("Introduce la contrasenya: ");
	fflush(stdout);
	fflush(stdin);
	gets(u.con);
	return u;
}

void registrarUsuario(Usuario *usuario) {
	printf("Ingresa el nombre: ");
	scanf("%s", usuario->nombre);
	printf("Ingresa los apellidos: ");
	scanf("%s", usuario->apellidos);
	printf("Ingresa el nombre de usuario/a: ");
	scanf("%s", usuario->nomUsuario);
	printf("Ingresa la contrasenya: ");
	scanf("%s", usuario->contrasenya);
	printf("Ingresa el correo electrónico: ");
	scanf("%s", usuario->email);
	printf("Ingresa el número de teléfono: ");
	scanf("%s", usuario->telefono);
}

void mostrarUsuario(Usuario *usuario) {
	printf("Nombre: %s %s\n", usuario->nombre, usuario->apellidos);
	printf("Usuario: %s\n", usuario->nomUsuario);
	printf("Email: %s\n", usuario->email);
	printf("Teléfono: %s\n", usuario->telefono);
	printf("\n");
}
