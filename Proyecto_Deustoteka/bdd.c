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
    char *sql = "CREATE TABLE IF NOT EXISTS usuarios ("
                "nombre varchar(20),"
                "apellidos varchar(50),"
                "email varchar(20),"
                "telefono varchar(20),"
    			"nomUsuario varchar(50) primary key,"
                "contrasenya varchar(20));";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'usuarios': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // Crear tabla "prestamos"
    sql = "CREATE TABLE IF NOT EXISTS prestamos ("
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
    }

    // Crear tabla "libros"
    sql = "CREATE TABLE IF NOT EXISTS libros ("
          "isbn varchar(20) primary key,"
          "titulo varchar(100),"
          "autor varchar(100),"
          "estado varchar(20),"
          "cantidad int,"
          "tipo varchar(50));";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'libros': %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return 1;
    }


    // Crear tabla "ciudad"
    sql = "CREATE TABLE IF NOT EXISTS ciudad ("
          "id int primary key,"
          "nombre varchar(20),"
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
    sql = "CREATE TABLE IF NOT EXISTS pais ("
          "id int primary key,"
          "nombre varchar(20));";
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla 'pais': %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;

    }

    // Crear tabla "empleado"
    sql = "CREATE TABLE IF NOT EXISTS empleados ("
          "dni varchar(50) primary key,"
          "nombre varchar(50),"
          "apellidos varchar(50),"
          "telefono varchar(15),"
          "cargo varchar(50),"
          "email varchar(50));";
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
