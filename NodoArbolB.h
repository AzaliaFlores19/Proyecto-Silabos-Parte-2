#ifndef NODO_ARBOL_B_H
#define NODO_ARBOL_B_H

#include <iostream>
#include "Silabo.h"

class NodoArbolB {
private:
    int n; // Número de claves almacenadas en el nodo
    bool leaf; // Si el nodo es hoja (true) o interno (false)
    int *key; // Almacena las claves en el nodo para comparación
    Silabo **silabos; // Almacena los objetos Silabo en el nodo
    NodoArbolB **child; // Arreglo de punteros a los hijos

public:
    // Constructor
    NodoArbolB(int t) {
        n = 0;
        leaf = true;
        key = new int[2 * t - 1]; // Tamaño máximo de claves en el nodo
        silabos = new Silabo*[2 * t - 1]; // Tamaño máximo de Silabos en el nodo
        child = new NodoArbolB*[2 * t]; // Tamaño máximo de hijos del nodo
        for (int i = 0; i < 2 * t - 1; i++) {
            silabos[i] = nullptr; // Inicializar punteros a null
        }
        for (int i = 0; i < 2 * t; i++) {
            child[i] = nullptr; // Inicializar punteros a null
        }
    }

    // Destructor
    ~NodoArbolB() {
        delete[] key;
        for (int i = 0; i < 2 * n - 1; i++) {
            delete silabos[i]; // Liberar memoria de Silabos
        }
        delete[] silabos;
        for (int i = 0; i < 2 * n + 1; i++) {
            delete child[i]; // Liberar memoria de hijos
        }
        delete[] child;
    }

    // Método para imprimir el contenido del nodo
    void imprimir() const {
        std::cout << "[";
        for (int i = 0; i < n; i++) {
            std::cout << key[i]; // Opcionalmente muestra más información del Silabo
            if (i < n - 1) std::cout << " | ";
        }
        std::cout << "]" << std::endl;
    }

    // Métodos de acceso y modificación adaptados para Silabo
    int getN() const { return n; }
    void setN(int value) { n = value; }
    bool isLeaf() const { return leaf; }
    void setLeaf(bool value) { leaf = value; }
    Silabo* getSilabo(int index) const { return silabos[index]; }
    void setSilabo(int index, Silabo* silabo) {
        silabos[index] = silabo;
        key[index] = silabo->toNum(); // Actualiza la clave cuando se establece el Silabo
    }
    int getKey(int index) const { return key[index]; }
    void setKey(int index, int value) { key[index] = value; }
    NodoArbolB* getChild(int index) const { return child[index]; }
    void setChild(int index, NodoArbolB* node) { child[index] = node; }
};

#endif // NODO_ARBOL_B_H
