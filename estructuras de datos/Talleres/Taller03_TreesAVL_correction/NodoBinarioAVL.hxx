#include "NodoBinarioAVL.h"

template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL() {
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->altura = 1;  // La altura inicial del nodo es 1
}

template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL(T val) {
    this->dato = val;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->altura = 1;  // La altura inicial del nodo es 1
}

template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL() {
}

template <class T>
T& NodoBinarioAVL<T>::getDato() {
    return this->dato;
}

template <class T>
void NodoBinarioAVL<T>::setDato(T& val) {
    this->dato = val;
    return;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq() {
    return this->hijoIzq;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer() {
    return this->hijoDer;
}

template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq) {
    this->hijoIzq = izq;
    return;
}

template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der) {
    this->hijoDer = der;
    return;
}
