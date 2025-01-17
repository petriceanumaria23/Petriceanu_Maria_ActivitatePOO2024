#include <iostream>
#include <string>
#include <cstring>
#include <fstream> // Pentru lucrul cu fisiere
using namespace std;

class Student;
class Profesor;
class Curs;

class Student {
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

    Student(const Student& s) : programStudiu(s.programStudiu) {
        this->varsta = s.varsta;
        this->nume = s.nume;
        this->nrCredite = s.nrCredite;
        this->email = new char[strlen(s.email) + 1];
        strcpy_s(this->email, strlen(s.email) + 1, s.email);
    }

    Student& operator=(const Student& s) {
        if (this != &s) {
            delete[] this->email;
            this->varsta = s.varsta;
            this->nume = s.nume;
            this->nrCredite = s.nrCredite;

            if (s.email != nullptr) {
                this->email = new char[strlen(s.email) + 1];
                strcpy_s(this->email, strlen(s.email) + 1, s.email);
            }
            else {
                this->email = nullptr;
            }
        }
        return *this;
    }

    bool operator==(const Student& s) {
        return (this->nume == s.nume && this->varsta == s.varsta &&
            this->nrCredite == s.nrCredite);
    }

    Student& operator++() {
        this->varsta++;
        return *this;
    }

    Student operator+(const Student& s) {
        Student temp;
        temp.nrCredite = this->nrCredite + s.nrCredite;
        return temp;
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

    // Functii pentru fisiere text
    void scrieInFisierText(const string& numeFisier) {
        ofstream fisier(numeFisier, ios::app);
        if (fisier.is_open()) {
            fisier << nume << "," << varsta << "," << nrCredite << "," << programStudiu << "," << (email ? email : "N/A") << endl;
            fisier.close();
        }
        else {
            cerr << "Eroare la deschiderea fisierului!" << endl;
        }
    }

    void citesteDinFisierText(const string& numeFisier) {
        ifstream fisier(numeFisier);
        if (fisier.is_open()) {
            getline(fisier, nume, ',');
            fisier >> varsta;
            fisier.ignore();
            fisier >> nrCredite;
            fisier.ignore();
            string tempEmail;
            getline(fisier, tempEmail);

            delete[] email;
            email = new char[tempEmail.length() + 1];
            strcpy_s(email, tempEmail.length() + 1, tempEmail.c_str());
            fisier.close();
        }
        else {
            cerr << "Eroare la deschiderea fisierului!" << endl;
        }
    }

    friend void afiseazaVarstaStudent(const Student& s);
};

int Student::maxCredite = 60;

void afiseazaVarstaStudent(const Student& s) {
    cout << "Varsta studentului " << s.nume << " este: " << s.varsta << endl;
}

class Profesor {
public:
    string nume;
    int varsta;
    double salariu;
    const string departament;
    char* email;
    static double salariuMaxim;

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

    Profesor(const Profesor& p) : departament(p.departament) {
        this->nume = p.nume;
        this->varsta = p.varsta;
        this->salariu = p.salariu;
        this->email = new char[strlen(p.email) + 1];
        strcpy_s(this->email, strlen(p.email) + 1, p.email);
    }

