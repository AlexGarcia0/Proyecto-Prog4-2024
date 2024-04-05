#include "listaUsuarios.h"
#include <stdio.h>
#include <string.h>

int buscarUsuario(ListaUsuarios listaU, char *nom){
	int pos=0,enc=0;
	while(!enc && pos<listaU.numeroU){
		if(strcmp(listaU.arrayU[pos].nombre,nom)==0){
			enc = 1;
		}else{
			pos++;
		}
	}
	if(enc){
		return pos;
	}else{
		return -1;
	}
}

void aniadirUsuario(ListaUsuarios *listaU, Usuario u){
	if(listaU->numeroU < listaU->tamanyo){
		listaU->arrayU[listaU->numeroU] = u;
		listaU->numeroU++;
		printf("Usuario anyadido\n");
	}else{
		printf("La lista está llena\n");
	}
	fflush(stdout);
}

void volcarFicheroAListaUsuarios(ListaUsuarios *listaU, char *nomfich){
	FILE *pf;
	Usuario u;
	pf = fopen(nomfich,"r");
	if(pf!=(FILE*)NULL){
		fscanf(pf,"%d",&listaU->tamanyo);
		listaU->arrayU = (Usuario*)malloc(listaU->tamanyo * sizeof(Usuario));
		listaU->numeroU = 0;
		while(fscanf(pf,"%s %s",u.nombre,u.contrasenya) != EOF){
			listaU->arrayU[listaU->numeroU] = u;
			listaU->numeroU++;
		}
		fclose(pf);
	}
}

void volcarListaUsuariosAFichero(ListaUsuarios listaU, char *nomfich){
	FILE *pf;
	int i;
	pf = fopen(nomfich,"w");
	if(pf != (FILE*)NULL){
		fprintf(pf,"%d\n",listaU.tamanyo);
		for(i=0;i<listaU.numeroU;i++){
			fprintf(pf,"%s %s\n",listaU.arrayU[i].nombre,listaU.arrayU[i].contrasenya);
		}
		fclose(pf);
	}
}

void aniadirUsuarioAlFinalDelFichero(Usuario u, char *nomfich){
	FILE *pf;

	pf = fopen(nomfich,"a");
	if(pf!=(FILE*)NULL){
		fprintf(pf,"%s %s\n",u.nombre,u.contrasenya);
		fclose(pf);
	}
}










