#include "view.h"

void View::run() {
    Controller controller;
    int opcion;

    do {
        cout << endl;
        cout << "Menu Principal:" << endl;
        cout << "1. Operaciones en Owners" << endl;
        cout << "2. Operaciones en Pets" << endl;
        cout << "3. Salir" << endl;
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
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
}