#include <stdio.h>
#include <string.h>
#include "empleado.h"

void crearEmpleado(Empleado *empleado, const char *nombre, const char *apellidos, const char *dni, const char *telefono, const char *cargo, const char *email, const char *contrasenya) {
    strcpy(empleado->nombre, nombre);
    strcpy(empleado->apellidos, apellidos);
    strcpy(empleado->dni, dni);
    strcpy(empleado->telefono, telefono);
    strcpy(empleado->cargo, cargo);
    strcpy(empleado->email, email);
    strcpy(empleado->contrasenya, contrasenya);
}

void mostrarEmpleado(const Empleado *empleado) {
    printf("Nombre: %s\n", empleado->nombre);
    printf("Apellidos: %s\n", empleado->apellidos);
    printf("DNI: %s\n", empleado->dni);
    printf("Teléfono: %s\n", empleado->telefono);
    printf("Cargo: %s\n", empleado->cargo);
    printf("Email: %s\n", empleado->email);
    printf("Contraseña: %s\n", empleado->contrasenya);
}
