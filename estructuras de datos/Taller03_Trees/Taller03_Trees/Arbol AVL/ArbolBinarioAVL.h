#ifndef ARBOLBINARIOAVL_H
#define ARBOLBINARIOAVL_H

#include "NodoBinarioAVL.h"

template <class T>
class ArbolBinarioAVL {
protected:
    NodoBinarioAVL<T> *raiz;

public:
    ArbolBinarioAVL();
    ~ArbolBinarioAVL();

    NodoBinarioAVL<T>* getRaiz();
    void ArbolBinarioAVL<T>::setRaiz(NodoBinarioAVL<T>* raiz);
    bool esVacio();
    T& datoRaiz();
    int altura(NodoBinarioAVL<T> *inicio);
    int balanceFactor(NodoBinarioAVL<T>* nodo);
    int tamano(NodoBinarioAVL<T> *inicio);
    
    // Rotaciones
    NodoBinarioAVL<T>* rotacionDerecha(NodoBinarioAVL<T>*& nodo);
    NodoBinarioAVL<T>* rotacionIzquierda(NodoBinarioAVL<T>*& nodo);
    NodoBinarioAVL<T>* rotacionIzquierdaDerecha(NodoBinarioAVL<T>*& nodo);
    NodoBinarioAVL<T>* rotacionDerechaIzquierda(NodoBinarioAVL<T>*& nodo);
    NodoBinarioAVL<T>* giroDerechaIzquierda(NodoBinarioAVL<T>* &padre);
    NodoBinarioAVL<T>* giroIzquierdaDerecha(NodoBinarioAVL<T>* &padre);
    NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>* padre);
    NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>* padre);


    // Operaciones del árbol
    bool insertar(const T& val);
    bool eliminar(const T& val);
    bool buscar(const T& val);
    
    // Recorridos
    void preOrden(NodoBinarioAVL<T> *inicio);
    void inOrden(NodoBinarioAVL<T> *inicio);
    void posOrden(NodoBinarioAVL<T> *inicio);
    void nivelOrden(NodoBinarioAVL<T> *inicio);
};

#include "ArbolBinarioAVL.hxx"
#endif // ARBOLBINARIOAVL_H
