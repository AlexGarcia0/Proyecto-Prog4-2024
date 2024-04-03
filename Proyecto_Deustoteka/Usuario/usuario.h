
#ifndef USUARIO_H_
#define USUARIO_H_
typedef struct usuario{
    char nombre[20];
    char apellidos[50];
    char email[20];
    char telefono[20];
	char nomUsuario[20];
	char contrasenya[20];
}Usuario;

Usuario pedirUsuario();

void registrarUsuario(Usuario usuarios[], int *numUsuarios);
void mostrarUsuarios(Usuario usuarios[], int numUsuarios);
Usuario *buscarUsuarioPorNombre(Usuario usuario[], int numUsuario, const char *nombre);

#endif /* USUARIO_H */
