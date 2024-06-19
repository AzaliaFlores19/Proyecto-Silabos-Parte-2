#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>
#include "Estado.h"
using std::string;

class Archivo {
public:
    int id;
    std::string nombrearchivo;
    Estado estado;
    std::string observacion;
    int numeroderevisiones;
    std::string bytesarchivo;

    // Declaración y definición del constructor por defecto
    Archivo() : id(0), nombrearchivo(""), estado(Estado(Prerevision)), observacion(""), numeroderevisiones(0), bytesarchivo("") {}

    // Constructor parametrizado
    Archivo(int id, const std::string& nombrearchivo, const Estado estado,
            const std::string& observacion, int numeroderevisiones, const std::string& bytesarchivo)
        : id(id), nombrearchivo(nombrearchivo), estado(estado),
        observacion(observacion), numeroderevisiones(numeroderevisiones), bytesarchivo(bytesarchivo) {}

    ~Archivo() {}

    int getId() const {
        return id;
    }

    void setId(int newId) {
        id = newId;
    }

    const std::string& getNombreArchivo() const {
        return nombrearchivo;
    }

    void setNombreArchivo(const std::string& newNombreArchivo) {
        nombrearchivo = newNombreArchivo;
    }

    Estado getEstado() const {
        return estado;
    }

    void setEstado(Estado newEstado) {
        estado = newEstado;
    }

    const std::string& getObservacion() const {
        return observacion;
    }

    void setObservacion(const std::string& newObservacion) {
        observacion = newObservacion;
    }

    int getNumeroderevisiones() const {
        return numeroderevisiones;
    }

    void setNumeroderevisiones(int newNumeroderevisiones) {
        numeroderevisiones = newNumeroderevisiones;
    }

    const std::string& getBytesarchivo() const {
        return bytesarchivo;
    }

    void setBytesarchivo(const std::string& newBytesarchivo) {
        bytesarchivo = newBytesarchivo;
    }
};

#endif // ARCHIVO_H