    Profesor& operator=(const Profesor& p) {
        if (this == &p)
            return *this;
        delete[] this->email;
        this->nume = p.nume;
        this->varsta = p.varsta;
        this->salariu = p.salariu;

        if (p.email != nullptr) {
            this->email = new char[strlen(p.email) + 1];
            strcpy_s(this->email, strlen(p.email) + 1, p.email);
        }
        else {
            this->email = nullptr;
        }

        return *this;
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

    // Functii pentru fisiere text
    void scrieInFisierText( string& numeFisier) {
        ofstream fisier(numeFisier, ios::app);
        if (fisier.is_open()) {
            fisier << nume << "," << varsta << "," << salariu << "," << departament << "," << (email ? email : "N/A") << endl;
            fisier.close();
        }
        else {
            cerr << "Eroare la deschiderea fisierului!" << endl;
        }
    }

    void citesteDinFisierText( string& numeFisier) {
        ifstream fisier(numeFisier);
        if (fisier.is_open()) {
            getline(fisier, nume, ',');
            fisier >> varsta;
            fisier.ignore();
            fisier >> salariu;
            fisier.ignore();
            string tempEmail;
            getline(fisier, tempEmail);

            delete[] email;
            email = new char[tempEmail.length() + 1];
            strcpy_s(email, tempEmail.length() + 1, tempEmail.c_str());
            fisier.close();
        }
        else {
            cerr << "Eroare la deschiderea fisierului!" << endl;
        }
    }

    friend void afiseazaSalariuProfesor( Profesor& p);
};

double Profesor::salariuMaxim = 10000.0;

void afiseazaSalariuProfesor(Profesor& p) {
    cout << "Salariul profesorului " << p.nume << " este: " << p.salariu << endl;
}

// Clasa Curs - Metode pentru fisiere binare
class Curs {
public:
    string nume;
    int nrOre;
    const string nivel;
    char* profesorTitular;
    static int durataMaximaCurs;

    Curs() : nivel("Licenta") {
        this->nume = "Programare C++";
        this->nrOre = 30;
        this->profesorTitular = nullptr;
    }

    Curs(string nume, int nrOre, string nivel) : nivel(nivel) {
        this->nume = nume;
        this->nrOre = nrOre;
        this->profesorTitular = nullptr;
    }

    void afisare() {
        cout << "Nume curs: " << nume << ", Nr. ore: " << nrOre
            << ", Nivel: " << nivel
            << ", Profesor titular: " << (profesorTitular ? profesorTitular : "N/A") << endl;
    }


    void scrieInFisierBinar(string numeFisier) {
    ofstream fisier(numeFisier, ios::binary | ios::app);
    if (fisier.is_open()) {
        size_t lungime = nume.size();
        fisier.write((char*)&lungime, sizeof(lungime));
        fisier.write(nume.c_str(), lungime);
        fisier.write((char*)&nrOre, sizeof(nrOre));
        lungime = profesorTitular ? strlen(profesorTitular) : 0;
        fisier.write((char*)&lungime, sizeof(lungime));
        if (profesorTitular) {
            fisier.write(profesorTitular, lungime);
        }
        fisier.close();
    }
}

void citesteDinFisierBinar(string numeFisier) {
    ifstream fisier(numeFisier, ios::binary);
    if (fisier.is_open()) {
        size_t lungime;
        fisier.read((char*)&lungime, sizeof(lungime));
        char* buffer = new char[lungime + 1];
        fisier.read(buffer, lungime);
        buffer[lungime] = '\0';
        nume = buffer;
        delete[] buffer;

        fisier.read((char*)&nrOre, sizeof(nrOre));

        fisier.read((char*)&lungime, sizeof(lungime));
        delete[] profesorTitular;
        profesorTitular = new char[lungime + 1];
        fisier.read(profesorTitular, lungime);
        profesorTitular[lungime] = '\0';

        fisier.close();
    } else {
        cerr << "Eroare la deschiderea fisierului binar!" << endl;
    }
}

};


int main() {
    cout << "Testare metode de lucru cu fisiere text si binare:" << endl;

    // Testare metode fișiere text pentru Student
    Student s1("Maria Pop", 21, 30, "Informatica Aplicata");
    s1.scrieInFisierText("student.txt");
    cout << "Datele studentului scrise in fisier text.\n";
    s1.afisare();

    Student s2;
    s2.citesteDinFisierText("student.txt");
    cout << "Datele studentului citite din fisier text:" << endl;
    s2.afisare();

    Curs c1("Structuri de date", 40, "Licenta");
    c1.scrieInFisierBinar("curs.dat");
    cout << "Datele cursului scrise in fisier binar.\n";
    c1.afisare();

    // Citim un alt obiect din același fișier
    Curs curs2;
    curs2.citesteDinFisierBinar("cursuri.dat");
    cout << "Curs citit din fisier:" << endl;
    curs2.afisare();

    

    return 0;
}