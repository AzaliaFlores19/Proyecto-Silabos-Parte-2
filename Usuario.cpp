#include "Usuario.h"

const std::string &Usuario::getName() const {
    return name;
}

void Usuario::setName(const std::string &newName) {
    name = newName;
}

const std::string &Usuario::getCuenta() const {
    return cuenta;
}

void Usuario::setCuenta(const std::string &newCuenta) {
    cuenta = newCuenta;
}

const std::string &Usuario::getTipo() const {
    return tipo;
}

void Usuario::setTipo(const std::string &newTipo) {
    tipo = newTipo;
}

string Usuario::getContrasena() const
{
    return contrasena;
}

void Usuario::setContrasena(const string &newContrasena)
{
    contrasena = newContrasena;
}

Usuario::Usuario() {
    this->name = "";
    this->cuenta = "";
    this->contrasena = "";
    this->tipo = "";
}

Usuario::Usuario(std::string name, std::string cuenta, std::string contrasena, std::string tipo) {
    this->name = name;
    this->cuenta = cuenta;
    this->contrasena = contrasena;
    this->tipo = tipo;
}

Usuario::~Usuario() {}

