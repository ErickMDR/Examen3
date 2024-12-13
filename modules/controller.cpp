#include "controller.h"
#include <iostream>

using namespace std;

void Controller::ManejoOwners() {
    Owners owners;
    int opcion;

    do {
        cout << endl;
        cout << "Operaciones en Owners:" << endl;
        cout << "1. Crear" << endl;
        cout << "2. Leer" << endl;
        cout << "3. Actualizar" << endl;
        cout << "4. Eliminar" << endl;
        cout << "5. Regresar" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                owners.create();
                break;
            case 2:
                owners.read();
                break;
            case 3:
                owners.update();
                break;
            case 4:
                owners.deleteOwner();
                break;
            case 5:
                cout << "Saliendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}

void Controller::ManejoPets() {
    Pets pets;
    int opcion;

    do {
        cout << endl;
        cout << "Operaciones en Pets:" << endl;
        cout << "1. Crear" << endl;
        cout << "2. Leer" << endl;
        cout << "3. Actualizar" << endl;
        cout << "4. Eliminar" << endl;
        cout << "5. Regresar" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pets.create();
                break;
            case 2:
                pets.read();
                break;
            case 3:
                pets.update();
                break;
            case 4:
                pets.deletePet();
                break;
            case 5:
                cout << "Saliendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
}