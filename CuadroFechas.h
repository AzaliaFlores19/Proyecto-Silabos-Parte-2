#ifndef CUADROFECHAS_H
#define CUADROFECHAS_H

#include "Archivo.h"

class CuadroFechas : public Archivo {
public:
    int silabo;
    std::string archivoBlob;

    CuadroFechas(int id, const std::string& nombrearchivo, string estado,
                 const std::string& observacion, int numeroderevisiones, const std::string& bytesarchivo,
                 int silabo, const std::string& archivoBlob)
        : Archivo(id, nombrearchivo, estado, observacion, numeroderevisiones, bytesarchivo),
        silabo(silabo), archivoBlob(archivoBlob) {}

    // Métodos getter y setter
    int getSilabo() const {
        return silabo;
    }

    void setSilabo(int newSilabo) {
        silabo = newSilabo;
    }

    const std::string& getArchivoBlob() const {
        return archivoBlob;
    }

    void setArchivoBlob(const std::string& newArchivoBlob) {
        archivoBlob = newArchivoBlob;
    }
};

#endif // CUADROFECHAS_H
