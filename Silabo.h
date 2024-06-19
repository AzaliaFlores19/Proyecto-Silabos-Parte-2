#ifndef SILABO_H
#define SILABO_H

#include <string>
#include <fstream>
#include <vector>
#include <QString>
#include <numeric> // Asegúrate de incluir esta librería para std::accumulate
#include "Archivo.h"
#include "CuadroFechas.h"
#include <iostream>

using std::string;

class Silabo : public Archivo {
private:
    string facultad;
    string carrera;
    string codigoClase;
    string nombreClase;
    string subidoPor; // num cuenta user
    CuadroFechas *cuadroFechas;

public:
    Silabo(int id, const string& nombrearchivo, const Estado estado,
                   const string& observacion, int numeroderevisiones,
                   const string& facultad, const string& carrera, const string& codigoClase,
                   const string& ruta, const string& nombreClase, const string subidoPor, CuadroFechas *cuadroFechas) {
        this->id = id;
        this->nombreArchivo = nombrearchivo;
        this->estado = estado;
        this->observacion = observacion;
        this->revisiones= numeroderevisiones;
        this->facultad = facultad;
        this->carrera = carrera;
        this->codigoClase = codigoClase;
        this->ruta = ruta;
        this->nombreClase = nombreClase;
        this->subidoPor = subidoPor;
        this->cuadroFechas = cuadroFechas;
    }

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

    string getNombreClase() const {
        return nombreClase;
    }

    string getSubidoPor() const {
        return subidoPor;
    }

    CuadroFechas* getCuadrofechas() const {
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

    void setNombreClase(const string& nuevoNombreClase) {
        nombreClase = nuevoNombreClase;
    }

    void setSubidoPor(const int nuevoSubidoPor) {
        subidoPor = nuevoSubidoPor;
    }

    void setCuadrofechas(CuadroFechas *newCuadrofechas) {
        cuadroFechas = newCuadrofechas;
    }

    // Método toNum
    long toNum() const {
        return std::accumulate(codigoClase.begin(), codigoClase.end(), 0L);
    }
};

#endif // SILABO_H
