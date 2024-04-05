/*
 * main.c
 *
 *  Created on: 4 abr 2024
 *      Author: iker2
 */
#include "usuario.h"
#include "menus.h"
#include <stdio.h>
int main(){
	Usuario u;
	int pos;
	char opcion,opcionP;
	do{
		opcion = bienvenidoDeustoteca();
		switch(opcion){
			case '1':   u=pedirUsuario();
						pos=buscarNombreUsuario(u.nomUsuario);
						if(pos!=-1){
							printf("Lo sentimos! Ese nombre de usuario ya existe\n");
						}else{
							registrarUsuario();
							}
			break;
			case '2':   u=pedirUsuario();
						pos=buscarNombreUsuario();
						if(pos==-1){
							printf("Lo sentimos! No tenemos datos de tu registro\n");
						}else{
							if(contrasenyaCorrecta(usuarios[pos], u.contrasenya)){
								printf("Bienvenido!!\n"); fflush(stdout);
								do{
									opcionP=menuPrincipal();
									switch(opcionP){
									case '1':
									case '2':
									case '3':printf("Volviendo al men� principal...\n"); fflush(stdout);
									  break;
									}
								}while(opcionP != '3');
							}else{
								printf("Lo sentimos! La contrase�a no es correcta\n");fflush(stdout);
							}

						}
						break;
			case '3':
			case '4': printf("Fin del programa\n");
					  fflush(stdout);
					  break;
			default : printf("ERROR! La opci�n no es correcta\n");
			   	   	  fflush(stdout);
		}
	}while(opcion!='4');
	return 0;
}

