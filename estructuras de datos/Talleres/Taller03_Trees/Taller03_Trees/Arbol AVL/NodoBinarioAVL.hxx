#include "NodoBinarioAVL.h"

template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL() : hijoIzq(nullptr), hijoDer(nullptr), altura(0) {}

template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL() {}

template <class T>
T& NodoBinarioAVL<T>::getDato() {
    return this->dato;
}

template <class T>
void NodoBinarioAVL<T>::setDato(const T& val) {
    this->dato = val;
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
}

template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der) {
    this->hijoDer = der;
}
