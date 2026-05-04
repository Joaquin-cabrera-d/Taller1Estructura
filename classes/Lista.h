//
// Created by chapuza on 03-05-2026.
//

#pragma once
#include "Cancion.h"

class Lista {
private:
    Cancion* principio;
    Cancion* cursor;
    Cancion* cancionActual;
    bool reproduciendo;
    bool modoAleatorio;
    int modoRepeticion;
    int totalCanciones;

public:
    Lista();
    ~Lista();

    bool Vacia();
    void Agregar(Cancion* cancion);
    void Print();

    // Control de reproducción
    void reproducirPausar();
    void siguiente();
    Cancion* obtenerActual();
    void anterior();
    void saltarACancion(int posicion);

    // Modos especiales
    void toggleAleatorio();
    void toggleRepeticion();
    void mezclarLista();

    // Mostrar información
    void mostrarEstadoActual();
    void mostrarListaReproduccion();
    void mostrarTodasCanciones();

    // Getter
    Cancion* getCancionActual() { return cancionActual; }
};
