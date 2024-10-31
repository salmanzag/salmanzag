#include "NodoBinario.h"
#include <cstddef>

using namespace std;
template<class T>
NodoBinario<T>::NodoBinario(){
  this->hijoIzq=NULL;
  this->hijoDer=NULL;
}
template<class T>
NodoBinario<T>::~NodoBinario(){
}

template <class T>
T& NodoBinario<T>::getDato(){
  return this->dato;
}

template <class T>
void NodoBinario<T>::setDato(T& val){
  this->dato=val;
  return;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::getHijoIzq(){
  return this->hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::getHijoDer(){
  return this->hijoDer;
}

template <class T>
void NodoBinario<T>::setHijoIzq(NodoBinario<T>* izq){
  this->hijoIzq=izq;
  return;
}

template <class T>
void NodoBinario<T>::setHijoDer(NodoBinario<T>* der){
  this->hijoDer=der;
  return;
}
