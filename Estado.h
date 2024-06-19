#ifndef ESTADO_H
#define ESTADO_H

#include <string>

using std::string;

struct EstadoNombres {
    string nombres[11] = {"Prerevision", "ListoRevision", "Aprobado", "AprobadoCondicion", "AprobadoIEDD", "SolicitudCambio", "DevueltoAcademia", "Coreccion", "CorreccionMayor", "CorrecionMenor", "Rechazar"};
};

enum Estado {
    // Cuando coordinador o jefe lo recibe
    Prerevision,

    // Cuando pasa a IEDD
    ListoRevision,

    // Tipos de aprobacion (Consultor)
    Aprobado,
    AprobadoCondicion,
    AprobadoIEDD,

    // Cambios

    // Cuando se le vuelve a pedir a Docente que modifique desde cero.
    SolicitudCambio,

    DevueltoAcademia,

    // Subidas despues de corregir (Consultor)
    Correcion,
    CorrecionMayor,
    CorrecionMenor,

    Rechazar



};

#endif // ESTADO_H
