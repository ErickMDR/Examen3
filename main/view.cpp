#include "view.h"

void View::run() {
    Controller controller;
    int opcion;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Operaciones en Owners\n";
        cout << "2. Operaciones en Pets\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                controller.ManejoOwners();
                break;
            case 2:
                controller.ManejoPets();
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}