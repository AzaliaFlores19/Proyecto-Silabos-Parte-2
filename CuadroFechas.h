#ifndef CUADROFECHAS_H
#define CUADROFECHAS_H

#include "Archivo.h"
#include <string>

class CuadroFechas : public Archivo {
public:
    int silabo;

    // Constructor por defecto
    CuadroFechas() : Archivo(), silabo(-1) {}

    // Constructor parametrizado
    CuadroFechas(int id, std::string nombrearchivo, Estado estado,
                 std::string observacion, int numeroderevisiones,
                 int silabo) {
        this->id = id;
        this->nombreArchivo = nombrearchivo;
        this->estado = estado;
        this->observacion = std::move(observacion);
        this->revisiones= numeroderevisiones;
        this->silabo = silabo;
    }

    // Métodos getter y setter
    int getSilabo() const {
        return silabo;
    }

    void setSilabo(int newSilabo) {
        silabo = newSilabo;
    }
};

#endif // CUADROFECHAS_H
