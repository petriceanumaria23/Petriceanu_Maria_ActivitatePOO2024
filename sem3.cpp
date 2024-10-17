#include<iostream>
using namespace std;

class Magazin {
public:
	string oras;
	int nrAngajati;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;
	Magazin():anDeschidere(2024), nrAngajati(2) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		
	}
	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;

	}
	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "nr angajati:" << this->nrAngajati << endl;
		cout << "supraf:" << this->suprafata << endl;
		cout << "an des:" << this->anDeschidere << endl;
		cout << "impozit pe m2:" << Magazin::impozitM2 << endl;

	}

	float calculeazasuprafatamedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
		static void modificaImpozit(int impozit) {
			if (impozit > 0) {
				Magazin::impozitM2 = impozit;
			}
		}
	}
	static float calculeazasupraftotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;
	}

};
int Magazin::impozitM2 = 2;

int main() {
	Magazin m1;
	m1.afisare();
	Magazin::modificaImpozit(3);
	m1.modificaImpozit(4)

	Magazin m2("Iasi", 7, 200, 2019);
	m2.afisare();
	Magazin* pointer = new Magazin("Timisoara", 4, 120, 2022);
	pointer->afisare();
	// -> dereferentiere+accesare
	cout << "supraf medie per angajat:" << pointer->calculeazasuprafatamedie() << endl;
	int nrMagazine = 3;
	Magazin* vector = new Magazin[nrMagazine];
	// [] -deplasare+deferentiere
	for (int i = 0; i < nrMagazine; i++) {
		vector[i].afisare();
		//(vector +1)->afisare
		//(*(
		
	}
	cout << "suprafata tot:" << Magazin::calculeazasupraftotala(vector, nrMgazine) << endl;
	delete[]vector;
	delete pointer;
	return 8000;

}