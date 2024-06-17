#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <iostream>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <vector>

using std::string, std::cout, std::vector;

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

    QSqlDatabase getConnection() {
        return connection;
    }

    bool saveCuadroFechas(int id, vector<char> buffer) {
        QSqlQuery query(connection);

        query.prepare("INSERT INTO CuadroFechas (silabo, archivo) VALUES (?, ?)");
        query.bindValue(0, id);
        query.bindValue(1, QByteArray(buffer.data(), static_cast<int>(buffer.size())));

        if (!query.exec()) {
            qDebug() << "Error: failed to insert file into database -" << query.lastError().text();
            return false;
        } else {
            qDebug() << "File successfully saved to the database.";
            return true;
        }
    }




};


#endif // DATABASE_H
