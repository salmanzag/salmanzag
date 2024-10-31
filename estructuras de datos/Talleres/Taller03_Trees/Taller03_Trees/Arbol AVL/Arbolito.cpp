#include "ArbolBinarioAVL.h"
#include <iostream>

int main() {
    ArbolBinarioAVL<int> arbolito;

    char operacion;
    int valor;

    while (true) {
        std::cin >> operacion >> valor;
        if (operacion == 'A') {
            arbolito.insertar(valor);
        } else if (operacion == 'E') {
            arbolito.eliminar(valor);
        } else {
            break;
        }
    }

    std::cout << "Recorrido Inorden:" << std::endl;
    arbolito.inOrden(arbolito.getRaiz());

    return 0;
}
