#include <iostream>
#include "ArbolBinario.h"
#include "NodoBinario.h"
#include "ArbolBinario.hxx"  // Incluir las implementaciones
#include "NodoBinario.hxx"   // Incluir las implementaciones

int main() {
    // Crear un árbol binario de enteros
    ArbolBinario<int> arbol;

    // Verificar si el árbol está vacío
    if (arbol.esVacio()) {
        std::cout << "El árbol está vacío." << std::endl;
    }

    // Insertar elementos en el árbol
    int valores[] = {10, 5, 15, 3, 7, 12, 17};
    for (int valor : valores) {
        arbol.insertar(valor, arbol.getRaiz());
    }

    // Mostrar el tamaño del árbol
    std::cout << "Tamaño del árbol: " << arbol.tamano(arbol.getRaiz()) << std::endl;

    // Mostrar la altura del árbol
    std::cout << "Altura del árbol: " << arbol.altura(arbol.getRaiz()) << std::endl;

    // Realizar diferentes recorridos
    std::cout << "Recorrido PreOrden: ";
    arbol.preOrden(arbol.getRaiz());
    std::cout << std::endl;

    std::cout << "Recorrido InOrden: ";
    arbol.inOrden(arbol.getRaiz());
    std::cout << std::endl;

    std::cout << "Recorrido PosOrden: ";
    arbol.posOrden(arbol.getRaiz());
    std::cout << std::endl;

    // Buscar un valor en el árbol
    int valorBuscado = 7;
    if (arbol.buscar(valorBuscado)) {
        std::cout << "Valor " << valorBuscado << " encontrado en el árbol." << std::endl;
    } else {
        std::cout << "Valor " << valorBuscado << " no encontrado en el árbol." << std::endl;
    }

    // Eliminar un valor del árbol
    int valorEliminar = 15;
    if (arbol.eliminar(valorEliminar)) {
        std::cout << "Valor " << valorEliminar << " eliminado del árbol." << std::endl;
    } else {
        std::cout << "Valor " << valorEliminar << " no encontrado en el árbol." << std::endl;
    }

    // Mostrar el árbol después de eliminar
    std::cout << "Recorrido InOrden después de eliminar: ";
    arbol.inOrden(arbol.getRaiz());
    std::cout << std::endl;

    return 0;
}
