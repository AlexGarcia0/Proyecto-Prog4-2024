#include <stdio.h>
char bienvenidoDeustoteca(){
	char opcion;
	printf("BIENVENIDO A DEUSTOTEKA\n");
	printf("------------------------\n ");
	printf("1. Registrarse\n");
	printf("2. Iniciar sesion\n");
	printf("3. Iniciar sesion como administrador\n");
	printf("4. Salir\n");
	printf("Elige una opci�n: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
char menuPrincipal(){
	char opcion;
	printf("MENU PRINCIPAL\n");
	printf("------------------------\n ");
	printf("1. Iniciar busqueda de libros\n");
	printf("2. Gestionar alquileres\n");
	printf("3. Volver\n");
	printf("Elige una opci�n: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
};

char menuAdministrador(){
	char opcion;
	printf("MENU ADMINISTRADOR\n");
	printf("------------------------\n ");
	printf("1. mostrar todos los libros\n");
	printf("2. Añadir libro\n");
	printf("3. Editar libro\n");
	printf("4. Eliminar libro\n");
	printf("5. Volver\n");
	printf("Elige una opci�n: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
};
