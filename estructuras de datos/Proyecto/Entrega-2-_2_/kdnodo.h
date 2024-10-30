#ifndef KDNODO_H
#define KDNODO_H

#include <iostream>
#include "vertice.h" // Asegúrate de tener la clase Vertice definida

template<class T>
class kdnodo {
private:
    T dato;
    kdnodo<T>* hijoIzq;
    kdnodo<T>* hijoDer;
    int tag;  // 0: X, 1: Y, 2: Z

public:
    kdnodo();
    T& obtenerDato();
    void fijarDato(const T& val);
    kdnodo<T>* obtenerHijoIzq();
    kdnodo<T>* obtenerHijoDer();
    void fijarHijoIzq(kdnodo<T>* izq);
    void fijarHijoDer(kdnodo<T>* der);
    int obtenerTag();
    void fijarTag(int value);
};

#include "kdnodo.hxx"

#endif
	