#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Persoana {
public:
    virtual void afisareInfo() const = 0; // Metodă virtuală pură
    virtual ~Persoana() {}                // Destructor virtual
};

class EntitateEducativa : public Persoana {
public:
    virtual ~EntitateEducativa() {}       // Destructor virtual
};

class Student : public EntitateEducativa {
public:
    int varsta;
    string nume;
    int nrCredite;
    const string programStudiu;
    char* email;
    static int maxCredite;

    Student() : programStudiu("Informatica") {
        this->varsta = 20;
        this->nume = "Popescu Andrei";
        this->nrCredite = 30;
        this->email = nullptr;
    }

    Student(string nume, int varsta, int nrCredite, string program)
        : programStudiu(program) {
        this->varsta = varsta;
        this->nume = nume;
        this->nrCredite = nrCredite;
        this->email = new char[strlen("popescu_andrei@yahoo.com") + 1];
        strcpy_s(this->email, strlen("popescu_andrei@yahoo.com") + 1, "popescu_andrei@yahoo.com");
    }

    ~Student() {
        delete[] email;
    }

    void afisareInfo() const override {
        cout << "Student: " << nume << ", Varsta: " << varsta
            << ", Credite: " << nrCredite
            << ", Program studiu: " << programStudiu
            << ", Email: " << (email ? email : "N/A") << endl;
    }
};

int Student::maxCredite = 60;

class Profesor : public EntitateEducativa {
public:
    string nume;
    int varsta;
    double salariu;
    const string departament;
    char* email;

    Profesor() : departament("Matematica") {
        nume = "Ionescu Maria";
        varsta = 45;
        salariu = 4000;
        email = nullptr;
    }

    Profesor(string nume, int varsta, double salariu, string departament)
        : departament(departament) {
        this->nume = nume;
        this->varsta = varsta;
        this->salariu = salariu;
        this->email = new char[strlen("maria.ionescu@example.com") + 1];
        strcpy_s(this->email, strlen("maria.ionescu@example.com") + 1, "maria.ionescu@example.com");
    }

    ~Profesor() {
        delete[] email;
    }

    void afisareInfo() const override {
        cout << "Profesor: " << nume << ", Varsta: " << varsta
            << ", Salariu: " << salariu
            << ", Departament: " << departament
            << ", Email: " << (email ? email : "N/A") << endl;
    }
};

class Curs : public EntitateEducativa {
public:
    string nume;
    int nrOre;
    const string nivel;
    char* profesorTitular;

    Curs() : nivel("Licenta") {
        this->nume = "Programare C++";
        this->nrOre = 30;
        this->profesorTitular = nullptr;
    }

    Curs(string nume, int nrOre, string nivel)
        : nivel(nivel) {
        this->nume = nume;
        this->nrOre = nrOre;
        this->profesorTitular = new char[strlen("Popescu Ion") + 1];
        strcpy_s(this->profesorTitular, strlen("Popescu Ion") + 1, "Popescu Ion");
    }

    ~Curs() {
        delete[] profesorTitular;
    }

    void afisareInfo() const override {
        cout << "Curs: " << nume << ", Nr. ore: " << nrOre
            << ", Nivel: " << nivel
            << ", Profesor titular: " << (profesorTitular ? profesorTitular : "N/A") << endl;
    }
};

int main() {
    vector<EntitateEducativa*> persoane;

    persoane.push_back(new Student("Ion Popescu", 20, 30, "Informatica"));
    persoane.push_back(new Profesor("Maria Ionescu", 45, 4000, "Matematica"));
    persoane.push_back(new Curs("Programare C++", 40, "Licenta"));

    for (auto persoana : persoane) {
        persoana->afisareInfo(); // Late binding
    }

    for (auto persoana : persoane) {
        delete persoana;
    }

    return 0;
}
