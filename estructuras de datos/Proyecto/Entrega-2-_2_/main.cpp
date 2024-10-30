#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>
#include <algorithm>
#include "kdtree.h"
#include "vertice.h"

using namespace std;

struct Cara {
    vector<int> indicesVertices;
};

struct Malla {
    string nombre;
    vector<Vertice> vertices;
    vector<Cara> caras;
    kdtree<Vertice> arbolKD; // KD-Tree para gestionar los vertices
};

// Funcion para convertir una cadena a minusculas
string convertirMinusculas(string cadena) {
    for (char& c : cadena) {
        c = tolower(c);
    }
    return cadena;
}

// Funcion que divide una linea de comando en palabras
vector<string> dividirComando(const string& linea) {
    vector<string> resultado;
    stringstream ss(linea);
    string palabra;
    while (ss >> palabra) {
        resultado.push_back(palabra);
    }
    return resultado;
}

// Funcion para cargar una malla desde un archivo
Malla LecturaMallas(const string& argumento1) {
    Malla malla;
    ifstream archivo(argumento1);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << argumento1 << endl;
        return malla;
    }

    string linea;
    int numVertices = 0;

    getline(archivo, malla.nombre);
    archivo >> numVertices;
    malla.vertices.resize(numVertices);

    // Lectura de los vertices
    for (int i = 0; i < numVertices; i++) {
        archivo >> malla.vertices[i].px >> malla.vertices[i].py >> malla.vertices[i].pz;
        malla.arbolKD.insertar(malla.vertices[i]);
    }

    // Lectura de las caras
    while (true) {
        Cara cara;
        int numIndices;
        archivo >> numIndices;
        if (numIndices == -1) break;
        cara.indicesVertices.resize(numIndices);
        for (int j = 0; j < numIndices; j++) {
            archivo >> cara.indicesVertices[j];
        }
        malla.caras.push_back(cara);
    }

    return malla;
}

// Funcion para encontrar el vertice mas cercano en una malla
void encontrarVerticeCercano(Malla& malla, const Vertice& punto) {
    double mejorDistancia = numeric_limits<double>::max();
    Vertice mejorVertice = malla.arbolKD.encontrarMasCercano(punto, mejorDistancia);

    cout << "El vertice mas cercano es " << mejorVertice << " a una distancia de " << mejorDistancia << endl;
}

// Funcion para listar las mallas cargadas en memoria
void listarMallas(const vector<Malla>& mallas) {
    if (mallas.empty()) {
        cout << "Memoria vacia." << endl;
        return;
    }
    for (const auto& m : mallas) {
        cout << "Objeto: " << m.nombre << ", Vertices: " << m.vertices.size() << ", Caras: " << m.caras.size() << endl;
    }
}

// Funcion para encontrar los vertices mas cercanos a las esquinas de la caja envolvente
void encontrarVerticesCercanosCaja(Malla& malla) {
    // Determinacion de las esquinas de la caja envolvente
    float xmin = numeric_limits<float>::max(), ymin = numeric_limits<float>::max(), zmin = numeric_limits<float>::max();
    float xmax = numeric_limits<float>::min(), ymax = numeric_limits<float>::min(), zmax = numeric_limits<float>::min();

    for (const auto& vertice : malla.vertices) {
        xmin = min(xmin, vertice.px);
        ymin = min(ymin, vertice.py);
        zmin = min(zmin, vertice.pz);
        xmax = max(xmax, vertice.px);
        ymax = max(ymax, vertice.py);
        zmax = max(zmax, vertice.pz);
    }

    // Vertices de las esquinas de la caja envolvente
    Vertice esquinas[8] = {
        {xmin, ymin, zmin}, {xmax, ymin, zmin}, {xmin, ymax, zmin}, {xmax, ymax, zmin},
        {xmin, ymin, zmax}, {xmax, ymin, zmax}, {xmin, ymax, zmax}, {xmax, ymax, zmax}
    };

    // Encontrar el vertice mas cercano para cada esquina
    for (const auto& esquina : esquinas) {
        encontrarVerticeCercano(malla, esquina);
    }
}

