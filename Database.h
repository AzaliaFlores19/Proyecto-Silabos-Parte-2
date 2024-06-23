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
#include "Silabo.h"
#include "CuadroFechas.h"
#include "Usuario.h"
#include "listaD.h"
#include <ArbolB.h>

using std::string, std::cout, std::vector;

class Database
{

private:
    QSqlDatabase connection;

    /*
     * Crea las tablas de la DB.
     */
    void prepareTables()
    {
        QStringList queries = {
            R"(
            CREATE TABLE IF NOT EXISTS Facultad (
            id INTEGER PRIMARY KEY,
            nombre TEXT
            );)",
            R"(
            CREATE TABLE IF NOT EXISTS ProgramaAcademico (
            id INTEGER PRIMARY KEY,
            facultad INTEGER,
            nombre TEXT,
            FOREIGN KEY (facultad) REFERENCES Facultad(id)
            );)",
            R"(
            CREATE TABLE IF NOT EXISTS Usuarios (
            numeroCuenta TEXT PRIMARY KEY,
            nombre TEXT,
            clave TEXT,
            org TEXT,
            tipo TEXT,
            carrera TEXT
            );)",
            R"(
            CREATE TABLE IF NOT EXISTS Silabos (
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
            CREATE TABLE IF NOT EXISTS CuadroFechas (
            id INTEGER PRIMARY KEY,
            silabo INTEGER,
            archivo BLOB,
            FOREIGN KEY (silabo) REFERENCES Silabos(id)
            );)"
        };

        for (const QString &queryStr : queries)
        {
            QSqlQuery query(connection);
            if (!query.exec(queryStr))
            {
                qDebug() << "Error creating table:" << query.lastError().text();
            }
        }
    }


