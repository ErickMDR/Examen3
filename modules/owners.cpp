#include "owners.h"

void Owners::create() {
    fstream file("owners.csv", ios::app);

    string id, nombre, apellido, correo, nombre_mascota, tipo_animal;
    cout << "Ingrese los datos: " << endl;
    cout << "ID: ";
    cin >> id;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;
    cout << "Correo: ";
    cin >> correo;
    cout << "Nombre de Mascota: ";
    cin >> nombre_mascota;
    cout << "Tipo de Animal: ";
    cin >> tipo_animal;

    file << id << "," << nombre << "," << apellido << "," << correo << "," << nombre_mascota << "," << tipo_animal << endl;
    file.close();
    cout << "Registro agregado exitosamente." << endl;
}

void Owners::read() {
    ifstream file("owners.csv");

    string targetId;
    cout << "Ingrese el ID del registro a leer: ";
    cin >> targetId;

    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        if (line.substr(0, pos) == targetId) {
            found = true;
            cout << "Registro encontrado: " << line << endl;
            break;
        }
    }

    if (!found) {
        cout << "Registro no encontrado." << endl;
    }

    file.close();
}

void Owners::update() {
    ifstream file("owners.csv");
    ofstream tempFile("temp.csv");

    string id, targetId;
    cout << "Ingrese el ID del registro a actualizar: ";
    cin >> targetId;

    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        if (line.substr(0, pos) == targetId) {
            found = true;
            string nombre, apellido, correo, nombre_mascota, tipo_animal;
            cout << "Ingrese los nuevos datos: " << endl;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Apellido: ";
            cin >> apellido;
            cout << "Correo: ";
            cin >> correo;
            cout << "Nombre de Mascota: ";
            cin >> nombre_mascota;
            cout << "Tipo de Animal: ";
            cin >> tipo_animal;
            tempFile << targetId << "," << nombre << "," << apellido << "," << correo << "," << nombre_mascota << "," << tipo_animal << endl;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    if (!found) {
        cout << "Registro no encontrado." << endl;
        remove("temp.csv");
        return;
    }

    remove("owners.csv");
    rename("temp.csv", "owners.csv");
    cout << "Registro actualizado exitosamente." << endl;
}

void Owners::deleteOwner() {
    ifstream file("owners.csv");
    ofstream tempFile("temp.csv");

    string id, targetId;
    cout << "Ingrese el ID del registro a eliminar: ";
    cin >> targetId;

    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        if (line.substr(0, pos) == targetId) {
            found = true;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    if (!found) {
        cout << "Registro no encontrado." << endl;
        remove("temp.csv");
        return;
    }

    remove("owners.csv");
    rename("temp.csv", "owners.csv");
    cout << "Registro eliminado exitosamente." << endl;
}