#ifndef LIBRO_H
#define LIBRO_H

#include <stdio.h>
#include <string.h>
#include "../sqlite3.h"

typedef struct {
    char titulo[100];
    char isbn[20];
    char autor[100];
    int cantidad;
    char estado[20];
    char tipo[50];
} Libro;

void imprimirLibros(sqlite3 *db);
void agregarLibro(Libro *libro, sqlite3 *db);
void editarLibro(sqlite3 *db);
void eliminarLibro(sqlite3* db);
Libro* obtenerLibros(int* numLibros, sqlite3 *db);
void prestamoLibro(Libro *libro, sqlite3 *db);
void devolucionLibro(Libro *libro, sqlite3 *db);

#endif /* LIBRO_H */
