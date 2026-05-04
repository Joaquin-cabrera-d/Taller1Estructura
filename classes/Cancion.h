//
// Created by chapuza on 03-05-2026.
//

#pragma once
#include <string>

using namespace std;

class Cancion {
private:
    string id;
    string nombre;
    string artista;
    string album;
    string anio;
    int duracion;
    string ruta;
    Cancion* siguiente;

public:
    // constructor
    Cancion(string id, string nombre, string artista, string album,
            string anio, int duracion, string ruta);

    // getters
    string getId();
    string getNombre();
    string getArtista();
    string getAlbum();
    string getAnio();  // ← AGREGADO
    int getDuracion(); // ← AGREGADO (útil para después)

    // setters
    void setSiguiente(Cancion* cancion);
    void Agregarsiguiente(Cancion* siguiente);

    // otros
    void print();
    Cancion* getSiguiente();

    // destructor
    ~Cancion();
};
