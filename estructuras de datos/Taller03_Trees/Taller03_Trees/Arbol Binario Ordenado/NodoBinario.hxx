#include "NodoBinario.h"

using namespace std;

NodoBinario::NodoBinario(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}

NodoBinario::~NodoBinario(){
}

template <class T>
T& NodoBinario::getDato(){
	return this->dato;
}

template <class T>
void NodoBinario::setDato(T& val){
	this->dato=val;
	return;
}

template <class T>
NodoBinario<T>* NodoBinario::getHijoIzq(){
	return this->hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario::getHijoDer(){
	return this->hijoDer;
}

template <class T>
void NodoBinario::setHijoIzq(NodoBinario<T>* izq){
	this->hijoIzq=izq;
	return;
}

template <class T>
void NodoBinario::setHijoIzq(NodoBinario<T>* der){
	this->hijoDer=der;
	return;
}
