#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>
using std::string;

class Archivo {
public:
    std::string nombrearchivo;
    string estado;
    std::string observacion;
    int numeroderevisiones;
    std::string bytesarchivo;
    int id;

    Archivo(int id, const std::string& nombrearchivo, string estado,
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

    string getEstado() const {
        return estado;
    }

    void setEstado(std::string newEstado) {
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
