#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Student {
public:
    int varsta;
    string nume;
    int nrCredite;
    const string programStudiu;
    char* email;
    static int maxCredite;

    // Constructor fără parametri
    Student() : programStudiu("Informatica") {
        this->varsta = 20;
        this->nume = "Popescu Andrei";
        this->nrCredite = 30;
        this->email = nullptr;
    }

    // Constructor cu parametri
    Student(string nume, int varsta, int nrCredite, string program)
        : programStudiu(program) {
        this->varsta = varsta;
        this->nume = nume;
        this->nrCredite = nrCredite;
        this->email = new char[strlen("popescu_andrei@yahoo.com") + 1];
        strcpy_s(this->email, strlen("popescu_andrei@yahoo.com") + 1, "popescu_andrei@yahoo.com");
    }

    // Constructor de copiere
    Student(const Student& s) : programStudiu(s.programStudiu) {
        this->varsta = s.varsta;
        this->nume = s.nume;
        this->nrCredite = s.nrCredite;
        if (s.email) {
            this->email = new char[strlen(s.email) + 1];
            strcpy_s(this->email, strlen(s.email) + 1, s.email);
        }
        else {
            this->email = nullptr;
        }
    }

    ~Student() {
        delete[] email;
    }

    static int getMaxCredite() {
        return maxCredite;
    }

    void afisare() {
        cout << "Nume: " << nume << ", Varsta: " << varsta
            << ", Credite: " << nrCredite
            << ", Program studiu: " << programStudiu
            << ", Email: " << (email ? email : "N/A") << endl;
    }
};

int Student::maxCredite = 60;

class Profesor {
public:
    string nume;
    int varsta;
    double salariu;
    const string departament;
    char* email;
    static double salariuMaxim;

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
        strcpy_s(this->email, strlen("maria.ionescu@example.com") + 1, "maria.ionescu@example.com");
    }

    // Constructor de copiere
    Profesor(const Profesor& p) : departament(p.departament) {
        this->nume = p.nume;
        this->varsta = p.varsta;
        this->salariu = p.salariu;
        if (p.email) {
            this->email = new char[strlen(p.email) + 1];
            strcpy_s(this->email, strlen(p.email) + 1, p.email);
        }
        else {
            this->email = nullptr;
        }
    }

    ~Profesor() {
        delete[] email;
    }

    static double getMaxSalariu() {
        return salariuMaxim;
    }

    void afisare() {
        cout << "Nume: " << nume << ", Varsta: " << varsta
            << ", Salariu: " << salariu
            << ", Departament: " << departament
            << ", Email: " << (email ? email : "N/A") << endl;
    }
};

double Profesor::salariuMaxim = 10000.0;

class Curs {
public:
    string nume;
    int nrOre;
    const string nivel;
    char* profesorTitular;
    static int durataMaximaCurs;

    // Constructor fără parametri
    Curs() : nivel("Licenta") {
        this->nume = "Programare C++";
        this->nrOre = 30;
        this->profesorTitular = nullptr;
    }

    // Constructor cu parametri
    Curs(string nume, int nrOre, string nivel)
        : nivel(nivel) {
        this->nume = nume;
        this->nrOre = nrOre;
        this->profesorTitular = new char[strlen("Popescu Ion") + 1];
        strcpy_s(this->profesorTitular, strlen("Popescu Ion") + 1, "Popescu Ion");
    }

    // Constructor de copiere
    Curs(const Curs& c) : nivel(c.nivel) {
        this->nume = c.nume;
        this->nrOre = c.nrOre;
        if (c.profesorTitular) {
            this->profesorTitular = new char[strlen(c.profesorTitular) + 1];
            strcpy_s(this->profesorTitular, strlen(c.profesorTitular) + 1, c.profesorTitular);
        }
        else {
            this->profesorTitular = nullptr;
        }
    }

    ~Curs() {
        delete[] profesorTitular;
    }

    static int getMaxDurataCurs() {
        return durataMaximaCurs;
    }

    void afisare() {
        cout << "Nume curs: " << nume << ", Nr. ore: " << nrOre
            << ", Nivel: " << nivel
            << ", Profesor titular: " << (profesorTitular ? profesorTitular : "N/A") << endl;
    }
};

int Curs::durataMaximaCurs = 60;

int main() {
    cout << "Testare clase cu constructori fara parametri:" << endl;
    Student s1;
    s1.afisare();
    Profesor p1;
    p1.afisare();
    Curs c1;
    c1.afisare();

    cout << "\nTestare clase cu constructori cu parametri:" << endl;
    Student s2("Maria Popescu", 22, 40, "Informatica Aplicata");
    s2.afisare();
    Profesor p2("Dumitru Vasile", 50, 7000.0, "Fizica");
    p2.afisare();
    Curs c2("Algoritmi", 40, "Licenta");
    c2.afisare();

    cout << "\nTestare clase cu constructori de copiere:" << endl;
    Student s3 = s2;
    s3.afisare();
    Profesor p3 = p2;
    p3.afisare();
    Curs c3 = c2;
    c3.afisare();

    cout << "\nFunctii statice:" << endl;
    cout << "Max credite student: " << Student::getMaxCredite() << endl;
    cout << "Max salariu profesor: " << Profesor::getMaxSalariu() << endl;
    cout << "Max durata curs: " << Curs::getMaxDurataCurs() << endl;

    return 0;
}
