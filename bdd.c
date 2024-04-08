#include <stdio.h>
#include "sqlite3.h"
#include "bdd.h"


int crearBDD() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("Deustoteka.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Crear tabla "usuarios"
    char *sql = "CREATE TABLE usuarios ("
                "DNI INTEGER PRIMARY KEY,"
                "nombre TEXT NOT NULL,"
                "apellidos TEXT NOT NULL,"
                "email TEXT NOT NULL,"
                "telefono TEXT,"
    			"nomUsuario TEXT UNIQUE NOT NULL"
                "contrasenya TEXT NOT NULL);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'usuarios': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Crear tabla "prestamos"
    sql = "CREATE TABLE prestamos ("
          "id INTEGER PRIMARY KEY,"
          "usuario_dni INTEGER NOT NULL,"
          "libro_isbn INTEGER NOT NULL,"
          "fecha_prestamo TEXT NOT NULL,"
          "fecha_devolucion TEXT,"
          "FOREIGN KEY (usuario_dni) REFERENCES usuarios(DNI),"
          "FOREIGN KEY (libro_isbn) REFERENCES libros(ISBN));";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'prestamos': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Crear tabla "libros"
    sql = "CREATE TABLE libros ("
          "isbn INTEGER PRIMARY KEY,"
          "titulo TEXT NOT NULL,"
          "autor TEXT NOT NULL,"
          "estado TEXT NOT NULL,"
          "cantidad INTEGER NOT NULL,"
          "tipo TEXT NOT NULL);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'libros': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }


    // Crear tabla "deustoteka"
    sql = "CREATE TABLE deustoteka ("
          "ID INTEGER PRIMARY KEY,"
          "nombre TEXT NOT NULL,"
          "calle TEXT NOT NULL,"
          "ciudad_id INTEGER NOT NULL,"
          "FOREIGN KEY (ciudad_id) REFERENCES ciudad(ID));";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'deustoteka': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Crear tabla "ciudad"
    sql = "CREATE TABLE ciudad ("
          "ID INTEGER PRIMARY KEY,"
          "nombre TEXT NOT NULL,"
          "pais_id INTEGER NOT NULL,"
          "FOREIGN KEY (pais_id) REFERENCES pais(ID));";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'ciudad': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Crear tabla "pais"
    sql = "CREATE TABLE pais ("
          "ID INTEGER PRIMARY KEY,"
          "nombre TEXT NOT NULL);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'pais': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Crear tabla "empleado"
    sql = "CREATE TABLE empleado ("
          "dni INTEGER PRIMARY KEY,"
          "nombre TEXT NOT NULL,"
          "apellidos TEXT NOT NULL,"
          "telefono TEXT,"
          "cargo TEXT NOT NULL,"
          "email TEXT NOT NULL);";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'empleado': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}
