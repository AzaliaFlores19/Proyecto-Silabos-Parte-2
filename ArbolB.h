#ifndef ARBOL_B_H
#define ARBOL_B_H

#include "NodoArbolB.h"
#include <iostream>

class ArbolB {
private:
    NodoArbolB* root;
    int t;
    int cantidadArbol;

    void mostrarDetalles(NodoArbolB* node) {
        if (node != nullptr) {
            for (int i = 0; i < node->getN(); i++) {
                mostrarDetalles(node->getChild(i));
                Silabo* silabo = node->getSilabo(i);
                std::cout << "Facultad: " << silabo->getFacultad() << ", Carrera: " << silabo->getCarrera()
                          << ", Nombre del curso: " << silabo->getNombreClase() << ", Código de clase: " << silabo->getCodigoClase()
                          << ", Ruta: " << silabo->getRuta().toStdString() << ", Estado: " << silabo->getEstado()
                          << ", Observación: " << silabo->getObservacion() << ", ID: " << silabo->getId()
                          << ", Número de revisiones: " << silabo->getNumeroderevisiones() << ", Subido Por: "<< silabo->getSubidoPor()<< std::endl;
            }
            mostrarDetalles(node->getChild(node->getN()));  // Recursión en el último hijo
        }
    }

    void split(NodoArbolB* x, int i, NodoArbolB* y) {
        NodoArbolB* z = new NodoArbolB(t);
        z->setLeaf(y->isLeaf());
        z->setN(t - 1);

        for (int j = 0; j < t - 1; j++) {
            z->setSilabo(j, y->getSilabo(j + t));
        }

        if (!y->isLeaf()) {
            for (int k = 0; k < t; k++) {
                z->setChild(k, y->getChild(k + t));
            }
        }

        y->setN(t - 1);

        for (int j = x->getN(); j > i; j--) {
            x->setChild(j + 1, x->getChild(j));
        }

        x->setChild(i + 1, z);

        for (int j = x->getN() - 1; j >= i; j--) {
            x->setKey(j + 1, x->getKey(j));
        }

        x->setSilabo(i, y->getSilabo(t - 1));
        x->setN(x->getN() + 1);
    }

    void nonFullInsert(NodoArbolB* x, Silabo* silabo) {
        int i = x->getN() - 1;

        if (x->isLeaf()) {
            while (i >= 0 && silabo->toNum() < x->getKey(i)) {
                x->setSilabo(i + 1, x->getSilabo(i));
                i--;
            }
            x->setSilabo(i + 1, silabo);
            x->setN(x->getN() + 1);
        } else {
            int j = 0;
            while (j < x->getN() && silabo->toNum() > x->getKey(j)) {
                j++;
            }
            if (x->getChild(j)->getN() == 2 * t - 1) {
                split(x, j, x->getChild(j));
                if (silabo->toNum() > x->getKey(j)) {
                    j++;
                }
            }
            nonFullInsert(x->getChild(j), silabo);
        }
    }

    NodoArbolB* search(NodoArbolB* current, Silabo* silabo) {
        int i = 0;
        while (i < current->getN() && silabo->toNum() > current->getKey(i)) {
            i++;
        }

        if (i < current->getN() && silabo->toNum() == current->getKey(i)) {
            return current;
        }

        if (current->isLeaf()) {
            return nullptr;
        } else {
            return search(current->getChild(i), silabo);
        }
    }

    void print(NodoArbolB* n) {
        if (n != nullptr) {
            n->imprimir();
            if (!n->isLeaf()) {
                std::cout << std::endl;
                for (int j = 0; j <= n->getN(); j++) {
                    print(n->getChild(j));
                }
            }
        }
    }

public:
    ArbolB(int t) : t(t), cantidadArbol(0) {
        root = new NodoArbolB(t);
    }

    NodoArbolB* getRaiz() const {
        return root;
    }

    int getCantidadArbol() const {
        return cantidadArbol;
    }

    void mostrarDetallesSilabos() {
        std::cout << "Detalles de todos los Silabos en el Arbol B:" << std::endl;
        mostrarDetalles(root);
    }

    void insertar(Silabo* silabo) {
        cantidadArbol++;
        if (root->getN() == 2 * t - 1) {
            NodoArbolB* s = new NodoArbolB(t);
            s->setLeaf(false);
            s->setChild(0, root);
            split(s, 0, root);
            root = s;
            nonFullInsert(s, silabo);
        } else {
            nonFullInsert(root, silabo);
        }
    }

    void buscarNodoPorSilabo(Silabo* silabo) {
        NodoArbolB* result = search(root, silabo);
        if (result == nullptr) {
            std::cout << "No se ha encontrado un nodo con el valor ingresado" << std::endl;
        } else {
            result->imprimir();
        }
    }

    void showBTree() {
        print(root);
    }
};

#endif // ARBOL_B_H
