#include <iostream>
#include <string>
#include <cstring>
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

    // Destructor
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



    bool operator==(const Profesor& p) {
        return (this->nume == p.nume && this->varsta == p.varsta && this->salariu == p.salariu);
    }

    Profesor& operator++() {
        this->salariu += 500;
        return *this;
    }

    Profesor operator+(const Profesor& p) {
        Profesor temp;
        temp.salariu = this->salariu + p.salariu;
        return temp;
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

    // Functie prietena
    friend void afiseazaSalariuProfesor(const Profesor& p);
};

double Profesor::salariuMaxim = 10000.0;

// Functie prietena
void afiseazaSalariuProfesor(const Profesor& p) {
    cout << "Salariul profesorului " << p.nume << " este: " << p.salariu << endl;
}

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


    Curs(string nume, int nrOre, string nivel)
        : nivel(nivel) {
        this->nume = nume;
        this->nrOre = nrOre;
        this->profesorTitular = new char[strlen("Popescu Ion") + 1];
        strcpy_s(this->profesorTitular, strlen("Popescu Ion") + 1, "Popescu Ion");
    }


    Curs(const Curs& c) : nivel(c.nivel) {
        this->nume = c.nume;
        this->nrOre = c.nrOre;
        this->profesorTitular = new char[strlen(c.profesorTitular) + 1];
        strcpy_s(this->profesorTitular, strlen(c.profesorTitular) + 1, c.profesorTitular);
    }


    Curs& operator=(const Curs& c) {
        if (this == &c) return *this;
        delete[] this->profesorTitular;
        this->nume = c.nume;
        this->nrOre = c.nrOre;
        if (c.profesorTitular != nullptr) {
            this->profesorTitular = new char[strlen(c.profesorTitular) + 1];
            strcpy_s(this->profesorTitular, strlen(c.profesorTitular) + 1, c.profesorTitular);
        }
        else {
            this->profesorTitular = nullptr;
        }

        return *this;
    }


    bool operator==(const Curs& c) {
        return (this->nume == c.nume && this->nrOre == c.nrOre);
    }


    Curs& operator++() {
        this->nrOre += 5;
        return *this;
    }


    Curs operator+(const Curs& c) {
        Curs temp;
        temp.nrOre = this->nrOre + c.nrOre;
        return temp;
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


    friend void afiseazaDurataCurs(const Curs& c);
};

int Curs::durataMaximaCurs = 60;


void afiseazaDurataCurs(const Curs& c) {
    cout << "Durata cursului " << c.nume << " este: " << c.nrOre << " ore." << endl;
}


class StudentMaster : public Student {
public:
    string specializare;
    double taxa;

    
    StudentMaster() : Student() {
        specializare = "Inteligenta Artificiala";
        taxa = 3000;
    }

   
    StudentMaster(string nume, int varsta, int nrCredite, string program, string specializare, double taxa)
        : Student(nume, varsta, nrCredite, program) {
        this->specializare = specializare;
        this->taxa = taxa;
    }

   
    void afiseazaTaxa() const {
        cout << "Studentul " << nume << " are taxa de " << taxa << " lei pentru specializarea " << specializare << "." << endl;
    }

   
    void afisare() {
        Student::afisare();
        cout << "Specializare: " << specializare << ", Taxa: " << taxa << endl;
    }
};

class ProfesorAsociat : public Profesor {
public:
    int nrOrePeSaptamana;
    string contractTip;

   
    ProfesorAsociat() : Profesor() {
        nrOrePeSaptamana = 10;
        contractTip = "Part-time";
    }

    
    ProfesorAsociat(string nume, int varsta, double salariu, string departament, int nrOre, string contractTip)
        : Profesor(nume, varsta, salariu, departament) {
        this->nrOrePeSaptamana = nrOre;
        this->contractTip = contractTip;
    }

    
    void afiseazaContract()  {
        cout << "Profesorul asociat " << nume << " are un contract " << contractTip
            << " și lucrează " << nrOrePeSaptamana << " ore pe săptămână." << endl;
    }

 
    void afisare() {
        Profesor::afisare();
        cout << "Numar ore pe saptamana: " << nrOrePeSaptamana
            << ", Tip contract: " << contractTip << endl;
    }
};

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

    cout << "\nTestare operatori:" << endl;
    s2 = s1;
    s2.afisare();
    if (s2 == s1) cout << "Studentii sunt egali." << endl;
    s2.afisare();
    Student s4 = s2 + s3;
    s4.afisare();

    p2 = p1;
    p2.afisare();
    if (p2 == p1) cout << "Profesorii sunt egali." << endl;
    p2.afisare();
    Profesor p4 = p2 + p3;
    p4.afisare();

    c2 = c1;
    c2.afisare();
    if (c2 == c1) cout << "Cursurile sunt egale." << endl;
    c2.afisare();
    Curs c4 = c2 + c3;
    c4.afisare();

    cout << "\nFunctii prietene:" << endl;
    afiseazaVarstaStudent(s1);
    afiseazaSalariuProfesor(p1);
    afiseazaDurataCurs(c1);


    cout << "\nTestare clase noi (StudentMaster și ProfesorAsociat):" << endl;

    // Testare StudentMaster
    StudentMaster sm1("Ioana Popa", 25, 45, "Informatica Aplicata", "AI", 4000.0);
    sm1.afisare();
    sm1.afiseazaTaxa();

    // Testare ProfesorAsociat
    ProfesorAsociat pa1("Diana Vasilescu", 35, 3500.0, "Informatica", 12, "Part-time");
    pa1.afisare();
    pa1.afiseazaContract();

    cout << "\nTestare upcasting:" << endl;

    // Upcasting pentru StudentMaster
    Student* studentPtr = &sm1;  
    studentPtr->afisare();       

    // Upcasting pentru ProfesorAsociat
    Profesor* profesorPtr = &pa1;  
    profesorPtr->afisare();        

    return 0;
}



