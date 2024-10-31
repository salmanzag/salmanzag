#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "NodoBinario.h"

template <class T>

class ArbolBinario {
    protected:
        NodoBinario<T>* raiz;  // Raíz del árbol

    public:
        ArbolBinario();
        ~ArbolBinario();
        bool esVacio();
        T& datoRaiz();
        int altura(NodoBinario<T>* inicio);
        int tamano(NodoBinario<T>* inicio);
        bool insertar(T& val, NodoBinario<T>* nodo);
        bool eliminar(T& val);
        bool buscar(T& val);
        void preOrden(NodoBinario<T>* inicio);
        void inOrden(NodoBinario<T>* inicio);
        void posOrden(NodoBinario<T>* inicio);
        void nivelOrden(NodoBinario<T>* inicio);
        // Nuevo método getRaiz() para obtener la raíz
        NodoBinario<T>* getRaiz() {
            return raiz;
        }
};

#endif // ARBOLBINARIO_H
