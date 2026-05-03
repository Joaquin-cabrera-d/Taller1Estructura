#include <iostream>
#include <string>
#include <cctype>

void menuPlaylist();
void menuListado();

void menuPlaylist(){
	string opcion;
	string input;
	cout << "Opciones:" << endl;
	cout << "S<num> - Saltar a la cancion seleccionada" << endl;
	cout << "V - Volver al menu principal" << endl;
}

void menuListado(){
	string opcion;
	string input;
	cout << "Opciones:" << endl;
	cout << "R<num> - Reproducir cancion seleccionada" << endl;
	cout << "A<num> - Agregar cancion seleccionada al final de la lista de reproduccion actual" << endl;
	cout << "N - Agregar cancion al registro de canciones" << endl;
	cout << "D<num> - Eliminar cancion seleccionada" << endl;
	cout << "V - Volver al menu principal" << endl;
	
}

int main() {
    char opcion;
    char input;
    do{
        cout << "Reproduciendo :   " << endl;
        cout << "Artista: " << endl;
        cout << "Album: " << endl;
        cout << "                      " << endl;
        cout << "                      " << endl;
        cout << "Opciones:" << endl;
        cout << "W - Reproducir/Pausar" << endl;
        cout << "Q - Pista Anterior" << endl;
        cout << "E - Pista Siguiente" << endl;
        cout << "S - Activar/Desactivar modo aleatorio" << endl;
        cout << "R - Repetición (Desactivado/Repetir una/Repetir todas)" << endl;
        cout << "A - Ver lista de reproducción actual" << endl;
        cout << "L - Listado de canciones" << endl;
        cout << "X - Salir" << endl;
        cout << "Ingrese Opción: ";
        getline(cin, input);
        try {
            opcion = stoi(input);
        } catch (...){
            opcion = 0;
        }
        opcion = std::tolower(opcion);
        switch(opcion){
            case 'w':

                break;
            case 'q' :

                break;
            case 'e' :

                break;
            case 's' :

                break;
            case 'r' :

                break;
            case 'a' :
				menuPlaylist();
                break;
			case 'l':
				menuListado();
				break;
            case 'x' :
                cout<<"Saliendo del programa"<<endl;
                break;
            default:
                cout << "Opcion no valida, intente de nuevo"<< endl;
        }
    } while(opcion != 'x');
    return 0;
}
