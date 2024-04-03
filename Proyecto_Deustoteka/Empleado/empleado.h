#ifndef EMPLEADO_H
#define EMPLEADO_H


typedef struct {
	char nombre[50];
	char apellidos[50];
	char dni[15];
	char telefono[15];
	char cargo[50];
	char email[50];
	char contrasenya[50];
} Empleado;


void crearEmpleado(Empleado *empleado, const char *nombre, const char *apellidos, const char *dni, const char *telefono, const char *cargo, const char *email, const char *contrasenya);
void mostrarEmpleado(const Empleado *empleado);

#endif /* EMPLEADO_H */
