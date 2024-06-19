#ifndef SILABO_H
#define SILABO_H

#include <string>
#include <fstream>
#include <vector>
#include <QString>
#include <numeric> // Asegúrate de incluir esta librería para std::accumulate
#include "Archivo.h"
#include "CuadroFechas.h"

using std::string;

class Silabo : public Archivo {
private:
    string facultad;
    string carrera;
    string codigoClase;
    QString ruta;
    string nombreClase;
    string subidoPor; // num cuenta user
    CuadroFechas cuadroFechas;

public:
    Silabo(int id, const string& nombrearchivo, const Estado estado,
           const string& observacion, int numeroderevisiones, const string& bytesarchivo,
           const string& facultad, const string& carrera, const string& codigoClase,
           const QString& ruta, const string& nombreClase, const string subidoPor, const CuadroFechas& cuadroFechas)
        : Archivo(id, nombrearchivo, estado, observacion, numeroderevisiones, bytesarchivo),
        facultad(facultad), carrera(carrera),
        codigoClase(codigoClase), ruta(ruta), nombreClase(nombreClase), subidoPor(subidoPor), cuadroFechas(cuadroFechas) {}

    // Métodos getter
    string getFacultad() const {
        return facultad;
    }

    string getCarrera() const {
        return carrera;
    }

    string getCodigoClase() const {
        return codigoClase;
    }

    QString getRuta() const {
        return ruta;
    }

    string getNombreClase() const {
        return nombreClase;
    }

    string getSubidoPor() const {
        return subidoPor;
    }

    CuadroFechas getCuadrofechas() const {
        return cuadroFechas;
    }

    // Métodos setter
    void setFacultad(const string& nuevaFacultad) {
        facultad = nuevaFacultad;
    }

    void setCarrera(const string& nuevaCarrera) {
        carrera = nuevaCarrera;
    }

    void setCodigoClase(const string& nuevoCodigoClase) {
        codigoClase = nuevoCodigoClase;
    }

    void setRuta(const QString& nuevaRuta) {
        ruta = nuevaRuta;
    }

    void setNombreClase(const string& nuevoNombreClase) {
        nombreClase = nuevoNombreClase;
    }

    void setSubidoPor(const int nuevoSubidoPor) {
        subidoPor = nuevoSubidoPor;
    }

    void setCuadrofechas(const CuadroFechas& newCuadrofechas) {
        cuadroFechas = newCuadrofechas;
    }

    // Método toNum
    long toNum() const {
        return std::accumulate(codigoClase.begin(), codigoClase.end(), 0L);
    }
};

#endif // SILABO_H
