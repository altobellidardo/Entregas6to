#include <iostream>
#include <string>
using namespace std;

#define MAX_CONTACTOS 10

class Contacto {
public:
  Contacto();
  Contacto(string nombre, int telefono, string correo);
  void mostrarInfo();

private:
  string nombre;
  int telefono;
  string correo;
};

Contacto::Contacto(string nombre, int telefono, string correo) {
  this->nombre = nombre;
  this->telefono = telefono;
  this->correo = correo + "@gmail.com";
}
Contacto::Contacto(){}
void Contacto::mostrarInfo() {
  cout << "Nombre: " << nombre << endl;
  cout << "Telefono: " << telefono << endl;
  cout << "Correo: " << correo << endl;
}

int main() {
  Contacto **lista_contactos = new Contacto *[MAX_CONTACTOS];

  int num_contactos = 0;

  while (true) {
    cout << "\nOpciones:" << endl;
    cout << "1. Agregar contacto" << endl;
    cout << "2. Mostrar contactos" << endl;
    cout << "3. Salir" << endl;

    int opcion;
    cout << "Tu opción: ";
    cin >> opcion;

    if (opcion == 1) {
      if (num_contactos < MAX_CONTACTOS) {
        string nombre, correo;
        int telefono;

        cout << "Nombre: ";
        cin >> nombre;
        cout << "Telefono: ";
        cin >> telefono;
        cout << "Correo: ";
        cin >> correo;

        Contacto *nuevo_contacto = new Contacto(nombre, telefono, correo);
        lista_contactos[num_contactos] = nuevo_contacto;
        num_contactos++;

        cout << "Contacto agregado correctamente." << endl;
      } else {
        cout << "La lista de contactos está llena." << endl;
      }
    }

    else if (opcion == 2) {
      if (num_contactos == 0) {
        cout << "La lista de contactos está vacía." << endl;
      } else {
        cout << "\nLista de contactos:" << endl;
        for (int i = 0; i < num_contactos; i++) {
          lista_contactos[i]->mostrarInfo();
          cout << "------------------------" << endl;
        }
      }
    }

    else if (opcion == 3) {
      for (int i = 0; i < num_contactos; i++) {
        delete lista_contactos[i];
      }
      delete[] lista_contactos;
      break;
    }

    else {
      cout << "Opción no válida." << endl;
    }
  }

  return 0;
}
