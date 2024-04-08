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

char busquedaDeLibros(){
	char opcion;
		printf("BUSQUEDA DE LIBROS\n");
		printf("------------------------\n ");
		printf("1. Busqueda por ISBN\n");
		printf("2. Busqueda por titulo\n");
		printf("3. Busqueda por categoria\n");
		printf("4. Busqueda por autor\n");
		printf("5. Busqueda por disponibilidad\n");
		printf("6. Volver\n");
		printf("Elige una opci�n: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&opcion);
		return opcion;
};

char gestionarAlquileres(){
	char opcion;
		printf("GESTIONAR ALQUILERES\n");
		printf("------------------------\n ");
		printf("1. Mostrar todos mis alquileres actuales\n");
		printf("2. Prolongar alquiler\n");
		printf("3. Devolver libro\n");
		printf("4. Volver\n");
		printf("Elige una opci�n: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&opcion);
		return opcion;
};

