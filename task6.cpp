﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definirea claselor existente
class Student {
public:
    int varsta;
    string nume;
    int nrCredite;
    const string programStudiu;
    char* email;
    static int maxCredite;

    Student(string nume, int varsta, int nrCredite, string program, const char* email)
        : programStudiu(program) {
        this->nume = nume;
        this->varsta = varsta;
        this->nrCredite = nrCredite;
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }

    ~Student() {
        delete[] email;
    }

    void afisare() const {
        cout << "Student: " << nume << ", Varsta: " << varsta << ", Credite: " << nrCredite << ", Program: " << programStudiu << endl;
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

    Profesor(string nume, int varsta, double salariu, string departament, const char* email)
        : departament(departament) {
        this->nume = nume;
        this->varsta = varsta;
        this->salariu = salariu;
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }

    ~Profesor() {
        delete[] email;
    }

    void afisare() const {
        cout << "Profesor: " << nume << ", Varsta: " << varsta << ", Salariu: " << salariu << ", Departament: " << departament << endl;
    }
};

double Profesor::salariuMaxim = 15000;

class Curs {
public:
    string nume;
    int nrOre;
    const string nivel;
    char* profesorTitular;
    static int durataMaximaCurs;

    Curs(string nume, int nrOre, string nivel, const char* profesorTitular) : nivel(nivel) {
        this->nume = nume;
        this->nrOre = nrOre;
        this->profesorTitular = new char[strlen(profesorTitular) + 1];
        strcpy(this->profesorTitular, profesorTitular);
    }

    ~Curs() {
        delete[] profesorTitular;
    }

    void afisare() const {
        cout << "Curs: " << nume << ", Nr ore: " << nrOre << ", Nivel: " << nivel << ", Profesor titular: " << profesorTitular << endl;
    }
};

int Curs::durataMaximaCurs = 180;

// Noua clasă: Facultate
class Facultate {
private:
    string numeFacultate;
    Profesor decan;
    vector<Student> studenti;
    vector<Curs> cursuri;
    int nrMaxStudenti;

public:
    
    Facultate(string numeFacultate, Profesor decan, int nrMaxStudenti)
        : decan(decan), numeFacultate(numeFacultate), nrMaxStudenti(nrMaxStudenti) {}

    
    void adaugaStudent(const Student& student) {
        if (studenti.size() < nrMaxStudenti) {
            studenti.push_back(student);
        }
        else {
            cout << "Nu mai sunt locuri disponibile pentru studenti" << endl;
        }
    }

    
    void adaugaCurs(Curs& curs) {
        cursuri.push_back(curs);
    }

    
    Profesor getDecan() {
        return decan;
    }

    
    void setDecan( Profesor decan) {
        this->decan = decan;
    }


  
    void afisare()  {
        cout << "Facultate: " << numeFacultate << endl;
        cout << "Decan: " << endl;
        decan.afisare();
        cout << "Lista studenti:" << endl;
        for (size_t i = 0; i < studenti.size(); i++) {
            studenti[i].afisare();
        }
        cout << "Lista cursuri:" << endl;
        for (size_t i = 0; i < cursuri.size(); i++) {
            cursuri[i].afisare();
        }
    }


    // Operatorul += pentru adăugarea unui student
    Facultate& operator+=( Student& student) {
        adaugaStudent(student);
        return *this;
    }

    // Operatorul -= pentru eliminarea unui student (după nume)
    Facultate& operator-=( string& numeStudent) {
        for (auto it = studenti.begin(); it != studenti.end(); ++it) {
            if (it->nume == numeStudent) {
                studenti.erase(it);
                break;
            }
        }
        return *this;
    }

    // Operatorul << pentru afișare
    friend ostream& operator<<(ostream& os, const Facultate& facultate) {
        os << "Facultate: " << facultate.numeFacultate << endl;
        os << "Decan: " << facultate.decan.nume << endl;
        os << "Nr. max. studenti: " << facultate.nrMaxStudenti << endl;
        return os;
    }
};


int main() {
   
    Profesor decan("Popescu Ion", 50, 12000, "Informatica", "popescu.ion@univ.ro");
    Student s1("Maria Ionescu", 20, 30, "Informatica", "maria.ionescu@student.univ.ro");
    Student s2("Andrei Vasile", 21, 25, "Informatica", "andrei.vasile@student.univ.ro");
    Curs c1("Programare C++", 60, "Licenta", "Popescu Ion");
    Curs c2("Structuri de Date", 45, "Licenta", "Ionescu Alina");

    
    Facultate facultate("Facultatea de Informatica", decan, 100);

    // Adăugare studenți și cursuri
    facultate += s1;
    facultate += s2;
    facultate.adaugaCurs(c1);
    facultate.adaugaCurs(c2);

    facultate.afisare();

    return 0;
}
