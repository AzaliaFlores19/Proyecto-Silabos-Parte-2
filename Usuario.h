#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using std::string;

class Usuario{
    friend class MainWindow;
private:
public:
    string name,cuenta,tipo,contrasena;
    Usuario();
    Usuario(string name, string cuenta, string contrasena, string tipo);
    ~Usuario();

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
    string getContrasena() const;
    void setContrasena(const string &newContrasena);
};





#endif // USUARIO_H
