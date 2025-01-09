


#include <iostream>
#include <cstring>
using namespace std;

struct Bloc {
    int sector;
    char* strada;
    int nrscari;
    int etaje;
    int apartamente;
    int anulConstructiei;

   
    void afisare() {
        cout << "Blocul din sectorul " << sector
            << ", strada " << strada
            << ", are " << nrscari << " scari, "
            << etaje << " etaje "
            << "si un numar total de " << apartamente << " apartamente, "
            << "fiind construit in anul " << anulConstructiei << "."
            << endl;
    }
};

// Funcție pentru citirea unui bloc
Bloc citireBloc() {
    Bloc bl;
    cout << "strada: ";
    char buffer[100];
    cin >> buffer;
    bl.strada = new char[strlen(buffer) + 1];
    strcpy_s(bl.strada, strlen(buffer) + 1, buffer);
    cout << "sector: ";
    cin >> bl.sector;
    cout << "Numar scari: ";
    cin >> bl.nrscari;
    cout << "Numar etaje: ";
    cin >> bl.etaje;
    cout << "Numar apartamente: ";
    cin >> bl.apartamente;
    cout << "Anul constructiei: ";
    cin >> bl.anulConstructiei;
    return bl;
}

int main() {
    int nrBlocuri = 4;
    Bloc* vector = new Bloc[nrBlocuri];

    // Citirea informațiilor
    for (int i = 0; i < nrBlocuri; i++) {
        cout << "Citire date pentru blocul " << i + 1 << ":\n";
        vector[i] = citireBloc();
    }

    // Afișarea informațiilor
    cout << "\nVector de blocuri:\n";
    for (int i = 0; i < nrBlocuri; i++) {
        vector[i].afisare();
    }

    // Eliberarea memoriei
    for (int i = 0; i < nrBlocuri; i++) {
        delete[] vector[i].strada;
    }
    delete[] vector;

    return 0;
}
