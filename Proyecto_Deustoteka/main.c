/*
 * main.c
 *
 *  Created on: 4 abr 2024
 *      Author: iker2
 */
#include "Usuario/usuario.h"
#include "Menus/menus.h"
#include "Usuario/listaUsuarios.h"
#include <stdio.h>
#define NOMFICH "Usuarios.txt"

int main(){
	ListaUsuarios listaU;
	Usuario u;
	int pos;
	char opcion,opcionP;
	do{
		opcion = bienvenidoDeustoteca();
		switch(opcion){
			case '1':   u=pedirUsuario();
						pos = buscarUsuario(listaU, u.nomUsuario);
						if(pos!=-1){
							printf("¡Lo sentimos! Este nombre de usuario ya existe\n");
						}else{
							registrarUsuario(&u);
						}
			break;
			case '2':   u=pedirUsuario();
						pos = buscarUsuario(listaU, u.nomUsuario);
						if(pos==-1){
							printf("¡Lo sentimos! No tenemos datos de tu registro\n");
						}else{
							if(contrasenyaCorrecta(listaU.arrayU[pos].contrasenya, u.contrasenya)){
								printf("¡Bienvenido!\n"); fflush(stdout);
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

						}
						break;
			case '3':
			case '4': printf("Fin del programa\n");
					  fflush(stdout);
					  break;
			default : printf("¡ERROR! La opción no es correcta\n");
			   	   	  fflush(stdout);
		}
	}while(opcion!='4');
	return 0;
}

