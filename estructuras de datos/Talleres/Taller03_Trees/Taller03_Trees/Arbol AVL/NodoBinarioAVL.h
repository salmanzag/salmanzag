#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

template <class T>
class NodoBinarioAVL {
public:
    T dato;
    NodoBinarioAVL<T> *hijoIzq;
    NodoBinarioAVL<T> *hijoDer;
    int altura;

    NodoBinarioAVL(); // Constructor por defecto
    ~NodoBinarioAVL(); // Destructor

    T& getDato();
    void setDato(const T& val);
    NodoBinarioAVL<T>* getHijoIzq();
    NodoBinarioAVL<T>* getHijoDer();
    void setHijoIzq(NodoBinarioAVL<T>* izq);
    void setHijoDer(NodoBinarioAVL<T>* der);
};

#include "NodoBinarioAVL.hxx"
#endif // NODOBINARIOAVL_H
