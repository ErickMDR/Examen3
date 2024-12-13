#include "pets.h"

void Pets::create() {
    ofstream file("pets.csv", ios::app);

    string id, nombre_mascota, tipo_animal, fecha_ingreso, sexo;
    cout << "Ingrese los datos: " << endl;
    cout << "ID: ";
    cin >> id;
    cout << "Ingrese Nombre de Mascota: ";
    cin >> nombre_mascota;
    cout << "Ingrese Tipo de Animal: ";
    cin >> tipo_animal;
    cout << "Ingrese Fecha de Ingreso (dd/mm/yyyy): ";
    cin >> fecha_ingreso;
    cout << "Ingrese Sexo (M/H): ";
    cin >> sexo;

    file << id << "," << nombre_mascota << "," << tipo_animal << "," << fecha_ingreso << "," << sexo << endl;
    file.close();
    cout << "Registro agregado exitosamente." << endl;
}

void Pets::read() {
    ifstream file("pets.csv");

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

void Pets::update() {
    ifstream file("pets.csv");
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
            string nombre_mascota, tipo_animal, fecha_ingreso, sexo;
            cout << "Ingrese los nuevos datos: " << endl;
            cout << "Nombre de Mascota: ";
            cin >> nombre_mascota;
            cout << "Tipo de Animal: ";
            cin >> tipo_animal;
            cout << "Fecha de Ingreso (dd/mm/yyyy): ";
            cin >> fecha_ingreso;
            cout << "Sexo (M/H): ";
            cin >> sexo;
            tempFile << targetId << "," << nombre_mascota << "," << tipo_animal << "," << fecha_ingreso << "," << sexo << endl;
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

    remove("pets.csv");
    rename("temp.csv", "pets.csv");
    cout << "Registro actualizado exitosamente." << endl;
}

void Pets::deletePet() {
    ifstream file("pets.csv");
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

    remove("pets.csv");
    rename("temp.csv", "pets.csv");
    cout << "Registro eliminado exitosamente." << endl;
}
