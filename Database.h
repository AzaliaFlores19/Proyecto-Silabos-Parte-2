#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <iostream>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

using std::string, std::cout;

class Database {

private:
    QSqlDatabase connection;

    /*
     * Crea las tablas de la DB.
     */
    void prepareTables() {
        QStringList queries = {
            R"(
            CREATE TABLE Facultad (
                id INTEGER PRIMARY KEY,
                nombre TEXT
            );)",
            R"(
            CREATE TABLE ProgramaAcademico (
                id INTEGER PRIMARY KEY,
                facultad INTEGER,
                nombre TEXT,
                FOREIGN KEY (facultad) REFERENCES Facultad(id)
            );)",
            R"(
            CREATE TABLE Usuarios (
                numeroCuenta TEXT PRIMARY KEY,
                nombre TEXT,
                clave TEXT,
                org TEXT
            );)",
            R"(
            CREATE TABLE Silabos (
                id INTEGER PRIMARY KEY,
                nombre TEXT,
                carrera INTEGER,
                codigoClase VARCHAR(6),
                nombreClase TEXT,
                estado INTEGER,
                subidoPor TEXT,
                archivo BLOB,
                FOREIGN KEY (carrera) REFERENCES ProgramaAcademico(id),
                FOREIGN KEY (subidoPor) REFERENCES Usuarios(numeroCuenta)
            );)",
            R"(
            CREATE TABLE CuadroFechas (
                id INTEGER PRIMARY KEY,
                silabo INTEGER,
                archivo BLOB,
                FOREIGN KEY (silabo) REFERENCES Silabos(id)
            );)"
        };

        for (const QString& queryStr : queries) {
            QSqlQuery query(connection);
            if (!query.exec(queryStr)) {
                qDebug() << "Error creating table:" << query.lastError().text();
            }
        }
    }


public:
    const string databasePath = QDir::homePath().toStdString() + "/silabos.sql";
    Database() {
        connection = QSqlDatabase::addDatabase("QSQLITE");
        connection.setDatabaseName(databasePath.c_str());

       if (!connection.open()) {
           cout << "Error al iniciar conexion.\n";
           return;
       }

       prepareTables();
    }




};


#endif // DATABASE_H
