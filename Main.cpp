#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include "classes/Cancion.h"
#include "classes/Lista.h"
using namespace std;

void menu() {cout << R"(

                   REPRODUCTOR DE MuSICA

 W - Reproducir/Pausar
 Q - Pista Anterior
 E - Pista Siguiente
 S - Activar/Desactivar modo aleatorio
 R - Repeticion (Desactivado/Repetir una/Repetir todas)
 A - Ver lista de reproduccion actual
 L - Listado de canciones
 X - Salir

 Ingrese Opcion:
)";

}

int main() {

    ifstream file("C:/Users/chapuza/OneDrive/Documents/UCN/Estructura/untitled/Canciones.txt");


    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo de canciones" << endl;
        cout << "Verifica que el archivo exista en la ruta correcta" << endl;
        return 1;
    }

    Lista lista;
    string linea;

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string id, nombre, artista, album, anio, duracionStr, ruta;

        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, artista, ',');
        getline(ss, album, ',');
        getline(ss, anio, ',');
        getline(ss, duracionStr, ',');
        getline(ss, ruta, ',');

        int duracion = 0;
        try {
            duracion = stoi(duracionStr);
        } catch (...) {
            duracion = 0;
        }

        Cancion* cancion = new Cancion(id, nombre, artista, album, anio, duracion, ruta);
        lista.Agregar(cancion);
    }
    file.close();

    if (lista.Vacia()) {
        cout << "No hay canciones para reproducir" << endl;
        return 1;
    }


    lista.reproducirPausar();

    char opcion;
    do {
        lista.mostrarEstadoActual();
        menu();
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'W':
                lista.reproducirPausar();
                break;

            case 'Q':
                lista.anterior();
                break;

            case 'E':
                lista.siguiente();
                break;

            case 'S':
                lista.toggleAleatorio();
                break;

            case 'R':
                lista.toggleRepeticion();
                break;

            case 'A':
                lista.mostrarListaReproduccion();
                break;

            case 'L':
                lista.mostrarTodasCanciones();
                break;

            case 'X':
                cout << "\n Saliendo del reproductor..." << endl;
                break;

            default:
                cout << "\n Opción no válida. Intente nuevamente." << endl;
                break;
        }

        if (opcion != 'X') {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }



    } while (opcion != 'X');

    return 0;
}
