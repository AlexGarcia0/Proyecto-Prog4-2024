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
	do{
		opcion = bienvenidoDeustoteca();
		switch(opcion){
			case '1':   u=pedirUsuario();
						pos=buscarUsuarioPorNombre();
						if(pos!=-1){
							printf("Lo sentimos! Ese nombre de usuario ya existe\n");
						}else{
							aniadirUsuario(&lu, u);
							aniadirUsuarioAlFinalDelFichero(u, NOMFICH);
							}
			break;
			case '2': pedirUsuario();
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

