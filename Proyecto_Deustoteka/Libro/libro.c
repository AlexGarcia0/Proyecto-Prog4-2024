#include <stdio.h>
#include <string.h>
#include "libro.h"


void imprimir_libro(Libro libro) {
	printf("Título: %s\n", libro.titulo);
	printf("ISBN: %s\n", libro.isbn);
	printf("Autor: %s\n", libro.autor);
	printf("Cantidad: %d\n", libro.cantidad);
	printf("Estado: %s\n", libro.estado);
	printf("Tipo: %s\n", libro.tipo);
}

void prestamo_libro(Libro *libro) {
    if (libro->cantidad > 0) {
        libro->cantidad--;
        if (libro->cantidad == 0) {
            strcpy(libro->estado, "agotado");
        }
        printf("Libro prestado con éxito.\n");
    } else {
        printf("Lo siento, el libro no está disponible en este momento.\n");
    }
}

void devolucion_libro(Libro *libro) {
	libro->cantidad++;
	strcpy(libro->estado, "disponible");
	printf("Libro devuelto con éxito.\n");
}
