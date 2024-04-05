#ifndef LISTAUSUARIOS_H_
#define LISTAUSUARIOS_H_
#include "usuario.h"
#include <stdlib.h>
typedef struct listaUsuarios{
	Usuario * arrayU;
	int tamanyo;
	int numeroU;
}ListaUsuarios;

int buscarUsuario(ListaUsuarios listaU, char *nom);
void aniadirUsuario(ListaUsuarios *listaU, Usuario u);
void volcarFicheroAListaUsuarios(ListaUsuarios *listaU, char *nomfich);
void volcarListaUsuariosAFichero(ListaUsuarios listaU, char *nomfich);
void aniadirUsuarioAlFinalDelFichero(Usuario u, char *nomfich);
#endif /* LISTAUSUARIOS_H_ */
