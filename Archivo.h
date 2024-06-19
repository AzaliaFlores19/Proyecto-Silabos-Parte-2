#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>
#include "Estado.h"
#include <vector>
#include <iostream>
using std::string;

class Archivo {
public:
    int id;
    string nombreArchivo;
    Estado estado;
    string observacion;
    int revisiones = 0;
    string ruta;

    // Declaración y definición del constructor por defecto
    Archivo() : id(0), nombreArchivo(""), estado(Estado(Prerevision)), observacion(""), revisiones(0), ruta("") {}

    // Constructor parametrizado
    Archivo(int id, string nombreArchivo, string ruta, Estado estado, string observacion, int revisiones) {
        this->id = id;
        this->nombreArchivo = nombreArchivo;
        this->ruta = ruta;
        this->estado = estado;
        this->observacion = observacion;
        this->revisiones = revisiones;
    }

    Archivo(int id, string nombreArchivo, string ruta, Estado estado, string observacion) {
        this->id = id;
        this->ruta = ruta;
        this->nombreArchivo = nombreArchivo;
        this->estado = estado;
        this->observacion = observacion;
        this->revisiones = 0;
    }

    std::vector<char> getFileToBytes() {
        string filePath = ruta;
        std::ifstream file(filePath, std::ios::binary | std::ios::ate);

        std::vector<char> dummy; // por si hay error
        if (!file) {
            std::cerr << "[Archivo.getFileToBytes] Error: could not open file " << filePath << std::endl;


            return dummy;
        }


        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);
        std::vector<char> buffer(size);


        if (!file.read(buffer.data(), size)) {
            std::cerr << "[Archivo.getFileToBytes] Error: could not read file " << filePath << std::endl;
            return dummy;
        }

        return buffer;

    }

    ~Archivo() {}

    int getId() const {
        return id;
    }

    void setId(int newId) {
        id = newId;
    }

    const string getNombreArchivo() const {
        return nombreArchivo;
    }

    string getRuta() {
        return ruta;
    }

    void settRuta(const string ruta) {
        this->ruta = ruta;
    }

    void setNombreArchivo(const std::string& newNombreArchivo) {
        nombreArchivo = newNombreArchivo;
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

    int getRevisiones() const {
        return revisiones;
    }

    void setNumeroderevisiones(int newNumeroderevisiones) {
        revisiones = newNumeroderevisiones;
    }
};

#endif // ARCHIVO_H
