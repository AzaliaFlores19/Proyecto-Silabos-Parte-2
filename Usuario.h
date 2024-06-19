#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using std::string;

class Usuario{
    friend class MainWindow;
private:
public:
    string name,cuenta,contrasena, institucion, tipousuario, carrera;
    Usuario(string name, string cuenta, string contrasena, string institucion, string tipousuario, string carrera)
    {
        this->name = name;
        this->cuenta = cuenta;
        this->contrasena = contrasena;
        this->institucion = institucion;
        this->tipousuario = tipousuario;
        this->carrera = carrera;

    }
    ~Usuario(){}

    /*
    - [ ] Directores - solo Visualización
    - [ ] Decanos - solo Visualización
    ???
    */


    const string &getName() const;
    void setName(const string &newName);
    const string &getCuenta() const;
    void setCuenta(const string &newCuenta);
    const string &getTipo() const;
    void setTipo(const string &newTipo);
    const string &getContrasena() const;
    void setContrasena(const string &newContrasena);
    const string &getInstitucion() const;
    void setInstitucion(const string &newInstitucion);

    string getCarrera() {
        return carrera;
    }
};
inline const string &Usuario::getCuenta() const
{
    return cuenta;
}

inline void Usuario::setCuenta(const string &newCuenta)
{
    cuenta = newCuenta;
}

inline const string &Usuario::getTipo() const
{
    return tipousuario;
}

inline void Usuario::setTipo(const string &newTipo)
{
    tipousuario = newTipo;
}

inline const string &Usuario::getContrasena() const
{
    return contrasena;
}

inline void Usuario::setContrasena(const string &newContrasena)
{
    contrasena = newContrasena;
}

inline const string &Usuario::getInstitucion() const
{
    return institucion;
}

inline void Usuario::setInstitucion(const string &newInstitucion)
{
    institucion = newInstitucion;
}

inline const string &Usuario::getName() const
{
    return name;
}

inline void Usuario::setName(const string &newName)
{
    name = newName;
}





#endif // USUARIO_H

