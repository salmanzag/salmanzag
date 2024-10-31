#include "ArbolBinario.h"

using namespace std;

ArbolBinario::ArbolBinario(){
	this->raiz=NULL;
}

ArbolBinario::~ArbolBinario(){
}

bool ArbolBinario::esVacio(){
	if(this->raiz==NULL){
		return true;
	}
	return false;
}

template <class T>
T& ArbolBinario::datoRaiz(){
	return (this->raiz).getDato();
}

template <class T>
int ArbolBinario::altura(NodoBinario<T> *inicio){
	int alturaIzq=0;
	int alturaDer=0;
	if(inicio==NULL){
		return -1;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()!=NULL){
		alturaIzq+=altura(inicio->gethijoIzq())+1;
	}
	if(inicio->getHijoDer()!=NULL){
		alturaDer+=altura(inicio->gethijoDer())+1;
	}
	alturaIzq>alturaDer?return (alturaIzq):return (alturaDer);
}

template <class T>
int ArbolBinario::tamano(NodoBinario<T> *inicio){
	int nodosIzq=0;
	int nodosDer=0;
	if(inicio==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 1;
	}
	if(inicio->getHijoIzq()!=NULL){
		nodosIzq+=tamano(inicio->gethijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		nodosDer+=tamano(inicio->gethijoDer());
	}
	return nodosIzq+nodosDer+1;
}

bool ArbolBinario::insertar(T& val, NodoBinario<T> *nod){

	//crea nodo a insertar
	NodoBinario<T> *nodito = new NodoBinario();
	nodito->setDato(val);

	// inserta en la raiz si no existia antes
	if(this->raiz== NULL)
		{
			this->raiz=nodito;
			return true;
		}
	// empieza recorrer por la izquiera si el valor es menor
	else if(val<nod->getDato())
	{
		//recorre los hijos de los hijos del hijo izquerdo
		if(nod->getHijoIzq!=NULL)
		{
			insertar(val,nod->getHijoIzq);
		}
		// cuando ya no exite un hijo izquierdo inserta
		else
		{
			nod->setHijoDer(nodito);
			return true;
		}
	}
	else if(val>nod->getDato())
	{
		//recorre los hijos de los hijos del hijo derecho
		if(nod->getHijoDer!=NULL)
		{
			insertar(val,nod->getHijoDer);
		}
		// cuando ya no exite un hijo izquierdo inserta
		else
		{
			nod->setHijoDer(nodito);
			return true;
		}
	}
	// si nunca inserto en hijo izquierdo o derecho , es porque ya existe
	else
	{
		return false;
	}
}







}

}
