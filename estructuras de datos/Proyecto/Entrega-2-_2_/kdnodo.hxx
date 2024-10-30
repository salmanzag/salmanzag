#include "kdnodo.h"

template<class T>
kdnodo<T>::kdnodo() {
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
    this->tag = 0;
}

template<class T>
T& kdnodo<T>::obtenerDato() {
    return dato;
}

template<class T>
void kdnodo<T>::fijarDato(const T& val) {
    dato = val;
}

template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoIzq() {
    return hijoIzq;
}

template<class T>
void kdnodo<T>::fijarHijoIzq(kdnodo<T>* izq) {
    hijoIzq = izq;
}

template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoDer() {
    return hijoDer;
}

template<class T>
void kdnodo<T>::fijarHijoDer(kdnodo<T>* der) {
    hijoDer = der;
}

template<class T>
int kdnodo<T>::obtenerTag() {
    return tag;
}

template<class T>
void kdnodo<T>::fijarTag(int value) {
    tag = value;
}
