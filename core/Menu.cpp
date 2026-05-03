void menu() {
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
}
