#include "ArbolBinarioAVL.h"
#include <queue>

using namespace std;

template <class T>
ArbolBinarioAVL<T>::ArbolBinarioAVL() {
    this->raiz = NULL;
}

template <class T>
ArbolBinarioAVL<T>::~ArbolBinarioAVL() {
}

template <class T>
void ArbolBinarioAVL<T>::setRaiz(NodoBinarioAVL<T>* raiz) {
    this->raiz = raiz;
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::getRaiz() {
    return this->raiz;
}

template <class T>
bool ArbolBinarioAVL<T>::esVacio() {
    return (this->raiz == NULL);
}

template <class T>
T& ArbolBinarioAVL<T>::datoRaiz() {
    return this->raiz->getDato();
}

template <class T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T> *nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

template <class T>
int ArbolBinarioAVL<T>::balanceFactor(NodoBinarioAVL<T> *nodo) {
    if (nodo == NULL)
        return 0;
    return altura(nodo->getHijoIzq()) - altura(nodo->getHijoDer());
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>*& y) {
    NodoBinarioAVL<T>* x = y->getHijoIzq();
    NodoBinarioAVL<T>* T2 = x->getHijoDer();
    x->setHijoDer(y);
    y->setHijoIzq(T2);
    y->altura = max(altura(y->getHijoIzq()), altura(y->getHijoDer())) + 1;
    x->altura = max(altura(x->getHijoIzq()), altura(x->getHijoDer())) + 1;
    return x;
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>*& x) {
    NodoBinarioAVL<T>* y = x->getHijoDer();
    NodoBinarioAVL<T>* T2 = y->getHijoIzq();
    y->setHijoIzq(x);
    x->setHijoDer(T2);
    x->altura = max(altura(x->getHijoIzq()), altura(x->getHijoDer())) + 1;
    y->altura = max(altura(y->getHijoIzq()), altura(y->getHijoDer())) + 1;
    return y;
}

template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::rebalance(NodoBinarioAVL<T>* nodo) {
    nodo->altura = 1 + max(altura(nodo->getHijoIzq()), altura(nodo->getHijoDer()));
    int balance = balanceFactor(nodo);

    if (balance > 1) {
        if (balanceFactor(nodo->getHijoIzq()) < 0)
            nodo->setHijoIzq(giroIzquierda(nodo->getHijoIzq()));
        return giroDerecha(nodo);
    }

    if (balance < -1) {
        if (balanceFactor(nodo->getHijoDer()) > 0)
            nodo->setHijoDer(giroDerecha(nodo->getHijoDer()));
        return giroIzquierda(nodo);
    }

    return nodo;
}

template <class T>
NodoBinarioAVL<T>* insertarNodo(NodoBinarioAVL<T>* nodo, T& val) {
    if (nodo == nullptr)
        return new NodoBinarioAVL<T>(val);

    if (val < nodo->getDato())
        nodo->setHijoIzq(insertarNodo(nodo->getHijoIzq(), val));
    else if (val > nodo->getDato())
        nodo->setHijoDer(insertarNodo(nodo->getHijoDer(), val));
    else
        return nodo;

    return rebalance(nodo);
}

template <class T>
bool ArbolBinarioAVL<T>::insertar(T& val) {
    this->raiz = insertarNodo(this->raiz, val);
    return true;
}
