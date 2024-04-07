#include <stdio.h>
#include <string.h>
#include "libro.h"
#include "../sqlite3.h"


void imprimirLibros(sqlite3 *db){
	int numLibros = 0;
	Libro *libros = obtenerLibros(&numLibros, db);
	for(int i = 0; i < numLibros; i++){
		printf("título: %s || ISBN: %s || autor: %s || cantidad: %d || estado: %s || tipo: %s\n",
				libros[i].titulo, libros[i].isbn, libros[i].autor, libros[i].cantidad, libros[i].estado, libros[i].tipo);
	}
}

void agregarLibro(Libro *libro, sqlite3 *db) {

    printf("Ingresa el título del nuevo libro: ");
    fflush(stdout);
    scanf("%s", libro->titulo);

    printf("Ingresa el ISBN: ");
    fflush(stdout);
    scanf("%s", libro->isbn);

    printf("Ingresa el autor: ");
    fflush(stdout);
    scanf("%s", libro->autor);

    printf("Ingresa la cantidad: ");
    fflush(stdout);
    scanf("%d", &libro->cantidad);

    printf("Ingresa el estado ('agotado' o 'disponible'): ");
    fflush(stdout);
    scanf("%s", libro->estado);

    printf("Ingresa el tipo de libro que es: ");
    fflush(stdout);
    scanf("%s", libro->tipo);

    sqlite3_stmt *stmt;
    char *sql = "INSERT INTO libros (titulo, isbn, autor, cantidad, estado, tipo) VALUES (?,?,?,?,?,?)";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, libro->titulo, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, libro->isbn, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, libro->autor, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, libro->cantidad);
    sqlite3_bind_text(stmt, 5, libro->estado, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, libro->tipo, -1, SQLITE_STATIC);

    int result = sqlite3_step(stmt);

    if (result != SQLITE_DONE) {
        fprintf(stderr, "Error al ingresar un nuevo libro: %s\n", sqlite3_errmsg(db));
        return;
    }

    printf("\nLibro introducido con éxito.\n");
    fflush(stdout);

    sqlite3_finalize(stmt);
}

void editarLibro(sqlite3 *db) {
    printf("Todos los libros:\n");
    imprimirLibros(db);

    printf("Introduce el ISBN del libro a editar: ");
    fflush(stdout);
    char isbn[20];
    scanf("%s", isbn);

    printf("Elija el parámetro a editar:\n");
    printf("1. Título\n");
    printf("2. Autor\n");
    printf("3. Cantidad\n");
    printf("4. Estado (agotado o disponible)\n");
    printf("5. Tipo\n");

    int opcion;
    scanf("%d", &opcion);

    char *campo;
    switch (opcion) {
        case 1:
            campo = "titulo";
            break;
        case 2:
            campo = "autor";
            break;
        case 3:
            campo = "cantidad";
            break;
        case 4:
            campo = "estado";
            break;
        case 5:
            campo = "tipo";
            break;
        default:
            printf("Opción inválida\n");
            return;
    }

    char query[200];
    sprintf(query, "UPDATE libros SET %s = ? WHERE isbn = ?", campo);

    char valor[100];
    printf("Ingrese el nuevo valor: ");
    scanf("%s", valor);

    sqlite3_stmt *stmt;
    int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (result == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, valor, -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, isbn, -1, SQLITE_TRANSIENT);

        result = sqlite3_step(stmt);
        if (result != SQLITE_DONE) {
            printf("Error actualizando el libro\n");
        } else {
            printf("Libro actualizado correctamente\n");
        }
    } else {
        printf("Error preparando el query\n");
    }

    sqlite3_finalize(stmt);
}

void eliminarLibro(sqlite3* db) {
    printf("Todos los libros:\n");
    imprimirLibros(db);

    char isbn[20];
    printf("Introduce el ISBN del libro a eliminar: ");
    fflush(stdout);
    scanf("%s", isbn);

    char* mensaje_error;
    char consulta[100];
    sprintf(consulta, "DELETE FROM libros WHERE isbn='%s'", isbn);
    if (sqlite3_exec(db, consulta, NULL, 0, &mensaje_error) != SQLITE_OK) {
        printf("Error eliminando libro: %s\n", mensaje_error);
        sqlite3_free(mensaje_error);
        return;
    }

    printf("Libro eliminado correctamente.\n");
}




Libro* obtenerLibros(int* numLibros, sqlite3 *db) {
	char *sql = "SELECT * FROM libros";
	sqlite3_stmt *stmt;
	if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
		fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
		return NULL;
	}
	Libro* libroList = malloc(sizeof(Libro));
	int count = 0;
	while(sqlite3_step(stmt) == SQLITE_ROW){
		count++;
		libroList = realloc(libroList, count*sizeof(Libro));
		strncpy(libroList[count-1].titulo, (char*)sqlite3_column_text(stmt,0), sizeof(libroList[count-1].titulo)-1);
		strncpy(libroList[count-1].isbn, (char*)sqlite3_column_text(stmt,1), sizeof(libroList[count-1].isbn)-1);
		strncpy(libroList[count-1].autor, (char*)sqlite3_column_text(stmt,2), sizeof(libroList[count-1].autor)-1);
		libroList[count-1].cantidad = sqlite3_column_int(stmt,3);
		strncpy(libroList[count-1].estado, (char*)sqlite3_column_text(stmt,4), sizeof(libroList[count-1].estado)-1);
		strncpy(libroList[count-1].tipo, (char*)sqlite3_column_text(stmt,5), sizeof(libroList[count-1].tipo)-1);
	}
	sqlite3_finalize(stmt);
	*numLibros = count;
	return libroList;
}

void prestamoLibro(Libro *libro, sqlite3 *db) {
	if (libro->cantidad > 0) {
		libro->cantidad--;

		if (libro->cantidad == 0) {
			strcpy(libro->estado, "agotado");
		}

		printf("Libro prestado con éxito.\n");

		sqlite3_stmt *stmt;
		char *sql = "UPDATE libros SET cantidad = ?, estado = ? WHERE isbn = ?";
		if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
			fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
			return;
		}
		sqlite3_bind_int(stmt, 1, libro->cantidad);
		sqlite3_bind_text(stmt, 2, libro->estado, -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, libro->isbn, -1, SQLITE_STATIC);

		int result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			fprintf(stderr, "Error al realizar el préstamo del libro: %s\n", sqlite3_errmsg(db));
			return;
		}

		sqlite3_finalize(stmt);
	} else {
		printf("Lo siento, el libro no está disponible en este momento.\n");
	}
}


void devolucionLibro(Libro *libro, sqlite3 *db) {
	libro->cantidad++;
	strcpy(libro->estado, "disponible");

	sqlite3_stmt *stmt;
	char *sql = "UPDATE libros SET cantidad = ?, estado = ? WHERE isbn = ?";
	if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK){
		fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
		return;
	}
	sqlite3_bind_int(stmt, 1, libro->cantidad);
	sqlite3_bind_text(stmt, 2, libro->estado, -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, libro->isbn, -1, SQLITE_STATIC);

	int result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		fprintf(stderr, "Error al realizar la devolución del libro: %s\n", sqlite3_errmsg(db));
		return;
	}

	printf("Libro devuelto con éxito.\n");
	sqlite3_finalize(stmt);
}

