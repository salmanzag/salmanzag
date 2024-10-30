#ifndef VERTICES_H
#define VERTICES_H

#include <cmath>
#include <iostream>

// Definición de la estructura Vertice
struct Vertice {
    float px, py, pz;

    Vertice() : px(0), py(0), pz(0) {}
    Vertice(float x, float y, float z) : px(x), py(y), pz(z) {}

    // Función para calcular la distancia euclidiana entre dos vértices
    float distancia(const Vertice& otro) const {
        return sqrt(pow(px - otro.px, 2) + pow(py - otro.py, 2) + pow(pz - otro.pz, 2));
    }

    // Sobrecarga de operador << para imprimir vértices
    friend std::ostream& operator<<(std::ostream& os, const Vertice& v) {
        os << "(" << v.px << ", " << v.py << ", " << v.pz << ")";
        return os;
    }
};

#endif
