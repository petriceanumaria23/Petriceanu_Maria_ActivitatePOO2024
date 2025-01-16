#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Student {
private:
    int varsta;
    string nume;
    int nrCredite;
    const string programStudiu;
    char* email;
    static int maxCredite;

public:
    // Constructor fără parametri
    Student() : programStudiu("Informatica") {
        varsta = 20;
        nume = "Popescu Andrei";
        nrCredite = 30;
        email = nullptr;
    }

    // Constructor cu parametri
    Student(string nume, int varsta, int nrCredite, string program)
        : programStudiu(program) {
        this->varsta = varsta;
        this->nume = nume;
        this->nrCredite = nrCredite;
        this->email = new char[strlen("popescu_andrei@yahoo.com") + 1];
        strcpy(this->email, "popescu_andrei@yahoo.com");
    }

    // Constructor de copiere
    Student(const Student& s) : programStudiu(s.programStudiu) {
        varsta = s.varsta;
        nume = s.nume;
        nrCredite = s.nrCredite;
        email = s.email ? new char[strlen(s.email) + 1] : nullptr;
        if (email) {
            strcpy(email, s.email);
        }
    }

    ~Student() {
        delete[] email;
    }

    int getVarsta() { return this->varsta; }

    void setVarsta(int varsta) { this->varsta = varsta; }

    string getNume() { return this->nume; }

    void setNume(string nume) { this->nume = nume; }

    int getNrCredite() { return this->nrCredite; }

    void setNrCredite(int nrCredite) { this->nrCredite = nrCredite; }

    string getProgramStudiu() { return this->programStudiu; }

    char* getEmail() { return this->email; }

    void setEmail(const char* email) {
        if (this->email) {
            delete[] this->email;
        }
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }

    static int getMaxCredite() { return maxCredite; }

    void afisare() const {
        cout << "Nume: " << nume << ", Varsta: " << varsta
            << ", Credite: " << nrCredite
            << ", Program studiu: " << programStudiu
            << ", Email: " << (email ? email : "N/A") << endl;
    }

    friend void proceseazaStudent(Student& s);
};

int Student::maxCredite = 60;

class Profesor {
private:
    string nume;
    int varsta;
    double salariu;
    const string departament;
    char* email;
    static double salariuMaxim;

public:
    // Constructor fără parametri
    Profesor() : departament("Matematica") {
        nume = "Ionescu Maria";
        varsta = 45;
        salariu = 4000;
        email = nullptr;
    }

    // Constructor cu parametri
    Profesor(string nume, int varsta, double salariu, string departament)
        : departament(departament) {
        this->nume = nume;
        this->varsta = varsta;
        this->salariu = salariu;
        this->email = new char[strlen("maria.ionescu@example.com") + 1];
        strcpy(this->email, "maria.ionescu@example.com");
    }

    // Constructor de copiere
    Profesor(const Profesor& p) : departament(p.departament) {
        nume = p.nume;
        varsta = p.varsta;
        salariu = p.salariu;
        email = p.email ? new char[strlen(p.email) + 1] : nullptr;
        if (email) {
            strcpy(email, p.email);
        }
    }

    ~Profesor() {
        delete[] email;
    }

    string getNume() { return this->nume; }

    void setNume(string nume) { this->nume = nume; }

    int getVarsta() { return this->varsta; }

    void setVarsta(int varsta) { this->varsta = varsta; }

    double getSalariu() { return this->salariu; }

    void setSalariu(double salariu) { this->salariu = salariu; }

    string getDepartament() { return this->departament; }

    char* getEmail() { return this->email; }

    void setEmail(const char* email) {
        if (this->email) {
            delete[] this->email;
        }
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }

    static double getSalariuMaxim() { return salariuMaxim; }

    void afisare() const {
        cout << "Nume: " << nume << ", Varsta: " << varsta
            << ", Salariu: " << salariu
            << ", Departament: " << departament
            << ", Email: " << (email ? email : "N/A") << endl;
    }

    friend void proceseazaProfesor(Profesor& p);
};

double Profesor::salariuMaxim = 10000.0;

// Funcții globale
void proceseazaStudent(Student& s) {
    s.setNrCredite(s.getNrCredite() + 10);
    cout << "Studentul " << s.getNume() << " a primit 10 credite în plus.\n";
}

void proceseazaProfesor(Profesor& p) {
    p.setSalariu(p.getSalariu() * 1.1);
    cout << "Profesorul " << p.getNume() << " a primit o mărire de 10%.\n";
}

int main() {
    Student s1;
    s1.afisare();
    proceseazaStudent(s1);
    s1.afisare();

    Profesor p1;
    p1.afisare();
    proceseazaProfesor(p1);
    p1.afisare();

    return 0;
}
