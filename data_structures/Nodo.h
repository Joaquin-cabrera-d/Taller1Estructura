#pragma once

struct Nodo {
    string id;
    string nombre;
    string artista;
    string album;
    int fechaSalida;
    int duracionSegundos;
    string ubicacion;
    Nodo* next;

    Nodo(string ID, string Nombre, string Artista, string Album, int FechaSalida, int DuracionSegundos, string Ubicacion) : id(ID), nombre(Nombre), artista(Artista), album(Album), fechaSalida(FechaSalida), duracionSegundos(DuracionSegundos), ubicacion(Ubicacion), next(nullptr) {}
};