public:
    const string databasePath = QDir::homePath().toStdString() + "/silabos.sql";
    Database()
    {
        connection = QSqlDatabase::addDatabase("QSQLITE");
        connection.setDatabaseName(databasePath.c_str());

        if (!connection.open())
        {
            cout << "Error al iniciar conexion.\n";
            return;
        }

        prepareTables();
    }

    QSqlDatabase getConnection()
    {
        return connection;
    }

    bool saveSilaboFile(Silabo *silabo, vector<char> buffer)
    {
        cout << "Saving silabo file\n...";
        QSqlQuery query(connection);

        query.prepare("INSERT INTO Silabos(nombre, carrera, codigoClase, nombreClase, estado, subidoPor, archivo) VALUES (?, ?, ?, ?, ?, ?, ?)");
        query.bindValue(0, QString::fromStdString(silabo->getNombreArchivo()));
        query.bindValue(1, QString::fromStdString(silabo->getCarrera()));
        query.bindValue(2, QString::fromStdString(silabo->getCodigoClase()));
        query.bindValue(3, QString::fromStdString(silabo->getNombreClase()));
        query.bindValue(4, silabo->getEstado());
        query.bindValue(5, silabo->getSubidoPor().c_str());
        query.bindValue(6, QByteArray(buffer.data(), (int)buffer.size()));

        if (!query.exec())
        {
            qDebug() << "Error: failed to insert silabo into database -" << query.lastError().text();
            return false;
        }

        if (!connection.commit())
        {
            qDebug() << "Error: failed to commit transaction -" << connection.lastError().text();
            return false;
        }

        // TODO: Verificar si hay cuadro de fechas y guardarlo.

        /*
        query.prepare("INSERT INTO CuadroFechas (silabo, archivo) VALUES (?, ?)");
        query.bindValue(0, silabo->getId());
        query.bindValue(1, QByteArray(buffer.data(), static_cast<int>(buffer.size())));

        if (!query.exec()) {
            qDebug() << "Error: failed to insert file into database -" << query.lastError().text();
            return false;
        } else {
            qDebug() << "File successfully saved to the database.";
            return true;
        }
        */

        return true;
    }

    bool writeFiles(int silaboId)
    {
        QSqlQuery query(connection);
        query.prepare("SELECT codigoClase, nombre, archivo FROM Silabos WHERE id = ?");
        query.bindValue(0, silaboId);

        if (!query.exec() || !query.next())
        {
            qDebug() << "Error: failed to retrieve file from database -" << query.lastError().text();
            return false;
        }

        QString codigoClase = query.value(0).toString();
        QString nombreArchivo = query.value(1).toString();
        QByteArray fileData = query.value(2).toByteArray();

        QDir homeDir = QDir::home();
        QDir silabosDir = homeDir.filePath("silabos");

        if (!silabosDir.exists())
        {
            if (!homeDir.mkpath("silabos"))
            {
                qDebug() << "Error: failed to create directory -" << silabosDir.path();
                return false;
            }
        }

        QString filePath = silabosDir.filePath(nombreArchivo);
        QFile file(filePath);

        if (!file.open(QIODevice::WriteOnly))
        {
            qDebug() << "Error: failed to open file for writing -" << filePath;
            return false;
        }

        file.write(fileData);
        file.close();
        qDebug() << "File successfully written to" << filePath;
        return true;
    }

    bool saveUser(Usuario user) {

        QSqlQuery query(connection);

        query.prepare("INSERT INTO Usuarios(numeroCuenta, nombre, clave, org, tipo, carrera) VALUES(?, ?, ?, ?, ?, ?);");
        query.bindValue(0, user.getCuenta().c_str());
        query.bindValue(1, user.getName().c_str());
        query.bindValue(2, user.getContrasena().c_str());
        query.bindValue(3, user.getInstitucion().c_str());
        query.bindValue(4, user.getTipo().c_str());
        query.bindValue(5, user.getCarrera().c_str());

        if (!query.exec()) {
            qDebug() << "[saveUser] error guardando.";
            return false;
        }

        return true;

    }

    bool loadUsers(listaD<Usuario> &usuarios) {
        QSqlQuery query(connection);

        if (!query.exec("SELECT numeroCuenta, nombre, clave, org, tipo, carrera FROM Usuarios")) {
            qDebug() << "Error: failed to retrieve users from database -" << query.lastError().text();
            return false;
        }

        while (query.next()) {
            string numeroCuenta = query.value(0).toString().toStdString();
            string nombre = query.value(1).toString().toStdString();
            string clave = query.value(2).toString().toStdString();
            string org = query.value(3).toString().toStdString();
            string tipo = query.value(4).toString().toStdString();
            string carrera = query.value(5).toString().toStdString();

            Usuario user(nombre, numeroCuenta, clave, org, tipo, carrera);
            usuarios.InsertarFin(user);
        }

        qDebug() << "Users successfully loaded from database.";
        return true;
    }

    bool actualizarUsuario(Usuario user) {
        if (!connection.isOpen()){
            connection.open();
        }

        QSqlQuery query(connection);
        query.prepare("UPDATE Usuarios SET clave = :clave WHERE numeroCuenta = :numeroCuenta;");
        query.bindValue(":clave", QString::fromStdString(user.getContrasena()));
        query.bindValue(":numeroCuenta", QString::fromStdString(user.getCuenta()));

        if (!query.exec()) {
            qDebug() << "Error al ejecutar el query de actualización del usuario:" << query.lastError().text();
            return false;
        }
        qDebug() << "Usuario actualizado correctamente. Cuenta:" << QString::fromStdString(user.getCuenta()) << "Nueva contraseña:" << QString::fromStdString(user.getContrasena());

        return true;
    }

    bool loadSilabos(ArbolB &arbolSilabos) {
        QSqlQuery query(connection);

        if (!query.exec("SELECT id, nombre, carrera, codigoClase, nombreClase, estado, subidoPor, archivo FROM Silabos")) {
            qDebug() << "Error: failed to retrieve silabos from database -" << query.lastError().text();
            return false;
        }

        while (query.next()) {
            int id = query.value(0).toInt();
            string nombreArchivo = query.value(1).toString().toStdString();
            string carrera = query.value(2).toString().toStdString();
            string codigoClase = query.value(3).toString().toStdString();
            string nombreClase = query.value(4).toString().toStdString();
            Estado estado = static_cast<Estado>(query.value(5).toInt());
            string subidoPor = query.value(6).toString().toStdString();
            QByteArray archivoDataArray = query.value(7).toByteArray();
            //            CuadroFechas* cuadrofecha = new CuadroFechas(id, nombreArchivo,estado,observacion,revisiones,id);

            // Crear objeto Silabo con el archivo
            //Silabo* silabo = new Silabo(id,nombreArchivo,estado,". . .",0,"",carrera,codigoClase,ruta,nombreClase,subidoPor,cuadrofecha);
            //arbolSilabos.insertar(silabo);

        }

        qDebug() << "Silabos successfully loaded from database.";
        return true;
    }



};

#endif // DATABASE_H
