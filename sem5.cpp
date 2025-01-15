#include<iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;
	float* Salarii;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin() :anDeschidere(2024), nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->Salarii = NULL;

	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->Salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->Salarii[i] = 2000 + i;
		}

	}

	//constructor de copiere
	Magazin(const Magazin& m) :anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		this->Salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->Salarii[i] = m.Salarii[i];
		}
		this->suprafata = m.suprafata;
	}
	//
	~Magazin() {
		if (this->Salarii) {
			delete[]this->Salarii;
		}
	}

	Magazin operator=(const Magazin& m) {
		if (&m != this) { //verificare de autoasignare
			this->oras = m.oras;
			this->nrAngajati = m.nrAngajati;
			if (this->Salarii) {
				delete[]this->Salarii;
			}
			this->Salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				this->Salarii[i] = m.Salarii[i];
			}
			this->suprafata = m.suprafata;
		}
		return *this;
	}


	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->Salarii != NULL) {
				delete[]this->Salarii;
			}
			this->Salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->Salarii[i] = salarii[i];
			}
		}
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float suprafataNoua) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}

	float* getSalarii() {
		return this->Salarii;
	}
	float getSalarii(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->Salarii[index];
		}
	}


	Magazin operator+(Magazin m2)const {
		Magazin temp = *this;
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->Salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = m2.Salarii[i];
		}
		if (temp.Salarii != NULL) {
			delete[]temp.Salarii;
		}
		temp.Salarii = aux;
		return temp;
	}
	Magazin operator+=(Magazin m) {
		*this = *this + m;
		return *this;
	}
	Magazin operator+(float salariu)const {
		Magazin temp = *this;
		if (temp.Salarii != NULL) {
			delete[]temp.Salarii;
		}
		temp.Salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.Salarii[i] = this->Salarii[i];
		}
		temp.Salarii[temp.nrAngajati];
		temp.nrAngajati++;
		return temp;
	}
	friend Magazin operator+(float salariu, Magazin m) {
		Magazin temp = m;
		if (temp.Salarii != NULL) {
			delete[]temp.Salarii;
		}
		temp.Salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < m.nrAngajati; i++) {
			temp.Salarii[i] = m.Salarii[i];
		}
		temp.Salarii[temp.nrAngajati];
		temp.nrAngajati++;
		return temp;
	}
	friend Magazin operator+(float salariu, Magazin m);




	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe m2:" << Magazin::impozitM2 << endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {

			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
	}


	static void modificaImpozit(int impozit) {
		if (impozit > 0) {
			Magazin::impozitM2 = impozit;
		}
	}
	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;
	}



};

int Magazin::impozitM2 = 2;
Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

int main() {
	//Magazin m1;
	//cout << m1.getNrAngajati() << endl;
	//m1.setNrAngajati(6, new float[6] {2, 5, 4, 8, 6, 3});
	//cout << m1.getNrAngajati() << endl;

	//Magazin m2("Bucuresti", 3, 80, 2019);
	//cout << m2.getSalarii()[1] << endl;
	//cout << m2.getSalarii(1) << endl;

	//m2.setNrAngajati(5, new float[5] {5, 8, 3, 9, 4});
	//cout << m2.getSalarii(3) << endl;

	//Magazin m3(m2);
	//Magazin m4 = m2; //cele 2 sunt echivalente //constructor de copiere
	//Magazin m5;
	//m5 = m2;
	//m2 = m2;
	//f(m4);

	Magazin m1;
	Magazin m2("Bucuresti", 3, 80, 2019);

	int a = 9;
	int b = 6;
	int c = a + b; //c=15

	Magazin m3 = m1 + m2;
	Magazin m4 = m1.operator+(m2);
	Magazin m5 = m1 + 2000.0f;  //m1.operator+(2000.0f);
	Magazin m6 = 3000.0f + m1;
	m1 += m2;
	return 73747837;

}