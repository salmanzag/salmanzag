#ifndef __KDNODO__H__
#define __KDNODO__H__

using namespace std;

template< class T >
class kdnodo
{
  protected:
    vector < T > datos;
    kdnodo<T> *hijoIzq;
    kdnodo<T> *hijoDer;
    int tag;

  public:
  	kdnodo();
    T& obtenerDato();
    void fijarDato(vector < T > & val);
    kdnodo<T>* obtenerHijoIzq();
    kdnodo<T>* obtenerHijoDer();
    void fijarHijoIzq(kdnodo<T> *izq);
    void fijarHijoDer(kdnodo<T> *der);
    void fijarTag(int value);
    int altura();
    int tamano();
    void insertar(vector < T > & val);
    kdnodo<T>* buscar(vector < T > & val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    void maximo(int &maxi);
    void minimo(int &mini);
    void imprimir();
};

#include "kdnodo.hxx"
#endif
