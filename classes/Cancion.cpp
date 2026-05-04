//
// Created by chapuza on 03-05-2026.
//

#include "Cancion.h"
using namespace std;
#include <iostream>
#include <ostream>
#include <string>

Cancion::Cancion(string id, string nombre, string artista, string album,
                 string anio, int duracion, string ruta) {
    this->id = id;
    this->nombre = nombre;
    this->artista = artista;
    this->album = album;
    this->anio = anio;
    this->duracion = duracion;
    this->ruta = ruta;
    this->siguiente = nullptr;
}

string Cancion::getId() {
    return this->id;
}

string Cancion::getNombre() {
    return this->nombre;
}

string Cancion::getArtista() {
    return this->artista;
}

string Cancion::getAlbum() {
    return this->album;
}

string Cancion::getAnio() {   // ← NUEVO
    return this->anio;
}

int Cancion::getDuracion() {  // ← NUEVO
    return this->duracion;
}

void Cancion::print() {
    cout << "ID:" << this->id << "| ";
    cout << "Nombre:" << this->nombre << "| ";
    cout << "Artista:" << this->artista << "| ";
    cout << "Album:" << this->album << "| ";
    cout << "Año:" << this->anio << "| ";
    cout << "Duracion:" << this->duracion << "| ";
    cout << "Ruta:" << this->ruta << endl;
}

void Cancion::Agregarsiguiente(Cancion* siguiente) {
    this->siguiente = siguiente;
}

Cancion* Cancion::getSiguiente() {
    return this->siguiente;
}

void Cancion::setSiguiente(Cancion* cancion) {
    this->siguiente = cancion;
}

Cancion::~Cancion() {

}
