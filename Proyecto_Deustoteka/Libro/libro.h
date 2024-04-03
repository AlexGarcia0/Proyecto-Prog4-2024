#ifndef LIBRO_H
#define LIBRO_H

// Estructura para representar un libro
typedef struct {
    char titulo[100];
    char isbn[20];
    char autor[100];
    int cantidad;
    char estado[20]; // Puede ser "agotado" o "disponible"
    char tipo[50];
} Libro;

// Funciones para manipular libros
void imprimir_libro(Libro libro);
void prestamo_libro(Libro *libro);
void devolucion_libro(Libro *libro);

#endif /* LIBRO_H */
