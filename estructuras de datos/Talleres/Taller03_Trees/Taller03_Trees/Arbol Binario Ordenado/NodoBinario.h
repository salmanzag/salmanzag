#ifndef NODOBINARIO_H
#define NODOBINARIO_H

template <class T>

class NodoBinario{
	protected:
		T dato;
		NodoBinario<T> *hijoIzq;
		NodoBinario<t> *hijoDer;

	public:
		NodoBinario();
		~NodoBinario();
		T& getDato();
		void setDato(T& val);
		NodoBinario<T>* getHijoIzq();
		NodoBinario<T>* getHijoDer();
		void setHijoIzq(NodoBinario<T> *izq);
		void setHijoDer(NodoBinario<T> *der);
};

#endif //NODOBINARIO_H