// Funcion principal
int main() {
    vector<Malla> mallas; // Almacena todas las mallas cargadas
    string comando;

    cout << "Bienvenido a la aplicacion de modelado de objetos 3D." << endl;
    cout << "Comandos disponibles:" << endl;
    cout << "- cargar <nombre_archivo>" << endl;
    cout << "- v_cercano <px> <py> <pz> <nombre_malla>" << endl;
    cout << "- v_cercanos_caja <nombre_malla>" << endl;
    cout << "- listado" << endl;
    cout << "- salir" << endl;
    cout << "Para obtener ayuda sobre un comando especifico, ingrese 'ayuda <comando>'." << endl;

    while (true) {
        cout << "$ ";
        getline(cin, comando); // Lee el comando completo
        vector<string> partes = dividirComando(comando); // Divide el comando en palabras

        if (partes.empty()) continue; // Si no hay entrada, sigue al siguiente ciclo

        string comandoPrincipal = convertirMinusculas(partes[0]); // Convierte el comando a minusculas

        if (comandoPrincipal == "cargar" && partes.size() == 2) {
            Malla nuevaMalla = LecturaMallas(partes[1]); // Carga la malla desde el archivo
            if (!nuevaMalla.nombre.empty()) mallas.push_back(nuevaMalla); // Solo agrega si la carga fue exitosa
        } else if (comandoPrincipal == "v_cercano" && partes.size() == 5) {
            float px = stof(partes[1]);
            float py = stof(partes[2]);
            float pz = stof(partes[3]);
            string nombreMalla = partes[4];

            // Busca la malla correspondiente
            auto it = find_if(mallas.begin(), mallas.end(), [&](const Malla& m) { return m.nombre == nombreMalla; });
            if (it != mallas.end()) {
                Vertice punto(px, py, pz);
                encontrarVerticeCercano(*it, punto);
            } else {
                cout << "Error: No se encontro la malla " << nombreMalla << endl;
            }
        } else if (comandoPrincipal == "v_cercanos_caja" && partes.size() == 2) {
            string nombreMalla = partes[1];

            // Busca la malla correspondiente
            auto it = find_if(mallas.begin(), mallas.end(), [&](const Malla& m) { return m.nombre == nombreMalla; });
            if (it != mallas.end()) {
                encontrarVerticesCercanosCaja(*it);
            } else {
                cout << "Error: No se encontro la malla " << nombreMalla << endl;
            }
        } else if (comandoPrincipal == "listado") {
            listarMallas(mallas);
        } else if (comandoPrincipal == "salir") {
            break; // Sale del ciclo y termina el programa
        } else if (comandoPrincipal == "ayuda") {
            if (partes.size() == 2) {
                string comandoAyuda = partes[1];
                if (comandoAyuda == "cargar") {
                    cout << "Uso: cargar <nombre_archivo>" << endl;
                    cout << "Carga una malla desde el archivo especificado." << endl;
                } else if (comandoAyuda == "v_cercano") {
                    cout << "Uso: v_cercano <px> <py> <pz> <nombre_malla>" << endl;
                    cout << "Encuentra el vertice mas cercano al punto (px, py, pz) en la malla especificada." << endl;
                } else if (comandoAyuda == "v_cercanos_caja") {
                    cout << "Uso: v_cercanos_caja <nombre_malla>" << endl;
                    cout << "Encuentra los vertices cercanos a las esquinas de la caja envolvente de la malla." << endl;
                } else if (comandoAyuda == "listado") {
                    cout << "Uso: listado" << endl;
                    cout << "Lista todas las mallas cargadas en memoria." << endl;
                } else {
                    cout << "Comando desconocido. Escribe 'ayuda <comando>' para obtener ayuda." << endl;
                }
            } else {
                cout << "Uso: ayuda <comando>" << endl;
                cout << "Proporciona ayuda sobre el comando especificado." << endl;
            }
        } else {
            cout << "Comando desconocido. Comandos disponibles:" << endl;
            cout << "- cargar <nombre_archivo>" << endl;
            cout << "- v_cercano <px> <py> <pz> <nombre_malla>" << endl;
            cout << "- v_cercanos_caja <nombre_malla>" << endl;
            cout << "- listado" << endl;
            cout << "- salir" << endl;
            cout << "Para obtener ayuda sobre un comando especifico, ingrese 'ayuda <comando>'." << endl;
        }
    }

    return 0;
}

