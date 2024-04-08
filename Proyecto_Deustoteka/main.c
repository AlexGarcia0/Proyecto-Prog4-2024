#include "Usuario/usuario.h"
#include "Menus/menus.h"
#include <stdio.h>
#include <string.h>

#include "bdd.h"
#include "sqlite3.h"
#include <stdlib.h>



int main(){

	sqlite3 *db;
	crearBDD(&db);

	Usuario u;
	char opcion, opcionP;

	do{
		opcion = bienvenidoDeustoteca();
		switch(opcion){
			case '1':	registrarUsuario(&u, db);

			break;
			case '2':
				u=pedirUsuario();
				if(verificarUsuario(u.nomUsuario, u.contrasenya, db)){
							printf("¡¡Bienvenido!!\n"); fflush(stdout);
							do{
								opcionP=menuPrincipal();
								switch(opcionP){
								case '1':
								case '2':
								case '3':printf("Volviendo al menú principal...\n"); fflush(stdout);
								break;
								}
							}while(opcionP != '3');
						}else{
							printf("¡Lo sentimos! La contrasenya no es correcta\n");fflush(stdout);
						}


						break;
			case '3':
			case '4': printf("Fin del programa.\n");
					  fflush(stdout);
					  break;
			default : printf("¡ERROR! La opción no es correcta\n");
			   	   	  fflush(stdout);
		}
	} while(opcion!='4');
		sqlite3_close(db);
	return 0;
}

