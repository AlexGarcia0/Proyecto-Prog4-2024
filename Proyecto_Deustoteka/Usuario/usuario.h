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
int contrasenyaCorrecta(char *contrasenyaU, char *contrasenya);
void registrarUsuario(Usuario *usuario);
void mostrarUsuarios(Usuario *usuario);

#endif /* USUARIO_H */
