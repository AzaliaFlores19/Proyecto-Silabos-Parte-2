#ifndef SILABO_H
#define SILABO_H

#include <string>
#include <fstream>
#include <vector>
#include <QString>
#include "Archivo.h"

using std::string;

class Silabo : public Archivo {
private:
    string facultad;
    string carrera;
    string codigoClase;
    QString ruta;
    string nombreClase;
    string subidoPor;

public:
    Silabo(int id, const string& nombrearchivo, string estado,
           const string& observacion, int numeroderevisiones, const string& bytesarchivo,
           const string& facultad, string carrera, const string& codigoClase,
           const QString& ruta, const string& nombreClase, const string& subidoPor)
        : Archivo(id, nombrearchivo, estado, observacion, numeroderevisiones, bytesarchivo),
        facultad(facultad), carrera(carrera),
        codigoClase(codigoClase), ruta(ruta), nombreClase(nombreClase), subidoPor(subidoPor) {}

    ~Silabo() {}

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

    void setFacultad(const string& nuevaFacultad) {
        facultad = nuevaFacultad;
    }

    void setCarrera(string nuevaCarrera) {
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

    void setSubidoPor(const string& nuevoSubidoPor) {
        subidoPor = nuevoSubidoPor;
    }

    long toNum() const {
        long val = 0;
        for (int i = 0; i < codigoClase.size(); i++) {
            char c = codigoClase[i];
            val += c;
        }

        return val;
    }
};

#endif // SILABO_H
