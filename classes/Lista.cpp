//
// Created by chapuza on 03-05-2026.
//

#include "Lista.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Lista::Lista() {
    principio = nullptr;
    cursor = nullptr;
    cancionActual = nullptr;
    reproduciendo = false;
    modoAleatorio = false;
    modoRepeticion = 0;
    totalCanciones = 0;
    srand(time(nullptr));
}

Lista::~Lista() {
    Cancion* actual = principio;
    while (actual != nullptr) {
        Cancion* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

bool Lista::Vacia() {
    return principio == nullptr;
}

void Lista::Agregar(Cancion* cancion) {
    if (Vacia()) {
        principio = cancion;
    } else {
        cursor = principio;
        while (cursor->getSiguiente() != nullptr) {
            cursor = cursor->getSiguiente();
        }
        cursor->setSiguiente(cancion);
    }
    totalCanciones++;

    // Si es la primera canción, que sea la actual
    if (cancionActual == nullptr) {
        cancionActual = principio;
    }
}

void Lista::Print() {
    if (Vacia()) {
        cout << "No hay canciones en la lista" << endl;
        return;
    }

    cursor = principio;
    int contador = 1;
    while (cursor != nullptr) {
        cout << contador << ". ";
        cursor->print();
        cursor = cursor->getSiguiente();
        contador++;
    }
}

void Lista::mostrarEstadoActual() {
    if (cancionActual == nullptr) {
        cout << "\nReproducción Detenida" << endl;
        return;
    }

    string estado = reproduciendo ? "Reproduciendo" : "En pausa";
    string indicador = "";

    if (modoAleatorio && modoRepeticion == 1) indicador = " (S-R1)";
    else if (modoAleatorio && modoRepeticion == 2) indicador = " (S-RA)";
    else if (modoAleatorio) indicador = " (S)";
    else if (modoRepeticion == 1) indicador = " (R1)";
    else if (modoRepeticion == 2) indicador = " (RA)";

    cout << "\n" << estado << indicador << ": "
         << cancionActual->getNombre()
         << " Artista: " << cancionActual->getArtista()
         << " Album: " << cancionActual->getAlbum()
         << " [" << cancionActual->getAnio() << "]" << endl;
}

void Lista::reproducirPausar() {
    if (cancionActual == nullptr) {
        if (principio != nullptr) {
            cancionActual = principio;
            reproduciendo = true;
            cout << "\n Reproduciendo: " << cancionActual->getNombre() << endl;
        } else {
            cout << "\n No hay canciones para reproducir" << endl;
        }
    } else {
        reproduciendo = !reproduciendo;
        if (reproduciendo) {
            cout << "\n Reproduciendo: " << cancionActual->getNombre() << endl;
        } else {
            cout << "\n En pausa: " << cancionActual->getNombre() << endl;
        }
    }
}

void Lista::siguiente() {
    if (cancionActual == nullptr) {
        reproducirPausar();
        return;
    }

    // Modo repetición una
    if (modoRepeticion == 1) {
        cout << "\n⏭ (Repitiendo): " << cancionActual->getNombre() << endl;
        reproduciendo = true;
        return;
    }

    Cancion* siguienteCancion = cancionActual->getSiguiente();

    // Si no hay siguiente
    if (siguienteCancion == nullptr) {
        if (modoRepeticion == 2) {
            // Repetir todas: volver al principio
            siguienteCancion = principio;
            cout << "\n⏭ (Repitiendo lista): " << siguienteCancion->getNombre() << endl;
        } else {
            cout << "\n⏹ Fin de la lista de reproducción" << endl;
            reproduciendo = false;
            return;
        }
    }

    cancionActual = siguienteCancion;
    reproduciendo = true;
    cout << "\n⏭ Reproduciendo: " << cancionActual->getNombre() << endl;
}

void Lista::anterior() {
    if (cancionActual == nullptr) {
        cout << "\n⏮ No hay canción actual" << endl;
        return;
    }

    if (cancionActual == principio) {
        cout << "\n⏮ No hay canción anterior" << endl;
        return;
    }

    // Modo repetición una
    if (modoRepeticion == 1) {
        cout << "\n⏮ (Repitiendo): " << cancionActual->getNombre() << endl;
        reproduciendo = true;
        return;
    }

    // Buscar canción anterior
    Cancion* anterior = principio;
    while (anterior != nullptr && anterior->getSiguiente() != cancionActual) {
        anterior = anterior->getSiguiente();
    }

    if (anterior != nullptr) {
        cancionActual = anterior;
        reproduciendo = true;
        cout << "\n⏮ Reproduciendo: " << cancionActual->getNombre() << endl;
    }
}

void Lista::toggleAleatorio() {
    modoAleatorio = !modoAleatorio;

    if (modoAleatorio) {
        cout << "\n Modo aleatorio ACTIVADO" << endl;
        mezclarLista();
    } else {
        cout << "\n Modo aleatorio DESACTIVADO" << endl;
    }
}

void Lista::mezclarLista() {
    if (totalCanciones <= 1) return;

    // Crear array temporal con punteros a canciones
    Cancion** arreglo = new Cancion*[totalCanciones];
    Cancion* actual = principio;
    for (int i = 0; i < totalCanciones; i++) {
        arreglo[i] = actual;
        actual = actual->getSiguiente();
    }

    // Algoritmo Fisher-Yates para mezclar
    for (int i = totalCanciones - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Cancion* temp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = temp;
    }

    // Reconstruir la lista
    principio = arreglo[0];
    for (int i = 0; i < totalCanciones - 1; i++) {
        arreglo[i]->setSiguiente(arreglo[i + 1]);
    }
    arreglo[totalCanciones - 1]->setSiguiente(nullptr);

    delete[] arreglo;
    cout << "✓ Lista de reproducción mezclada" << endl;
}

void Lista::toggleRepeticion() {
    modoRepeticion = (modoRepeticion + 1) % 3;

    switch(modoRepeticion) {
        case 0:
            cout << "\n Repetición: DESACTIVADA" << endl;
            break;
        case 1:
            cout << "\n Repetición: REPETIR UNA" << endl;
            break;
        case 2:
            cout << "\n Repetición: REPETIR TODAS" << endl;
            break;
    }
}

void Lista::mostrarListaReproduccion() {
    cout << "\n=== LISTA DE REPRODUCCIÓN ACTUAL ===" << endl;

    if (cancionActual != nullptr) {
        cout << "Actual: " << cancionActual->getNombre()
             << " - " << cancionActual->getArtista() << endl;
    } else {
        cout << "Actual: (ninguna)" << endl;
    }

    cout << "\nPróximas canciones:" << endl;

    if (cancionActual == nullptr || cancionActual->getSiguiente() == nullptr) {
        cout << "  [Vacía]" << endl;
    } else {
        Cancion* actual = cancionActual->getSiguiente();
        int contador = 1;
        while (actual != nullptr) {
            cout << "  " << contador << ". " << actual->getNombre()
                 << " - " << actual->getArtista() << endl;
            actual = actual->getSiguiente();
            contador++;
        }
    }
}

void Lista::mostrarTodasCanciones() {
    cout << "\n=== LISTADO DE CANCIONES ===" << endl;
    Print();
}

void Lista::saltarACancion(int posicion) {
    if (posicion < 1 || posicion > totalCanciones) {
        cout << "\n Posición inválida" << endl;
        return;
    }
    
    Cancion* destino = principio;
    for (int i = 1; i < posicion; i++) {
        destino = destino->getSiguiente();
    }
    
    cancionActual = destino;
    reproduciendo = true;
    cout << "\n Saltando a: " << cancionActual->getNombre() << endl;
}
