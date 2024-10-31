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
        void setRaiz(NodoBinarioAVL<T>* raiz);
        NodoBinarioAVL<T>* getRaiz();
        bool esVacio();
        T& datoRaiz();
        int altura(NodoBinarioAVL<T> *inicio);
        int balanceFactor(NodoBinarioAVL<T> *nodo);
        NodoBinarioAVL<T>* rebalance(NodoBinarioAVL<T>* nodo);
        NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>*& inicio);
        NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>*& inicio);
        bool insertar(T& val);
        bool eliminar(T& val);
        bool buscar(T& val);
        void preOrden(NodoBinarioAVL<T> *inicio);
        void inOrden(NodoBinarioAVL<T> *inicio);
        void posOrden(NodoBinarioAVL<T> *inicio);
};

#include "ArbolBinarioAVL.hxx"

#endif //ARBOLBINARIOAVL_H
